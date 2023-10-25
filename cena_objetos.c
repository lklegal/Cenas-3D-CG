#include <GL/glut.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5.0, 5.0, 5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);

    GLfloat posLuzLocal[4] = {-8.0, -8.0, -8.0, 1.0};
    GLfloat branco[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat preto[4] = {0.0, 0.0, 0.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, posLuzLocal);
    glLightfv(GL_LIGHT0, GL_AMBIENT, preto);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, branco);
    glLightfv(GL_LIGHT0, GL_SPECULAR, branco);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.15);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.1);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    GLfloat posLuzDistante[4] = {0.0, 0.0, 0.0, 0.0};
    glLightfv(GL_LIGHT1, GL_POSITION, posLuzDistante);
    glEnable(GL_LIGHT1);

    float paredesDiffuse[4] = {1.0, 0.0, 0.0, 1.0};
    float paredesSpecular[4] = {0.2, 0.2, 0.2, 1.0};
    //const GLfloat briho = 30.0f;
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, paredesDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, paredesSpecular);
    glMaterialf(GL_FRONT,GL_SHININESS, 1.0);

    glPushMatrix();
        //glLoadIdentity();
        glScalef(2.0, 0.05, 1.5);
        glTranslatef(0.0, -15.0, 0.0);
        glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
        //glLoadIdentity();
        glScalef(2.0, 1.5, 0.05);
        glTranslatef(0.0, 0.0, -15.0);
        glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
        //glLoadIdentity();
        glScalef(0.05, 1.5, 1.5);
        glTranslatef(-20.0, 0.0, 0.0);
        glutSolidCube(1.0);
    glPopMatrix();
	glutSwapBuffers();
}

int init(){
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Cena Objetos");
	glClearColor(0.8, 0.8, 0.8, 0.0);
    glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(30.0, 1.0, -8.0, 3.0);
    //glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 8.0);
	glutDisplayFunc(display);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	init();
    //criarMenu();
	glutMainLoop();
	return 0;
}