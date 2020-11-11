//inclusion des fichiers sources propres au projet
#include<utils.h>

using namespace fourmiProjet;

int main(int argc,char **argv)
{
    utils u;
    u.init(argc, argv);
    u.affichage();

    return 0;
}
