// Test.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <GL/freeglut.h>

bool model = true;
bool ortho = true;
int rot_Z = 0;
int rot_Y = 0;
int rot_X = 0;
//GLfloat light_position[] = { 50.0, 50.0, 50.0, 50.0 };





void zmianaMacierzy() 
{
    model = !model;
    if (model) 
    {
        glMatrixMode(GL_MODELVIEW);
    }
    else 
    {
        glMatrixMode(GL_PROJECTION);
    }
}

void zmianaProjekcji()
{
    ortho = !ortho;
    if (ortho)
    {
        glLoadIdentity();
        glOrtho(-1, 1, -1, 1, -1.0f, 2.0f);
        printf("Ortho\n");
    }
    else
    {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluLookAt(0, 0, 1.5f, 0, 0, 2.5f, 0, 1, 0);
        //glFrustum(-1, 1, -1, 1, -1.0f, 8.0f);
        gluPerspective(120.0f, 1, 0.1f, 20.0f);
        glMatrixMode(GL_MODELVIEW);
        
        printf("Persp\n");
        
        
    }
}

void funkcjaRenderujaca()
{
    
    glClear(GL_COLOR_BUFFER_BIT);
   
   

    glPushMatrix();
    glRotatef(rot_Z, 0, 0, 1);
    glRotatef(rot_Y, 0, 1, 0);
    glRotatef(rot_X, 1, 0, 0);
    glEnd();


    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    
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
    case 'v':
        zmianaMacierzy();
        break;
    case 'p':
        zmianaProjekcji();
        break;
    case 27: // ESCAPE key
        exit(0);
        break;
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

    //glEnable(GL_CULL_FACE);
    //... kod w main po stworzeniu okna i kontekstu opengl
//ustawienie macierzy projekcji na jednostkowa
    glMatrixMode(GL_PROJECTION);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glutPostRedisplay();

    glLoadIdentity();
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



// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
