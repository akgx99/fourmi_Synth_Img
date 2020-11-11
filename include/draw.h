#ifndef DRAW_H
#define DRAW_H

//inclusion fichiers en-tête freeglut
#ifdef __APPLE__
    #include<GLUT/glut.h>
#else

    #include<GL/glut.h>
#endif // __APPLE__
#include <GL/freeglut.h>
#include <cstdlib>
#include <math.h>       /* pour cos, sin */
#define pi 3.14159265

namespace fourmiProjet
{
    class draw
    {
        public:
            void static corps();
            void static antenne();
            void static pates();

        private:
            void static regtangle(GLfloat x, GLfloat y, GLfloat z);
            void static sphere(GLdouble r, GLint sl, GLint st);
    };
}

#endif // DRAW_H
