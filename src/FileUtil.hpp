#pragma once

#include <sstream>
#include <string.h>

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


    string Read(string& path){
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
        return (string)buff;
    }
};
