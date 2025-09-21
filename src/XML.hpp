#pragma once

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct XMLElement{
    string name;
    unordered_map<string, string> attributes;
    vector<XMLElement> children;
    string text;

    bool HasAttribute(const string& name) const;
    string GetAttribute(const string& name) const;
    int getAttributeInt(const string& name) const;
    float GetAttributeFloat(const string& name) const;
};

XMLElement parseXML(const string& data);
