

#include <iostream>
#include <GL/freeglut.h>


int rot_Z = 0;
int rot_Y = 0;
int rot_X = 0;
int x = 100;
int y = 0;
int z = -70;

float startx = 0;
float starty = 0;
float endx = 0;
float endy = 0;


float x_r = 0.9;
float y_r = 0;
float z_r = -1;
float angle_r = 0;

float x_g = 0;
float y_g = 0;
float z_g = -0.9;
float angle_g = 0;

float x_b = 0;
float y_b = 0;
float z_b = -0.9;
float angle_b = 0;

float x_w = 0;
float y_w = 0;
float z_w = -1;


float spotAngle = 10.0;
float spotExponent = 2.0;
float spotDirection[] = { 0.0, -1.0, 0.0 };
float lightPos[] = { 0.0, 3.0, 0.0, 0.0 };
GLfloat light_position[] = { 4.0, 4.0, 4.0, 4.0 }; //swiatlo kierunkowe

bool On_0 = 1;
bool On_1 = 1;
bool On_2 = 1;
bool On_3 = 1;
bool On_4 = 1;


void swiatloPunktowe(float x,float y, float z, int col)
{
    
    glMatrixMode(GL_MODELVIEW);
    
    glLoadIdentity();

    if (col == 0)
    {
        GLfloat color[] = { 1,1,1,1 };
        //glLightfv(GL_LIGHT1, GL_AMBIENT, color);
        GLfloat lightPos[] = { x, y, z, 1.0 };

        glLightfv(GL_LIGHT4, GL_POSITION, lightPos);

        GLfloat diffuse[] = { 0.8,0.8,0.8,1 };

        glLightfv(GL_LIGHT4, GL_DIFFUSE, diffuse);

        glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 1.2);
        glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 0);
        glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 0);



        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
        GLfloat materialSpecular[] = { 1.0f, 1.0f, 1.0f, 0.0f };
        //glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
        GLfloat materialEmission[] = { 1.0f, 1.0f, 1.0f, 1.0f };
        //glMaterialfv(GL_FRONT, GL_EMISSION, color);
        //glColor3f(0.8, 0.2, 0.1);              // Red ball displaced to left.
        glPushMatrix();
        glTranslatef(x, y, z);
        //glRotatef(60.0, 1, 0, 0);
        glutSolidSphere(0.03, 20, 50);
        glPopMatrix();
    }


    if (col == 1)
    {
        GLfloat color[] = { 1,0,0,1 };
        //glLightfv(GL_LIGHT1, GL_AMBIENT, color);
        GLfloat lightPos[] = { x, y, z, 1.0 };

        glLightfv(GL_LIGHT1, GL_POSITION, lightPos);

        GLfloat diffuse[] = { 0.5,0,0,0 };

        glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse);

        glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.2);
        glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0);
        glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0);



        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
        GLfloat materialSpecular[] = { 1.0f, 1.0f, 1.0f, 0.0f };
        //glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
        GLfloat materialEmission[] = { .5f, 0.0f, .0f, 1.0f };
        //glMaterialfv(GL_FRONT, GL_EMISSION, color);
        //glColor3f(0.8, 0.2, 0.1);              // Red ball displaced to left.
        glPushMatrix();
        glTranslatef(x, y, z);
        //glRotatef(60.0, 1, 0, 0);
        glutSolidSphere(0.03, 20, 50);
        glPopMatrix();
    }




    if (col == 2) 
    {
        GLfloat color[] = { 0,1,0,1 };
        //glLightfv(GL_LIGHT1, GL_AMBIENT, color);
        GLfloat lightPos[] = { x, y, z, 1.0 };

        glLightfv(GL_LIGHT2, GL_POSITION, lightPos);

        GLfloat diffuse[] = { 0,0.5,0,0 };

        glLightfv(GL_LIGHT2, GL_DIFFUSE, diffuse);

        glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.2);
        glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0);
        glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0);


        
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
        GLfloat materialSpecular[] = { 1.0f, 1.0f, 1.0f, 0.0f };
        //glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
        GLfloat materialEmission[] = { .0f, 0.5f, .0f, 1.0f };
        //glMaterialfv(GL_FRONT, GL_EMISSION, color);
        //glColor3f(0.8, 0.2, 0.1);              // Red ball displaced to left.
        glPushMatrix();
        glTranslatef(x, y, z);
        //glRotatef(60.0, 1, 0, 0);
        glutSolidSphere(0.03, 20, 50);
        glPopMatrix();
    }
    if (col == 3)
    {
        GLfloat color[] = { 0,0.3,1,1 };
        //glLightfv(GL_LIGHT1, GL_AMBIENT, color);
        GLfloat lightPos[] = { x, y, z, 1.0 };

        glLightfv(GL_LIGHT3, GL_POSITION, lightPos);

        GLfloat diffuse[] = { 0,0,0.5,0 };

        glLightfv(GL_LIGHT3, GL_DIFFUSE, diffuse);

        glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.2);
        glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0);
        glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0);



        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
        GLfloat materialSpecular[] = { 1.0f, 1.0f, 1.0f, 0.0f };
        //glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
        GLfloat materialEmission[] = { .0f,  .0f, 0.5f, 1.0f };
        //glMaterialfv(GL_FRONT, GL_EMISSION, color);
        //glColor3f(0.8, 0.2, 0.1);              // Red ball displaced to left.
        glPushMatrix();
        glTranslatef(x, y, z);
        //glRotatef(60.0, 1, 0, 0);
        glutSolidSphere(0.03, 20, 50);
        glPopMatrix();
    }


    //glutSwapBuffers();
}



