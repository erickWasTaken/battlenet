#include "XML.hpp"
#include <iostream>
#include <ctype.h>
#include <algorithm>
#include <string>

using namespace std;

enum XMLTokenType{
    element,
    close,
    attributeName,
    attributeValue,
    text,
    none
};

struct XMLToken{
    XMLTokenType type;
    string text;
    size_t start;
    size_t end;
    size_t exit;
};

string XMLElement::GetAttribute(const string& name) const{
    return attributes.find(name) != attributes.end() ? attributes.at(name) : "";
}

void trim(string& data){
    // queries the first empty space from left-right
    auto start = find_if(data.begin(), data.end(), [](char c){return !isspace(c);}); // only satisfied when non-whitespace
    data.erase(data.begin(), start);

    // queries the first empty space from right-left
    auto end = find_if(data.rbegin(), data.rend(), [](char c){return !isspace(c);});
    data.erase(end.base(), data.end());
}

static string getTextTokenText(const string& data, const XMLToken& token){
    auto text = data.substr(token.start, token.end - token.start);
    trim(text);
    return text;
}

int skipToAfter(const string& data, size_t index, const string& marker){
    auto endIndex = data.find(marker, index);

    // if we have reached the end of the string
    if(endIndex == string::npos)
            return data.length();

    return endIndex + marker.length();
}

XMLToken nextToken(const string& data, XMLTokenType type, size_t start){
    XMLToken token{
        XMLTokenType::none,
    };

    auto index = start;
    auto len = data.length();
    char lastChar = '\0';
    bool inElement = type == XMLTokenType::element || type == XMLTokenType::attributeName || type == XMLTokenType::attributeValue;

    while(index < len){
        unsigned char currentChar = data[index];

        switch(currentChar){
            case '<':
                // was in text-body, found another tag
                if(token.type == XMLTokenType::text){
                    token.end = index;
                    token.text = getTextTokenText(data, token);
                    token.exit = index;
                    return token;
                }
                break;

            // comment skip ???
            case '?':
                if(lastChar != '<')
                    break;
                
                // incremented later, so subtract 1
                index = skipToAfter(data, index, ">") -1;
                currentChar = '\0';
                break;

            // comment skip
            case '!':
                if(lastChar != '<')
                    break;
                
                index = skipToAfter(data, index, "-->") -1;
                currentChar = '\0';
                break;

            // end of block
            case '/': {
                if(token.type == XMLTokenType::element){
                    token.end = index;
                    token.text = data.substr(token.start, token.end - token.start);
                    token.exit = index;
                    return token;
                } 

                if(lastChar != '<')
                    break;

                token.type = XMLTokenType::close;
                token.start = index + 1;
                token.end = skipToAfter(data, index, ">") -1;
                token.text = data.substr(token.start, token.end - token.start);
                trim(token.text);

                token.exit = token.end + 1;
                return token;
            }

            case '>':
                if(lastChar == '/'){
                    token.type = XMLTokenType::close;
                    token.start = index - 1;
                    token.end = index;
                    token.exit = index + 1;
                    return token;
                }

                if(token.type == XMLTokenType::element){
                    token.end = index;
                    token.text = data.substr(token.start, token.end - token.start);
                    token.exit = index;
                    return token;
                }

                inElement = false;
                token.start = index + 1;
                token.type = XMLTokenType::text;
                break;

            case '"':
                // just part of the text, skip
                if(!inElement)
                    break;

                if(token.type == XMLTokenType::attributeValue){
                    token.end = index;
                    token.text = data.substr(token.start + 1, token.end - token.start - 1);
                    token.exit = index + 1;
                    return token;
                }

                // ???
                token.type = XMLTokenType::attributeValue;
                token.start = index;
                break;

            default:
                if(isalpha(currentChar)){
                    if(lastChar == '<'){
                        token.start = index;
                        token.type = XMLTokenType::element;
                    }else if(token.type == XMLTokenType::none && inElement){
                        token.start = index;
                        token.type = XMLTokenType::attributeName;
                    }
                }else if(token.type == XMLTokenType::element || token.type == XMLTokenType::attributeName){
                    token.end = index;
                    token.text = data.substr(token.start, token.end - token.start);
                    token.exit = index + 1;
                    return token;
                } 

                break;
        }

        lastChar = currentChar;
        index++;
    }

    token.end = index;
    token.exit = index;

    return token;
}

XMLElement parseXML(const string& data){
    size_t index = 0;

    XMLToken token = nextToken(data, XMLTokenType::none, index);
    index = token.exit;

    XMLElement rootElement = {
        token.text, // name
    };

    if(token.type != XMLTokenType::element){
        return rootElement;
    }

    vector<XMLElement*> elements;
    elements.push_back(&rootElement);

    XMLElement* currentElement = &rootElement;
    string attributeName;

    // build children vector
    do{
        token = nextToken(data, token.type, index);
        index = token.exit;

        switch(token.type){
            case XMLTokenType::element: {
                XMLElement child = {
                    token.text,
                };
                
                currentElement->children.push_back(child);

                auto& children = currentElement->children;
                currentElement = &children[children.size() -1];
                elements.push_back(currentElement);
                break;
            }

            case XMLTokenType::close: 
            if(currentElement->children.size() > 0){
                currentElement->text = "";
            }

            elements.pop_back(); 

            if(elements.size() == 0){
                return rootElement;
            }

            currentElement = elements[elements.size() -1];
            break;
            
            case XMLTokenType::attributeName:
                attributeName = token.text;
                break;

            case XMLTokenType::attributeValue:
                currentElement->attributes.emplace(attributeName, token.text);
                break;

            case XMLTokenType::text:
                currentElement->text = token.text;
                break;

            case XMLTokenType::none:
                return rootElement;
        }

    }while(token.type != XMLTokenType::none);

    return rootElement;
}
