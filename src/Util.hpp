#pragma once

#include <sstream>
#include <string.h>
#include <iostream>
#include <math.h>

#define UNIMPLEMENTED cout << "::UNIMPMENETED::\n" << "::" << __func__ << "::\n::" << __FILE__ <<  "::\n" <<"::" <<  __LINE__ <<  "::" << endl;  
#define ERROR(msg) cout << "::ERROR::\n::" << msg << "::" << endl;

using namespace std;
// using namespace sf;

namespace FileUtil{

    class FileStream{
    private:
        FILE* file;
        bool valid;

    public:
        FileStream(string& path){
            file = fopen(path.c_str(), "w");
            valid = !file ? false : true;
        }

        ~FileStream(){ fclose(file); }
    };


    static string Read(const string& path){
        auto *in = fopen(path.c_str(), "r");
        if(!in)
            return "";

    fseek(in, 0, SEEK_END);
    int size = ftell(in);
    fseek(in, 0, SEEK_SET);

    char* buff = (char*)malloc(sizeof(char) * size + 1);
    memset(buff, 0, sizeof(*buff));
    fread(buff, sizeof(char), size, in);

    fclose(in);
    return (const string)buff;
}
};

namespace StringUtil{
    static int to_int(const string& s){
        auto c = (s[s.length() -1] - '0');
        if(c < 0 || c > 9){
            ERROR("string begins with non-numerical characters");
            return -1;
        }

        int res = 0;
        for(int i = s.length() -1; i >= 0; i--){
            c = s[i] - '0';
            if(c < 0 || c > 9)
                continue;

            res += c * pow(10, s.length() - 1 - i);
        }
        return res;
    }
};
