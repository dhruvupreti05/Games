#ifndef SHADER_CLASS
#define SHADER_CLASS

#include <glad/glad.h>
#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <string>
#include <cerrno>

std::string get_file_contents(const char* filename);

class Shader
{
    public:
        GLuint ID;
        Shader(const char* vertexFile, const char* fragmentFile);

        void Activate();
        void Delete();
};

#endif