// Test.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <GL/freeglut.h>


bool naive = true;
int rot_Z = 0;
int rot_Y = 0;
int rot_X = 0;
//GLfloat light_position[] = { 50.0, 50.0, 50.0, 50.0 };

float startx = 0;
float starty = 0;
float endx = 0;
float endy = 0;

bool gluInvertMatrix(const float m[16], float invOut[16])
{
    float inv[16], det;
    int i;
    inv[0] = m[5] * m[10] * m[15] -
        m[5] * m[11] * m[14] -
        m[9] * m[6] * m[15] +
        m[9] * m[7] * m[14] +
        m[13] * m[6] * m[11] -
        m[13] * m[7] * m[10];
    inv[4] = -m[4] * m[10] * m[15] +
        m[4] * m[11] * m[14] +
        m[8] * m[6] * m[15] -
        m[8] * m[7] * m[14] -
        m[12] * m[6] * m[11] +
        m[12] * m[7] * m[10];
    inv[8] = m[4] * m[9] * m[15] -
        m[4] * m[11] * m[13] -
        m[8] * m[5] * m[15] +
        m[8] * m[7] * m[13] +
        m[12] * m[5] * m[11] -
        m[12] * m[7] * m[9];
    inv[12] = -m[4] * m[9] * m[14] +
        m[4] * m[10] * m[13] +
        m[8] * m[5] * m[14] -
        m[8] * m[6] * m[13] -
        m[12] * m[5] * m[10] +
        m[12] * m[6] * m[9];
    inv[1] = -m[1] * m[10] * m[15] +
        m[1] * m[11] * m[14] +
        m[9] * m[2] * m[15] -
        m[9] * m[3] * m[14] -
        m[13] * m[2] * m[11] +
        m[13] * m[3] * m[10];
    inv[5] = m[0] * m[10] * m[15] -
        m[0] * m[11] * m[14] -
        m[8] * m[2] * m[15] +
        m[8] * m[3] * m[14] +
        m[12] * m[2] * m[11] -
        m[12] * m[3] * m[10];
    inv[9] = -m[0] * m[9] * m[15] +
        m[0] * m[11] * m[13] +
        m[8] * m[1] * m[15] -
        m[8] * m[3] * m[13] -
        m[12] * m[1] * m[11] +
        m[12] * m[3] * m[9];
    inv[13] = m[0] * m[9] * m[14] -
        m[0] * m[10] * m[13] -
        m[8] * m[1] * m[14] +
        m[8] * m[2] * m[13] +
        m[12] * m[1] * m[10] -
        m[12] * m[2] * m[9];
    inv[2] = m[1] * m[6] * m[15] -
        m[1] * m[7] * m[14] -
        m[5] * m[2] * m[15] +
        m[5] * m[3] * m[14] +
        m[13] * m[2] * m[7] -
        m[13] * m[3] * m[6];
    inv[6] = -m[0] * m[6] * m[15] +
        m[0] * m[7] * m[14] +
        m[4] * m[2] * m[15] -
        m[4] * m[3] * m[14] -
        m[12] * m[2] * m[7] +
        m[12] * m[3] * m[6];
    inv[10] = m[0] * m[5] * m[15] -
        m[0] * m[7] * m[13] -
        m[4] * m[1] * m[15] +
        m[4] * m[3] * m[13] +
        m[12] * m[1] * m[7] -
        m[12] * m[3] * m[5];
    inv[14] = -m[0] * m[5] * m[14] +
        m[0] * m[6] * m[13] +
        m[4] * m[1] * m[14] -
        m[4] * m[2] * m[13] -
        m[12] * m[1] * m[6] +
        m[12] * m[2] * m[5];
    inv[3] = -m[1] * m[6] * m[11] +
        m[1] * m[7] * m[10] +
        m[5] * m[2] * m[11] -
        m[5] * m[3] * m[10] -
        m[9] * m[2] * m[7] +
        m[9] * m[3] * m[6];
    inv[7] = m[0] * m[6] * m[11] -
        m[0] * m[7] * m[10] -
        m[4] * m[2] * m[11] +
        m[4] * m[3] * m[10] +
        m[8] * m[2] * m[7] -
        m[8] * m[3] * m[6];
    inv[11] = -m[0] * m[5] * m[11] +
        m[0] * m[7] * m[9] +
        m[4] * m[1] * m[11] -
        m[4] * m[3] * m[9] -
        m[8] * m[1] * m[7] +
        m[8] * m[3] * m[5];
    inv[15] = m[0] * m[5] * m[10] -
        m[0] * m[6] * m[9] -
        m[4] * m[1] * m[10] +
        m[4] * m[2] * m[9] +
        m[8] * m[1] * m[6] -
        m[8] * m[2] * m[5];
    det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];
    if (det == 0)
        return false;
    det = 1.0 / det;
    for (i = 0; i < 16; i++)
        invOut[i] = inv[i] * det;
    return true;
}