void display() {
    //swiatloPunktowe(0.5f, 0.5f, 0, 1);
    
}

void funkcjaRenderujaca()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  
    glEnable(GL_LIGHTING);


    if (On_0) {
        glEnable(GL_LIGHT0);
        //swiatlo z nieskonczonosci
        GLfloat lightPos0[] = { x, y, z, 0.0 };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
        GLfloat diffuse[] = { 0.7,0.7,0.7,0 };
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    }
    else {
        glDisable(GL_LIGHT0);
    }

    if (On_4) {
        //white
        swiatloPunktowe(x_w, y_w, z_w, 0);
        glEnable(GL_LIGHT4);
    }
    else {
        glDisable(GL_LIGHT4);
    }


    if (On_1) {
        x_r = 0.8f * cosf(angle_r);
        z_r = 0.8f * sinf(angle_r);
        if (angle_r == 360)
        {
            angle_r = 0;

        }
        else {
            angle_r += -0.01;
        }

        // red
        swiatloPunktowe(x_r, y_r, z_r, 1);
        glEnable(GL_LIGHT1);
    }
    else {
        glDisable(GL_LIGHT1);
    }
    

    if (On_2) {
        x_g = 0.9f * cosf(angle_g);
        y_g = 0.9f * sinf(angle_g);
        if (angle_g == 360)
        {
            angle_g = 0;

        }
        else {
            angle_g += 0.03;
        }

        // green
        swiatloPunktowe(x_g, y_g, z_g, 2);
        glEnable(GL_LIGHT2);
    }
    else {
        glDisable(GL_LIGHT2);
    }

    if (On_3) {
        y_b = 0.95f * cosf(angle_b);
        z_b = 0.95f * sinf(angle_b);
        if (angle_b == 360)
        {
            angle_b = 0;

        }
        else {
            angle_b += 0.02;
        }
        // blue
        swiatloPunktowe(x_b, y_b, z_b, 3);
        glEnable(GL_LIGHT3);
    }
    else {
        glDisable(GL_LIGHT3);
    }



    
    glutPostRedisplay();





    glEnable(GL_COLOR_MATERIAL);
    //ambient

    
    
    glRotatef(rot_Z, 0, 0, 1);
    glRotatef(rot_Y, 0, 1, 0);
    glRotatef(rot_X, 1, 0, 0);
    //niesk

    //plamka
     /*
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, spotAngle);
    glTranslatef(0.1f, 0.1f, 0.1f);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDirection);//poddaja się przeksztalcenia jak glTranslate
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, spotExponent);*/

    glEnd();


    glDisable(GL_COLOR_MATERIAL);

    GLfloat material[] = { 1,1,0.7, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, material);
    glBegin(GL_QUADS);
    //Floor /
    glVertex3f(-1.5, 3, 2);
    glVertex3f(1.5, -3, 2);
    glVertex3f(0, -3, -0.7f);
    glVertex3f(-3, 3, -0.7f);
    
    glEnd();
    
    GLfloat materialColor[] = { 0.8f, 0.45f, 0.8f, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialColor);
    GLfloat materialSpecular[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular);
    GLfloat materialEmission[] = { .0f, .0f, .0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_EMISSION, materialEmission);
    glMaterialf(GL_FRONT, GL_SHININESS, 100);
    
    glutSolidTorus(0.2, 0.5, 25, 25);
    glTranslatef(0, 0, -0.5f);

    GLfloat materialAmbient2[] = { 0.2f, 0.3f, 0.7f, 1.0f };
    GLfloat materialDiffuse2[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat materialSpecular2[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat materialEmission2[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_AMBIENT, materialAmbient2);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, materialDiffuse2);
    glMaterialfv(GL_FRONT, GL_SPECULAR, materialSpecular2);
    glMaterialfv(GL_FRONT, GL_EMISSION, materialEmission2);
    glMaterialf(GL_FRONT, GL_SHININESS, 50);

    glutSolidTeapot(0.3f);
    glTranslatef(0, 0, 0.5f);
    


    //aktualizacja ekranu poprzez zamiane bufforów
    glutSwapBuffers();
}

