

#include <iostream>
#include <GL/freeglut.h>
#include <tchar.h>



int rot_Z = 0;
int rot_Y = 0;
int rot_X = 0;
int x = 100;
int y = 0;
int z = -70;


GLuint t1;
GLuint t2;
GLuint t3;
GLuint t4;
GLuint t5;
GLuint t6;
GLuint tr;

bool cube = true;


bool LoadBitmapTex(LPCWSTR szFileName, GLuint& texid)
{
    HBITMAP hBMP;//uchwyt do bitmapy
    BITMAP BMP;//struktura opisujaca parametry bitmapy, wingdi.h, tez jest tu np BITMAPINFOHEADER
    //wczytaj bitmape, parametr tworzacy sekcje DIB kolokwialnie "tablice z pixelami"
    hBMP = (HBITMAP)LoadImage(GetModuleHandle(NULL), szFileName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION |
        LR_LOADFROMFILE);
    if (!hBMP)
    {
        printf("false hBMP ");
        return FALSE;
    }
    //pobierz informacje o obiekcie bitmapy, zapisane dane do struktury
    GetObject(hBMP, sizeof(BMP), &BMP);
    //wygeneruj teksture
    glGenTextures(1, &texid);
    //ustaw pwyrownanie struktury na 4 (slowo)
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    //zbinduj jako teksture 2D
    glBindTexture(GL_TEXTURE_2D, texid);
    //W jaki sposb powinna skalowac sie tekstura
    //generalnie tekstury maja rozmiary potegi 2, patrz mipmapy
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (BMP.bmBitsPixel != 24)//musi byc bitmapa 24bit per pixel
    {
        DeleteObject(hBMP);
        printf("false pixels ");
        return FALSE;
    }
    //Dolacz bitmape do tekstury
    glTexImage2D(GL_TEXTURE_2D, 0, 3, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
    //usun bitmape z pamieci
    DeleteObject(hBMP);
    return TRUE;
}


void pokazSciane() 
{
    srand(time(NULL));
    int random = rand() % 6;

    if (random == 1)
    {
        rot_X = 0;
        rot_Y = 180;
        rot_Z = 0;
    }
    else if (random == 2)
    {
        rot_X = 0;
        rot_Y = 90;
        rot_Z = 270;

    }
    else if (random == 3)
    {
        rot_X = 90;
        rot_Y = 0;
        rot_Z = 270;

    }
    else if (random == 4)
    {
        rot_X = 270;
        rot_Y = 0;
        rot_Z = 90;

    }
    else if (random == 5)
    {
        rot_X = 0;
        rot_Y = 270;
        rot_Z = 270;

    }
    else
    {
        rot_X = 0;
        rot_Y = 0;
        rot_Z = 0;
    }

    //printf("sciana: %i,   X: %i, Y: %i, Z: %i\n", random, rot_X, rot_Y, rot_Z);

}


void funkcjaRenderujaca()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_LIGHT0);
    //swiatlo z nieskonczonosci
    GLfloat lightPos0[] = { x, y, z, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    GLfloat diffuse[] = { 0.7,0.7,0.7,0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_TEXTURE_2D);


    if (cube) {
        // Sześcian
        glPushMatrix();
        glRotatef(rot_Z, 0, 0, 1);
        glRotatef(rot_X, 0, 1, 0);
        glRotatef(rot_Y, 1, 0, 0);
        glEnd();


        glBindTexture(GL_TEXTURE_2D, t6);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(-0.5f, -0.5f, -0.5f);
        glTexCoord2f(1, 0); glVertex3f(0.5f, -0.5f, -0.5f);
        glTexCoord2f(1, 1); glVertex3f(0.5f, 0.5f, -0.5f);
        glTexCoord2f(0, 1); glVertex3f(-0.5f, 0.5f, -0.5f);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, t1);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex3f(-0.5f, -0.5f, 0.5f);
        glTexCoord2f(1, 1); glVertex3f(0.5f, -0.5f, 0.5f);
        glTexCoord2f(1, 0); glVertex3f(0.5f, 0.5f, 0.5f);
        glTexCoord2f(0, 0); glVertex3f(-0.5f, 0.5f, 0.5f);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, t3);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 0); glVertex3f(0.5f, -0.5f, 0.5f);
        glTexCoord2f(1, 0); glVertex3f(0.5f, 0.5f, 0.5f);
        glTexCoord2f(1, 1); glVertex3f(0.5f, 0.5f, -0.5f);
        glTexCoord2f(0, 1); glVertex3f(0.5f, -0.5f, -0.5f);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, t4);
        glBegin(GL_QUADS);
        glTexCoord2f(1, 0); glVertex3f(-0.5f, -0.5f, 0.5f);
        glTexCoord2f(0, 0); glVertex3f(-0.5f, 0.5f, 0.5f);
        glTexCoord2f(0, 1); glVertex3f(-0.5f, 0.5f, -0.5f);
        glTexCoord2f(1, 1); glVertex3f(-0.5f, -0.5f, -0.5f);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, t5);
        glBegin(GL_QUADS);
        glTexCoord2f(1, 1); glVertex3f(-0.5f, 0.5f, 0.5f);
        glTexCoord2f(0, 1); glVertex3f(-0.5f, 0.5f, -0.5f);
        glTexCoord2f(0, 0); glVertex3f(0.5f, 0.5f, -0.5f);
        glTexCoord2f(1, 0); glVertex3f(0.5f, 0.5f, 0.5f);
        glEnd();

        glBindTexture(GL_TEXTURE_2D, t2);
        glBegin(GL_QUADS);
        glTexCoord2f(0, 1); glVertex3f(-0.5f, -0.5f, 0.5f);
        glTexCoord2f(0, 0); glVertex3f(0.5f, -0.5f, 0.5f);
        glTexCoord2f(1, 0); glVertex3f(0.5f, -0.5f, -0.5f);
        glTexCoord2f(1, 1); glVertex3f(-0.5f, -0.5f, -0.5f);

        glEnd();

        glPopMatrix();

    }

    else 
    {


        glPushMatrix();
             
        glBindTexture(GL_TEXTURE_2D, tr);
        glBegin(GL_TRIANGLES);
        glTexCoord2f(1.27, 1.767); glVertex3f(-0.8f, 0.8f, -0.2f);
        glTexCoord2f(1.27, 1.204); glVertex3f(-0.8f, -0.81f, -0.2f);
        glTexCoord2f(1.815, 1.204); glVertex3f(0.83f, -0.81f, -0.2f);
        glEnd();

        glPopMatrix();

        glBindTexture(GL_TEXTURE_2D, t2);
        glBegin(GL_QUADS);
        glVertex3f(1, 1, 0.5f);
        glVertex3f(1, -1, 0.5f);
        glVertex3f(-1, -1, 0.5f);
        glVertex3f(-1, 1, 0.5f);
        glEnd();

    }

   




    //aktualizacja ekranu poprzez zamiane bufforów
    glutSwapBuffers();
}

