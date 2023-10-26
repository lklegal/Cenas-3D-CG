#include <GL/glut.h>

float angulo = 0.0;

void renderizaBule(){
    //luzes
    GLfloat posLuzLocal[4] = {3.0, 3.0, 3.0, 1.0};
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

    //bule
    float buleDiffuse[4] = {0.0, 1.0, 1.0, 1.0};
    float buleSpecular[4] = {0.5, 0.5, 0.5, 1.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, buleDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, buleSpecular);
    glMaterialf(GL_FRONT,GL_SHININESS, 100.0);
    glPushMatrix();
        glRotatef(angulo, 0.0, 1.0, 0.0);
        glutSolidTeapot(1.0);     
    glPopMatrix();
}

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

    //visão XY
    glPushMatrix();
    glViewport(0, 400, 400, 400);
        gluLookAt(0.0, 0.0, 7.0,
                0.0, 0.0, 0.0,
                0.0, 1.0, 0.0);
    renderizaBule();
    glPopMatrix();

    //visão YZ
    glPushMatrix();
    glViewport(400, 400, 400, 400);
        gluLookAt(7.0, 0.0, 0.0,
                0.0, 0.0, 0.0,
                0.0, 1.0, 0.0);
    renderizaBule();
    glPopMatrix();

    //visão XZ
    glPushMatrix();
    glViewport(0, 0, 400, 400);
        gluLookAt(0.0, 7.0, 0.0,
                0.0, 0.0, 0.0,
                0.0, 0.0, -1.0);
    renderizaBule();
    glPopMatrix();

    //visão perspectiva
    glPushMatrix();
    glViewport(400, 0, 400, 400);
        gluLookAt(4.0, 4.0, 4.0,
                0.0, 0.0, 0.0,
                0.0, 1.0, 0.0);
    renderizaBule();
    glPopMatrix();

	glutSwapBuffers();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Cena bule");
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