void funkcjaKlawiatury(unsigned char key, int x, int y)
{
    //printf("Key %c, pos(X: %d, Y: %d)\n", key, x, y);//uwaga tylko gdy mamy konsole !
    switch (key) {
    case'0':
        On_0 = !On_0;
        printf("swiatlo z nieskonczonosci: %s\n", On_0 ? "on" : "off");
        break;

    case '1':
        On_1 = !On_1;
        printf("swiatlo czerwone: %s\n", On_1 ? "on" : "off");
        break;

    case '2':
        On_2 = !On_2;
        printf("swiatlo zielone: %s\n", On_2 ? "on" : "off");
        break;

    case '3':
        On_3 = !On_3;
        printf("swiatlo niebiskie: %s\n", On_3 ? "on" : "off");
        break;

    case '4':
        On_4 = !On_4;
        printf("swiatlo biale: %s\n", On_4 ? "on" : "off");
        break;

    case 'w': // up
        y_w+=0.015;
        if (y_w < -1) {
            y_w = -1;
        }
        break;


    case 's': // down
        y_w-=0.015;
        if (y_w > 1) {
            y_w = 1;
        }
        break;

    case 'a': // left
        x_w -= 0.015;
        if (x_w > 1) {
            x_w > 1;
        }

        break;

    case 'd': // right
        x_w += 0.015;
        if (x_w < -1) {
            x_w = -1;
        }
        break;

    case 'f': // left
        z_w -= 0.02;
        if (z_w > 1.2) {
            z_w > 1.2;
        }

        break;

    case 'c': // right
        z_w += 0.02;
        if (z_w < -1.2) {
            z_w = -1.2;
        }
        break;

    case 27: // ESCAPE key
        exit(0);
        break;
    case 'y':
        //wcisnieto klawisz y
        rot_Y++; //zwieksz kat obrotu
        if (rot_Y > 360)
        {
            rot_Y = 0;
        }
        glutPostRedisplay();//wymuszenie przerysowania sceny
        break;

    case 'x':
        //wcisnieto klawisz x
        rot_X++; //zwieksz kat obrotu
        if (rot_X > 360)
        {
            rot_X = 0;
        }
        glutPostRedisplay();//wymuszenie przerysowania sceny
        break;
    case 'z':
        //wcisnieto klawisz e
        rot_Z++;//zwieksz kat obrotu
        if (rot_Z > 360)
        {
            rot_Z = 0;
        }
        glutPostRedisplay();//wymuszenie przerysowania sceny
        break;
    }
}


void fM1(int x, int y)
{
    //printf("M1 pos(X: %d, Y: %d)\n", x, y);

}
void fM2(int x, int y)
{
    //printf("M2 pos(X: %d, Y: %d)\n", x, y);
}
void fM3(int button, int state,
    int x, int y)
{
    if (state == 0)
    {
        startx = (float)x / 5;
        starty = (float)y / 3;
    }
    if (state == 1)
    {
        endx = (float)x / 5;
        endy = (float)y / 3;


        glRotatef(endx - startx, 0, -1.0, 0);
        glRotatef(endy - starty, -1.0, 0, 0);

        printf("M3, angle(X:%f, Y:%f\n", (endx - startx), (starty - endy));
    }
}
int main(int argc, char* args[])
{
    glutInit(&argc, args);


    //Tworzymy kontekst OpenGL 2.1
    glutInitContextVersion(2, 1);
    //Podwójne buforowanie
    glutInitDisplayMode(GLUT_DOUBLE);
    //Inicjujemy okienko, w którym będzie wyświetlana scena (rozmiar 300x300)
    glutInitWindowSize(300, 300);

    //i tworzymy je z nagłówkiem w pasku tytułu
    glutCreateWindow("OpenGL");
    glutMotionFunc(fM1);
    glutPassiveMotionFunc(fM2);
    glutMouseFunc(fM3);

    
    


    glEnable(GL_DEPTH_TEST);

    //... kod w main po stworzeniu okna i kontekstu opengl
//ustawienie macierzy projekcji na jednostkowa
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, 1 / 2, 0.1, 500);
    //ustawienie macierzy modelu-widoku na jednostkowa
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //inicjalizacja koloru tla na czerny (RGB 0-1,0-1,0-1), kanał alpha
    glClearColor(0.f, 0.f, 0.f, 1.f);


    printf("\n--------- KLAWISZE ---------\n--- Wlacz / wylacz swiatlo ---\n 0 - swiatlo z nieskonczonosci \n 1 - swiatlo czerwone \n 2 - swiatlo zielone \n 3 - swiatlo niebieskie \n 4 - swiatlo biale \n\n--- Poruszanie swiatlem bialym ---\n w - gora\n s - dol\n a - lewo\n d - prawo\n f - oddal / w glab\n c - przybliz\n\n");


    glutDisplayFunc(funkcjaRenderujaca);
    //glutIdleFunc(display);


    glutKeyboardFunc(funkcjaKlawiatury);

    //Startujemy pętle główną GLUT
    glutMainLoop();

    return 0;
}