void funkcjaKlawiatury(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27: // ESCAPE key
        exit(0);
        break;

    case 't':
        cube = !cube;
        if (cube) {
            pokazSciane();
        }
        glutPostRedisplay();
        break;

    case 'z':
        //wcisnieto klawisz z
        rot_Z++;//zwieksz kat obrotu
        if (rot_Z > 360)
        {
            rot_Z = 0;
        }
        glutPostRedisplay();//wymuszenie przerysowania sceny
        break;

    case 'x':
        rot_X++;
        if (rot_X > 360)
        {
            rot_X = 0;
        }
        glutPostRedisplay();//wymuszenie przerysowania sceny
        break;

    case 'y':
        rot_Y++;
        if (rot_Y > 360)
        {
            rot_Y = 0;
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

    pokazSciane();
    // TEKSTURY

    LoadBitmapTex(TEXT("bitmapy\\1.bmp"), t1);

    LoadBitmapTex(TEXT("bitmapy\\2.bmp"), t2);

    LoadBitmapTex(TEXT("bitmapy\\3.bmp"), t3);

    LoadBitmapTex(TEXT("bitmapy\\4.bmp"), t4);

    LoadBitmapTex(TEXT("bitmapy\\5.bmp"), t5);

    LoadBitmapTex(TEXT("bitmapy\\6.bmp"), t6);

    LoadBitmapTex(TEXT("bitmapy\\trojkat.bmp"), tr);


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

    printf("----- KLAWISZE ----\n\n t  -  zmiana sceny (kostka / trojkat)\n x, y, z - obrot kostki");

    glutDisplayFunc(funkcjaRenderujaca);
    //glutIdleFunc(display);


    glutKeyboardFunc(funkcjaKlawiatury);

    //Startujemy pętle główną GLUT
    glutMainLoop();

    return 0;
}