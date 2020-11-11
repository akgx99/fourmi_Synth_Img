/* représente l'ensemble des "outils" nécessaires au projet */

#ifndef UTILS_H
#define UTILS_H

#include<draw.h>

namespace fourmiProjet
{
    class utils
    {
        public:
            void init(int argc, char **argv);
            void static affichage();

        private:
            void static clavier(unsigned char touche, int x, int y);
            void static reshape(int x, int y);
            void static mouse(int bouton, int etat, int x, int y);
            void static mousemotion(int x, int y);
            void idle();
    };

    class Point
    {
        public:
            //coordonnnées x, y et z du point
            double x;
            double y;
            double z;

            //couleur RGB du point
            float r;
            float g;
            float b;

    };
}

#endif // UTILS_H
