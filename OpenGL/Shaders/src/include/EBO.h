#ifndef EBO_CLASS
#define EBO_CLASS

#include <glad/glad.h>

class EBO
{
    public:
        GLuint ID;
        EBO(GLuint* indices, GLsizeiptr size);
        
        void Bind();
        void Delete();
        void Unbind();
};

#endif