#include <GL/glut.h>

float angulo = 0.0;

void girar(){
    angulo += 1;
    if(angulo >= 360.0){
        angulo = 0.0;
    }
    glutPostRedisplay();
    glutTimerFunc(20, girar, 0);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //câmera
    gluLookAt(5.0, 5.0, 5.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
    glColor3f(1.0f, 0.0f, 0.0f);

    //luzes
    GLfloat posLuzLocal[4] = {10.0, 8.0, 11.0, 1.0};
    GLfloat branco[4] = {1.0, 1.0, 1.0, 1.0};
    GLfloat preto[4] = {0.0, 0.0, 0.0, 1.0};
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT0, GL_POSITION, posLuzLocal);
    glLightfv(GL_LIGHT0, GL_AMBIENT, preto);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, branco);
    glLightfv(GL_LIGHT0, GL_SPECULAR, branco);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.5);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.15);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.1);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    GLfloat posLuzDistante[4] = {0.0, 0.0, 0.0, 0.0};
    glLightfv(GL_LIGHT1, GL_POSITION, posLuzDistante);

    //paredes e chão
    float paredesDiffuse[4] = {1.0, 0.0, 0.0, 1.0};
    float paredesSpecular[4] = {0.2, 0.2, 0.2, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, paredesDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, paredesSpecular);
    glMaterialf(GL_FRONT,GL_SHININESS, 1.0);

    glPushMatrix();
        glScalef(2.0, 0.05, 1.5);
        glTranslatef(0.0, -15.0, 0.0);
        glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
        glScalef(2.0, 1.5, 0.05);
        glTranslatef(0.0, 0.0, -15.0);
        glutSolidCube(1.0);
    glPopMatrix();
    glPushMatrix();
        glScalef(0.05, 1.5, 1.5);
        glTranslatef(-20.0, 0.0, 0.0);
        glutSolidCube(1.0);
    glPopMatrix();

    //esfera
    float esferaDiffuse[4] = {0.0, 1.0, 0.0, 1.0};
    float esferaSpecular[4] = {0.2, 0.2, 0.2, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, esferaDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, esferaSpecular);
    glMaterialf(GL_FRONT,GL_SHININESS, 2.0);
    glPushMatrix();
        glScalef(0.2, 0.2, 0.2);
        glTranslatef(-2.5, -3.0, 2.0);
        glRotatef(angulo, 0.0, 1.0, 0.0);
        glutSolidSphere(1.0, 30.0, 30.0);     
    glPopMatrix();

    //toro
    float toroDiffuse[4] = {0.0, 0.0, 1.0, 1.0};
    float toroSpecular[4] = {0.2, 0.2, 0.2, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, toroDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, toroSpecular);
    glMaterialf(GL_FRONT,GL_SHININESS, 2.0);
    glPushMatrix();
        glScalef(0.1, 0.1, 0.1);
        glTranslatef(0.0, -6.5, 0.0);
        glRotatef(angulo, 0.0, 1.0, 0.0);
        glRotatef(90.0, 1.0, 0.0, 0.0);
        glutSolidTorus(1.0, 2.0, 30.0, 30.0);     
    glPopMatrix();

    //bule
    float buleDiffuse[4] = {0.0, 1.0, 1.0, 1.0};
    float buleSpecular[4] = {0.2, 0.2, 0.2, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, buleDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, buleSpecular);
    glMaterialf(GL_FRONT,GL_SHININESS, 100.0);
    glPushMatrix();
        glScalef(0.1, 0.1, 0.1);
        glTranslatef(8.0, -4, 6.0);
        glRotatef(angulo, 0.0, 1.0, 0.0);
        glutSolidTeapot(2.0);     
    glPopMatrix();
	glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Cena Objetos");
	glClearColor(0.8, 0.8, 0.8, 0.0);
    glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(30.0, 1.0, 0.1, 100.0);
	glutDisplayFunc(display);
    glutTimerFunc(20, girar, 0);
	glutMainLoop();
	return 0;
}