void fM1(int x, int y)
{
    //printf("M1, pos(X:%d, Y:%d\n", x - startx, y - starty);
    
}
void fM2(int x, int y)
{
    //printf("M2, pos(X:%d, Y:%d\n", x, y);
    
}
void fM3(int button, int state, int x, int y)
{
    if (naive)
    {
        if (state == 0) 
        {
            startx = (float) x/5;
            starty = (float) y/3;
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
    else
    {
        float m[16];
        int v[4];
        float invOut[16];
        glGetFloatv(GL_MODELVIEW_MATRIX, m);
        glGetIntegerv(GL_VIEWPORT, v);

        

        if (state == 0)
        {
            startx = (float)x;
            starty = (float)y;
        }
        if (state == 1)
        {
            endx = (float)x;
            endy = (float)y;

            float x_rot = starty - endy;
            float y_rot = startx - endx;

            

            float angle = -sqrtf((startx - endx) * (startx - endx) + (starty - endy) * (starty - endy)) / v[3] * 180 ;

            if (gluInvertMatrix(m, invOut))
            {
                float nx = invOut[0] * x_rot + invOut[3] * y_rot;
                float ny = invOut[1] * x_rot + invOut[4] * y_rot;
                float nz = invOut[2] * x_rot + invOut[5] * y_rot;

                glRotatef(-angle, nx, ny, nz);
                printf("%f, %f, %f \n", nx, ny, nz);
            }

            
        }
    }
    
   
}


void funkcjaRenderujaca()
{
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   
   

    glPushMatrix();
    glRotatef(rot_Z, 0, 0, 1);
    glRotatef(rot_Y, 0, 1, 0);
    glRotatef(rot_X, 1, 0, 0);
    

    
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.0f);     // Orange
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, - 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    
    glEnd();

    glPopMatrix();

    //aktualizacja ekranu poprzez zamiane bufforów
    glutSwapBuffers();
}

void funkcjaKlawiatury(unsigned char key, int x, int y)
{
    printf("Key %c, pos(X: %d, Y: %d)\n", key, x, y);//uwaga tylko gdy mamy konsole !
    switch (key)
    {

    case 27: // ESCAPE key
        exit(0);
        break;

    case 'q':
        naive = !naive;

    case 'z':
        //wcisnieto klawisz z
        rot_Z++;//zwieksz kat obrotu
        if (rot_Z > 360)
        {
            rot_Z = 0;
        }
    case 'y':
        rot_Y++;
        if (rot_Y > 360)
        {
            rot_Y = 0;
        }
        
    case 'x':
        rot_X++;
        if (rot_X > 360)
        {
            rot_X = 0;
        }
        
        
        
glutPostRedisplay();//wymuszenie przerysowania sceny
break;
    }
}

int main(int argc, char* args[])
{

    glutInit(&argc, args);
#ifdef _DEBUG
    std::cout << "Debug!\n";
#endif
    std::cout << "Hello World!\n";


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


    //glEnable(GL_CULL_FACE);
    //... kod w main po stworzeniu okna i kontekstu opengl
//ustawienie macierzy projekcji na jednostkowa
    //glMatrixMode(GL_PROJECTION);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glutPostRedisplay();
    glEnable(GL_DEPTH_TEST);
    //glLoadIdentity();
    //ustawienie macierzy modelu-widoku na jednostkowa
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //inicjalizacja koloru tla na czerny (RGB 0-1,0-1,0-1), kanał alpha
    glClearColor(0.f, 0.f, 0.f, 1.f);
    //... dalasza częsc kodu
    glutDisplayFunc(funkcjaRenderujaca);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
    {
        //reakcja na blad
        std::cout << "Błąd :((\n";
    }

    glutKeyboardFunc(funkcjaKlawiatury);

    //Startujemy pętle główną GLUT
    glutMainLoop();

    return 0;


}