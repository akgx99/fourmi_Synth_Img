#include "utils.h"

using namespace fourmiProjet;

char presse;
int anglex, angley, x, y, xold, yold;

void utils::init(int argc, char **argv)
{
    //Initialisation de la fenêtre et création de la fenêtre
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(200,200);
    glutInitWindowSize(500,500);
    glutCreateWindow("fourmi");

    //Initialisation d'OpenGL
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,1.0,1.0);
    glPointSize(2.0);
    glEnable(GL_DEPTH_TEST);

    //Enregistrement des fonctions de rappel
    glutDisplayFunc(affichage);
    glutKeyboardFunc(clavier);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(mousemotion);

    //Entrée dans la boucle principale de glut
    glutMainLoop();

}

void utils::affichage()
{

    /* effacement de l'image avec la couleur de fond */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);

    glLoadIdentity();
    glRotatef(angley,1.0,0.0,0.0);
    glRotatef(anglex,0.0,1.0,0.0);

    draw::corps();
    draw::antenne();
    draw::pates();

    glFlush();

    //On echange les buffers
    glutSwapBuffers();
}

void utils::clavier(unsigned char touche, int x, int y)
{
    switch(touche)
    {
        case 'p': /* affichage du carre plein */
          glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
          glutPostRedisplay();
          break;
        case 'f': /* affichage en mode fil de fer */
          glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
          glutPostRedisplay();
          break;
        case 's' : /* Affichage en mode sommets seuls */
          glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
          glutPostRedisplay();
          break;
        case 'd':
          glEnable(GL_DEPTH_TEST);
          glutPostRedisplay();
          break;
        case 'D':
          glDisable(GL_DEPTH_TEST);
          glutPostRedisplay();
          break;
        case 'q' : /*la touche 'q' permet de quitter le programme */
          exit(0);
    }

}

void utils::reshape(int x,int y)
{
    if (x<y)
    glViewport(0,(y-x)/2,x,x);
    else
    glViewport((x-y)/2,0,y,y);
}

void utils::mouse(int button, int state,int x,int y)
{
  /* si on appuie sur le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    presse = 1; /* le booleen presse passe a 1 (vrai) */
    xold = x; /* on sauvegarde la position de la souris */
    yold=  y;
  }
  /* si on relache le bouton gauche */
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
    presse=0; /* le booleen presse passe a 0 (faux) */
}


void utils::mousemotion(int x,int y)
{
    if (presse) /* si le bouton gauche est presse */
    {
      /* on modifie les angles de rotation de l'objet
     en fonction de la position actuelle de la souris et de la derniere
     position sauvegardee */
      anglex=anglex+(x-xold);
      angley=angley+(y-yold);
      glutPostRedisplay(); /* on demande un rafraichissement de l'affichage */
    }

    xold=x; /* sauvegarde des valeurs courante de le position de la souris */
    yold=y;
}
