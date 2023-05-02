#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <GL/glut.h>
#include <vector>

double PI = 3.14159265358979;

void init(void);  // ayarlari init etti�imiz fonksiyon
void display(void); // t�m �izim i�lemlerinin bulundu�u fonksiyon

int i = 0;
float ver[8][3] =
{
    {-1.0,-1.0,1.0},
    {-1.0,1.0,1.0},
    {1.0,1.0,1.0},
    {1.0,-1.0,1.0},
    {-1.0,-1.0,-1.0},
    {-1.0,1.0,-1.0},
    {1.0,1.0,-1.0},
    {1.0,-1.0,-1.0},
};

GLfloat color[8][3] =
{
    {0.5,0.0,0.5},
    {0.5,0.0,0.0},
    {0.5,0.5,0.0},
    {0.0,0.5,0.0},
    {0.0,0.0,0.5},
    {0.5,0.5,0.5},
    {0.0,0.5,0.5},
};




void quad(int a, int b, int c, int d,int e) //sondaki de�er (yani"e" oluyor),k�p�n y�z�ne  hangi rengi vermek istedi�imi  se�ebilmek i�in vermi� oldu�um bir index.
{
    glBegin(GL_QUADS);
 

   
        glColor3fv(color[e]);
        glVertex3fv(ver[a]);

        glColor3fv(color[e]);
        glVertex3fv(ver[b]);

        glColor3fv(color[e]);
        glVertex3fv(ver[c]);

        glColor3fv(color[e]);
        glVertex3fv(ver[d]);
   
    glEnd();
    
}

void colorcube()
{
   
    quad(0, 3, 2, 1,0); 
    
    quad(2, 3, 7, 6,1);   
   
    quad(0, 4, 7, 3,2);
    
    quad(1, 2, 6, 5,3);
    
    quad(4, 5, 6, 7,4);
    quad(0, 1, 5, 4,5);
}

double rotate_y = 0;
double rotate_x = 0;
void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_RIGHT)// OK TU�LARI �LE OBJEY�  HAREKET ETT�RME
        rotate_y += 5;
    else if (key == GLUT_KEY_LEFT)// OK TU�LARI �LE OBJEY�  HAREKET ETT�RME
        rotate_y -= 5;
    else if (key == GLUT_KEY_UP)// OK TU�LARI �LE OBJEY�  HAREKET ETT�RME
        rotate_x += 5;
    else if (key == GLUT_KEY_DOWN)   // OK TU�LARI �LE OBJEY�  HAREKET ETT�RME
        rotate_x -= 5;
    glutPostRedisplay();
}

void display()
{
   glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    /*                                            // Bu k�s�m gene Init() fonksiyonunda oldu�u gibi 2D projeyi buraya at�p birle�tirmeye �al��t�m.
    glColor3f(0, 0.50, 100);// R,G,B
    glPointSize(4); // nokta boyutu
    glBegin(GL_POINTS);
    float i, r = 0.1;

    for (i = -1.0; i <= 1.0; i += 0.0001) {
        glVertex2f(cos(i * PI) * 2 * r, sin(i * PI) * 2 * r);

    }

    glEnd();
    glFlush();

    glColor3ub(122, 0, 0);
    glLineWidth(1000); // �izgi kal�nl���
    glBegin(GL_LINES);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.3, -0.3);
    glEnd();
    glFlush();

    glColor3ub(100, 100, 0);
    glBegin(GL_QUADS);
    glVertex2f(-0.7, -0.2);
    glVertex2f(-0.7, 0.2);
    glVertex2f(-0.3, 0.2);
    glVertex2f(-0.3, -0.2);
    glEnd();
    glFlush();

    */

   
    glLoadIdentity();
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    gluPerspective(20, w / h, 0.1, 100);  //g�r�nt�n�n olu�abilmesi i�in gerekli.3D objelerin perspektif ayar�
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

    gluLookAt  //bu k�s�m k�p'�n ekranda yer alacak konumunu belirliyor.
    (
        7 ,7, 7,
        1, 1, 1,
        1, 0, 1
    );

   
   
  
    
    //init();
    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
    colorcube();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{



    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("Computer Graphics Final Projesi 17-155-014 H.Egemen Gulpinar");
   
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;



}



/*void init(void) // 2D objelerin oldu�u dosyay� buraya at�p birle�tirmeye �al��t�m.Ancak 3D K�p ile 2D cisimleri �st �ste biniyor,birbirinden ay�ram�yorum.
{
    // arka plan rengini belirle
    glClearColor(0.95, 0.95, 0.5, 1.0);// k�rm�z�,ye�il,mavi,alpha [0-1]
    glShadeModel(GL_FLAT);
    // bakis degerlerini ilkle
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);

   


    glRotatef(rotate_x, 1.0, 0.0, 0.0);
    glRotatef(rotate_y, 0.0, 1.0, 0.0);
}

*/