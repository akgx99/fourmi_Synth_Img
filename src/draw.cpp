#include "draw.h"

using namespace fourmiProjet;

int step = 10;
float cosinus = cos(step);
float sinus = sin(step);

void draw::corps()
{
    glPushMatrix();
    glColor3f(0.1,0.1,0.1); //définit la couleur du corps de la fourmi
    glScalef(1, 1.3, 1);
    sphere(0.18,34, 34);
    glTranslatef(0.00, 0.30, 0.00);

    sphere(0.20,34, 34);
    glTranslatef(-0.05, 0.17, 0.05);
    glRotatef(-90, 1, 0, 0);
    glRotatef(-25, 0, 1, 0);
    glTranslatef(0.00, 0.10, 0.00);
    glRotatef(25, 0, 1, 0);

    glRotatef(90, 1, 0, 0);
    glScalef(1, 1.3, 1);
    glTranslatef(0.15, -0.65, 0.05);
    sphere(0.25,34, 34);
    glScalef(1, 1 / 1.3, 1);

    glPopMatrix();

    glColor3f(1,1,1); //définit la couleur des pattes et des antennes

}

void draw::antenne()
{
    glBegin(GL_LINES);
    glVertex3f(0.00, 0.30, 0.00);
    glVertex3f(0.40, 0.70, 0.40);
    glVertex3f(0.00, 0.30, 0.00);
    glVertex3f(0.40, 0.70, -0.40);
    glEnd();
}

void draw::pattes(int angley)
{
    //pate gauche arrière
    glBegin(GL_LINE_STRIP);
    glVertex3f(0.00, 0.05, 0.18);
    glVertex3f(0.35 + 0.05 * cosinus, 0.15, 0.25);
    glVertex3f(-0.20 + 0.05 * cosinus, 0.25 + 0.1 * sinus, 0.45);
    glEnd();

    //pate gauche milieu
    glBegin(GL_LINE_STRIP);
    glVertex3f(0.00, 0.00, 0.18);
    glVertex3f(0.35 + 0.05 * cosinus, 0.00, 0.25);
    glVertex3f(-0.20 + 0.05 * cosinus, 0.00 + 0.1 * sinus, 0.45);
    glEnd();

    //pate gauche avant
    glBegin(GL_LINE_STRIP);
    glVertex3f(0.00, -0.05, 0.18);
    glVertex3f(0.35 + 0.05 * cosinus, -0.15, 0.25);
    glVertex3f(-0.20 + 0.05 * cosinus, -0.25 + 0.1 * sinus, 0.45);
    glEnd();

    //pate droite avant
    glBegin(GL_LINE_STRIP);
    glVertex3f(0.00, 0.05, -0.18);
    glVertex3f(0.35 - 0.05 * sinus, 0.15, -0.25);
    glVertex3f(-0.20 - 0.05 * sinus, 0.25 + 0.1 * cosinus, -0.45);
    glEnd();

    //pate droite milieu
    glBegin(GL_LINE_STRIP);
    glVertex3f(0.00, 0.00, -0.18);
    glVertex3f(0.35 - 0.05 * sinus, 0.00, -0.25);
    glVertex3f(-0.20 - 0.05 * sinus, 0.00 + 0.1 * cosinus, -0.45);
    glEnd();

    //pate droite arrière
    glBegin(GL_LINE_STRIP);
    glVertex3f(0.00, -0.05, -0.18);
    glVertex3f(0.35 - 0.05 * sinus, -0.15, -0.25);
    glVertex3f(-0.20 - 0.05 * sinus, -0.25 + 0.1 * cosinus, -0.45);
    glEnd();
}

void draw::regtangle(GLfloat x, GLfloat y, GLfloat z)
{
    glScalef(x,y,z);
    glutSolidCube(1.0);
}

void draw::sphere(GLdouble r, GLint sl, GLint st)
{
    glutSolidSphere(r, sl, st);
}
