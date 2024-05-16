#define GLEW_STATIC
#include <GL/glew.h>//pierwsza,inaczej moga byc GLchar udefined etc.
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>


#include <stdio.h>
#include <tchar.h>


#include <iostream>


/*
int rot_Z = 0;
int rot_Y = 0;
int rot_X = 0;
int x = 100;
int y = 0;
int z = -70;
*/


// ------------- ZMIANA NA TRÓJKĄT ---------------

bool cube = true;



const GLchar * simply_vertex_shader =
"#version 150\n"
"in vec3 position;"
"uniform float alpha;"
"mat3 rotation = mat3("
"vec3(cos(alpha), -sin(alpha), 0.0),"
"vec3(sin(alpha), cos(alpha), 0.0),"
"vec3(0.1, 0.2, 0.0)"
");"
"void main()"
"{"
" gl_Position = vec4(rotation*position,1);"
"}";

const GLchar* simply_fragment_shader =
"#version 150 \n"
"out vec4 out_color;"
"void main()"
"{"
" out_color = vec4(0.6,0.4,1.0, 1.0);"
"}";


static const GLfloat triangle_vertex[] = {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f, 1.0f, 0.0f,
};


static const GLfloat cube_vertex[] = {
    -0.5f,-0.5f,-0.5f, // 1
    -0.5f,-0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f,
    0.5f, 0.5f,-0.5f, // 2
    -0.5f,-0.5f,-0.5f,
    -0.5f, 0.5f,-0.5f,
    0.5f,-0.5f, 0.5f, // 3
    -0.5f,-0.5f,-0.5f,
    0.5f,-0.5f,-0.5f,
    0.5f, 0.5f,-0.5f, //4
    0.5f,-0.5f,-0.5f,
    -0.5f,-0.5f,-0.5f,
    -0.5f,-0.5f,-0.5f, //5
    -0.5f, 0.5f, 0.5f,
    -0.5f, 0.5f,-0.5f,
    0.5f,-0.5f, 0.5f, //6
    -0.5f,-0.5f, 0.5f,
    -0.5f,-0.5f,-0.5f,
    -0.5f, 0.5f, 0.5f, //7
    -0.5f,-0.5f, 0.5f,
    0.5f,-0.5f, 0.5f,
    0.5f, 0.5f, 0.5f, //8
    0.5f,-0.5f,-0.5f,
    0.5f, 0.5f,-0.5f,
    0.5f,-0.5f,-0.5f, //9
    0.5f, 0.5f, 0.5f,
    0.5f,-0.5f, 0.5f,
    0.5f, 0.5f, 0.5f, //10
    0.5f, 0.5f,-0.5f,
    -0.5f, 0.5f,-0.5f,
    0.5f, 0.5f, 0.5f,  //11
    -0.5f, 0.5f,-0.5f,
    -0.5f, 0.5f, 0.5f,
    0.5f, 0.5f, 0.5f, //12
    -0.5f, 0.5f, 0.5f,
    0.5f,-0.5f, 0.5f
};


GLint alphaUniformLocation;

float rotationAngle = 0.0f; // Initial rotation angle
const float rotationSpeed = 0.1f; // Adjust as needed


void funkcjaRenderujaca()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (cube) {
        rotationAngle += rotationSpeed;
        glUniform1f(alphaUniformLocation, rotationAngle);
        glDrawArrays(GL_TRIANGLES, 0, 12 * 3);
    }
    else {
        glDrawArrays(GL_TRIANGLES, 0, 3);
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
    case 'r':
        
        glutPostRedisplay();//wymuszenie przerysowania sceny
        break;
    }

}





int main(int argc, char* args[])
{
    glutInit(&argc, args);

    //Tworzymy kontekst OpenGL 2.1
    glutInitContextVersion(2, 1);
    

    //Podwójne buforowanie
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    //Inicjujemy okienko, w którym będzie wyświetlana scena (rozmiar 300x300)
    glutInitWindowSize(300, 300);
    //i tworzymy je z nagłówkiem w pasku tytułu
    glutCreateWindow("Zad8 OpenGL-Shader");

    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        printf("Err %d", err);
        return 0;
    }

    //-----------------------------------------------

    GLuint vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);


    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);


    

    if (cube) {

        glBufferData(GL_ARRAY_BUFFER, sizeof(cube_vertex), cube_vertex, GL_STATIC_DRAW);

    }
    else {
        glBufferData(GL_ARRAY_BUFFER, sizeof(triangle_vertex), triangle_vertex, GL_STATIC_DRAW);
    }

    


    // Utwórz i skompiluja vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &simply_vertex_shader, NULL);
    glCompileShader(vertexShader);
    // Utwórz i skompiluja fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &simply_fragment_shader, NULL);
    glCompileShader(fragmentShader);
    //też może odbyć się w inicjalizacji prog

    glCompileShader(vertexShader);
    GLint isCompiled = 0;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 0;
        glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);
        GLchar* errorLog = (GLchar*)malloc(maxLength * sizeof(GLchar));
        glGetShaderInfoLog(vertexShader, maxLength, &maxLength, errorLog);
        printf(errorLog);
        free(errorLog);
        glDeleteShader(vertexShader);
        getchar();
        return 0;
    }


    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    // Dobindowanie zmiennej out_color dla shadera
    glBindFragDataLocation(shaderProgram, 0, "out_color");
    glLinkProgram(shaderProgram); // linkowanie
    glUseProgram(shaderProgram); // uzycie

   
    //pobranie umiejscowienia atrybutu "position" w naszym programie
    GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
   
    //odblokowanie atrybutów
    glEnableVertexAttribArray(posAttrib);
  
    //ustawienie atrybutów
    glVertexAttribPointer(
        posAttrib, //pozycja
        3, //rozmiar elementów dla każdego wierzchołka
        GL_FLOAT, //typ
        GL_FALSE,//czy znormalizowany
        0,//"stride" w przypadku gdy zero oznacza, że mamy ciągłą upakowaną tablicę
        0//wskażnik do pierwszego atrybutu, jeśli zero to od początku (domyślnie)
    );

    if (cube) {
        alphaUniformLocation = glGetUniformLocation(shaderProgram, "alpha");
    }
    

    glutDisplayFunc(funkcjaRenderujaca);
    //glutIdleFunc(display);
    

    glutKeyboardFunc(funkcjaKlawiatury);

    // Startujemy pętle główną GLUT
    glutMainLoop();

    glDeleteProgram(shaderProgram);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);

    return 0;
}
