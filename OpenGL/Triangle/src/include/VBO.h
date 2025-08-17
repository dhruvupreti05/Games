#ifndef VBO_CLASS
#define VBO_CLASS

#include <glad/glad.h>

    class VBO
    {
        public:
            GLuint ID;
            VBO(GLfloat* vertices, GLsizeiptr size);
            
            void Bind();
            void Delete();
            void Unbind();
    };

#endif