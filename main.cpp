#include<GL/gl.h>
#include<GL\glut.h>
#include<iostream>
using namespace std;
#define SPEED 40.0      //speed of traffic

float i=0.0;    //movement of car
float m=0.0;    //movement of clouds
float n=0.0;    //movement of plane along x-axis
float o=0.0;    //  and y-axis

int light=1;      //1 for green-light, 0 for red-light
int day=1;        //1 for day ,0 for night
int planee=0;      //1 for plane
int nightWindowValue=0;  //1 for lights in window

float getRGB(float x)
{
    float RGB = x/255;
    return RGB;
}


void draw_points(int cx, int cy)
{

    glBegin(GL_POINTS);
    glVertex2i(cx,cy);
    glEnd();
}

void plotpixels(int h,int k, int x,int y)
{
    draw_points(x+h,y+k);
    draw_points(-x+h,y+k);
    draw_points(x+h,-y+k);
    draw_points(-x+h,-y+k);
    draw_points(y+h,x+k);
    draw_points(-y+h,x+k);
    draw_points(y+h,-x+k);
    draw_points(-y+h,-x+k);
}

void draw_circle(int h, int k, int r)
{
    int d=1-r, x=0, y=r;
    while(y>x)
    {
        plotpixels(h,k,x,y);

        if(d<0)
        {
            d+=2*x+3;
        }
        else
        {
            d+=2*(x-y)+5;
            --y;
        }
        ++x;
    }
    plotpixels(h,k,x,y);
}


void cars ()
{
    glColor3f(getRGB(255),getRGB(0),getRGB(0)); //car1
    glBegin(GL_POLYGON);
    glVertex2f(755+i,65);
    glVertex2f(755+i,115);
    glVertex2f(785+i,125);
    glVertex2f(805+i,180);
    glVertex2f(905+i,180);
    glVertex2f(930+i,125);
    glVertex2f(980+i,115);
    glVertex2f(980+i,65);
    glEnd();




    //windowcar1 1
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(805+i,165);
    glVertex2f(840+i,165);
    glVertex2f(850+i,130);
    glVertex2f(790+i,130);

    //glVertex2f(830+i,130);
    glEnd();



    //window 2
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(865+i,165);
    glVertex2f(900+i,165);

    glVertex2f(920+i,130);
    glVertex2f(855+i,130);


    //glVertex2f(830+i,130);
    glEnd();



    for(int l=0; l<20; l++)  //car1 wheel
    {
        glColor3f(0.0,0.0,0.0);
        draw_circle(805+i,70,l);
        draw_circle(905+i,70,l);
    }



    glColor3f(getRGB(248),getRGB(219),getRGB(20)); //CAR2
    glBegin(GL_POLYGON);
    glVertex2f(435+i,65);
    glVertex2f(435+i,115);
    glVertex2f(465+i,125);
    glVertex2f(485+i,180);
    glVertex2f(585+i,180);
    glVertex2f(610+i,125);
    glVertex2f(660+i,115);
    glVertex2f(660+i,65);
    glEnd();



    //windowcar1 1
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(485+i,165);
    glVertex2f(520+i,165);
    glVertex2f(530+i,130);
    glVertex2f(470+i,130);


    //glVertex2f(830+i,130);
    glEnd();

    //windowcar1 1
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(545+i,165);
    glVertex2f(580+i,165);
    glVertex2f(595+i,130);

    glVertex2f(535+i,130);


    //glVertex2f(830+i,130);
    glEnd();





    for(int l=0; l<20; l++)  //car1 wheel
    {
        glColor3f(0.0,0.0,0.0);
        draw_circle(485+i,70,l);
        draw_circle(585+i,70,l);
    }




    glColor3f(getRGB(87),getRGB(252),getRGB(16)); //CAR2
    glBegin(GL_POLYGON);
    glVertex2f(35+i,65);
    //glVertex2f(35+i,115);
    //glVertex2f(65+i,125);
    glVertex2f(55+i,180);
    glVertex2f(240+i,180);
    //glVertex2f(210+i,125);
    //glVertex2f(260+i,115);
    glVertex2f(260+i,65);
    glEnd();



    //windowcar1 bus
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(65+i,165);
    glVertex2f(95+i,165);
    glVertex2f(105+i,120);
    glVertex2f(55+i,120);

    glEnd();


    //windowcar2 bus
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(120+i,165);
    glVertex2f(150+i,165);
    glVertex2f(160+i,120);
    glVertex2f(110+i,120);

    glEnd();

    //windowcar3 bus
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(175+i,165);
    glVertex2f(210+i,165);
    glVertex2f(225+i,120);
    glVertex2f(165+i,120);

    glEnd();


    for(int l=0; l<20; l++)  //car1 wheel
    {
        glColor3f(0.0,0.0,0.0);
        draw_circle(85+i,70,l);
        draw_circle(185+i,70,l);
    }


    glColor3f(getRGB(255),getRGB(0),getRGB(0)); //car4
    glBegin(GL_POLYGON);
    glVertex2f(1005-i,255);
    glVertex2f(1005-i,300);
    glVertex2f(1085-i,325);
    glVertex2f(1085-i,370);
    glVertex2f(1185-i,370);
    glVertex2f(1210-i,315);
    glVertex2f(1235-i,305);
    glVertex2f(1235-i,255);
    glEnd();

    //windowcar1 1
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1090-i,360);
    glVertex2f(1120-i,360);
    glVertex2f(1135-i,325);
    glVertex2f(1070-i,325);

    glEnd();

    //windowcar1 1
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1145-i,360);
    glVertex2f(1175-i,360);
    glVertex2f(1195-i,325);
    glVertex2f(1140-i,325);


    glEnd();















    for(int l=0; l<20; l++)  //car1 whee4
    {
        glColor3f(0.0,0.0,0.0);
        draw_circle(1085-i,260,l);
        draw_circle(1185-i,260,l);
    }



    glColor3f(getRGB(79),getRGB(237),getRGB(244)); //car5
    glBegin(GL_POLYGON);
    glVertex2f(705-i,255);
    glVertex2f(705-i,300);
    glVertex2f(785-i,325);
    glVertex2f(785-i,370);
    glVertex2f(885-i,370);
    glVertex2f(910-i,315);
    glVertex2f(935-i,305);
    glVertex2f(935-i,255);
    glEnd();


    //windowcar1 1
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(785-i,360);
    glVertex2f(820-i,360);
    glVertex2f(830-i,320);
    glVertex2f(770-i,320);
    glEnd();




    //windowcar1 1
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(840-i,360);
    glVertex2f(875-i,360);
    glVertex2f(890-i,320);
    glVertex2f(835-i,320);

    glEnd();



    for(int l=0; l<20; l++)  //car1 whee5
    {
        glColor3f(0.0,0.0,0.0);
        draw_circle(785-i,260,l);
        draw_circle(885-i,260,l);
    }



    glColor3f(getRGB(245),getRGB(146),getRGB(10)); //car5
    glBegin(GL_POLYGON);
    glVertex2f(365-i,255);
    glVertex2f(365-i,330);
    glVertex2f(435-i,355);
    glVertex2f(395-i,370);
    glVertex2f(440-i,370);
    glVertex2f(440-i,320);
    glVertex2f(600-i,320);
    glVertex2f(600-i,255);
    glEnd();


    //windowcar1 1
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(400-i,360);
    glVertex2f(425-i,360);
    glVertex2f(430-i,320);
    glVertex2f(390-i,320);

    glEnd();



    for(int l=0; l<25; l++)  //car1 wheel
    {
        glColor3f(0.0,0.0,0.0);
        draw_circle(410-i,260,l);
        draw_circle(550-i,260,l);
    }

}

void nightWindow()
{
    glBegin(GL_POLYGON);  //start house1 window1
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(115, 525);
    glVertex2f(115, 550);
    glVertex2f(145, 550);
    glVertex2f(145, 525);
    glEnd();

    glBegin(GL_POLYGON);  //start house1 window2
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(155, 525);
    glVertex2f(155, 550);
    glVertex2f(185, 550);
    glVertex2f(185, 525);
    glEnd();


    glBegin(GL_POLYGON);  //start house1 window3
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(115, 575);
    glVertex2f(115, 600);
    glVertex2f(145, 600);
    glVertex2f(145, 575);
    glEnd();


    glBegin(GL_POLYGON);  //start house1 window4
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(155, 575);
    glVertex2f(155, 600);
    glVertex2f(185, 600);
    glVertex2f(185, 575);
    glEnd();

    glBegin(GL_POLYGON);  //start house2 window1
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(240., 520);
    glVertex2f(240,  545);
    glVertex2f(280,  545);
    glVertex2f(280,  520);
    glEnd();


    glBegin(GL_POLYGON);  //start house2 window2
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(290., 520);
    glVertex2f(290,  545);
    glVertex2f(330,  545);
    glVertex2f(330,  520);
    glEnd();

    glBegin(GL_POLYGON);  //start house3 window1
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(380, 540);
    glVertex2f(380, 565);
    glVertex2f(405, 565);
    glVertex2f(405, 540);
    glEnd();

    glBegin(GL_POLYGON);  //start house3 window2
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(415, 540);
    glVertex2f(415, 565);
    glVertex2f(440, 565);
    glVertex2f(440, 540);
    glEnd();

    glBegin(GL_POLYGON);  //start house3 window3
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(380, 585);
    glVertex2f(380, 610);
    glVertex2f(405, 610);
    glVertex2f(405, 585);
    glEnd();

    glBegin(GL_POLYGON);  //start house3 window4
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(415, 585);
    glVertex2f(415, 610);
    glVertex2f(440, 610);
    glVertex2f(440, 585);
    glEnd();


    glBegin(GL_POLYGON);  //start house3 window5
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(380, 630);
    glVertex2f(380, 655);
    glVertex2f(405, 655);
    glVertex2f(405, 630);
    glEnd();

    glBegin(GL_POLYGON);  //start house3 window6
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(415, 630);
    glVertex2f(415, 655);
    glVertex2f(440, 655);
    glVertex2f(440, 630);
    glEnd();

    glBegin(GL_POLYGON);  //start tower window1
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(635, 555);
    glVertex2f(635, 630);
    glVertex2f(650, 630);
    glVertex2f(650, 555);
    glEnd();



    glBegin(GL_POLYGON);  //start tower window1
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(635, 555);
    glVertex2f(635, 630);
    glVertex2f(650, 630);
    glVertex2f(650, 555);
    glEnd();



    glBegin(GL_POLYGON);  //start tower window1
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(640, 555);
    glVertex2f(640, 630);
    glVertex2f(650, 630);
    glVertex2f(650, 555);
    glEnd();


    glBegin(GL_POLYGON);  //start tower window2
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(665, 555);
    glVertex2f(665, 630);
    glVertex2f(680, 630);
    glVertex2f(680, 555);
    glEnd();


    glBegin(GL_POLYGON);  //start house4 window1
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(865, 520);
    glVertex2f(865, 565);
    glVertex2f(905, 565);
    glVertex2f(905, 520);
    glEnd();

    glBegin(GL_POLYGON);  //start house4 window2
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(925, 520);
    glVertex2f(925, 565);
    glVertex2f(965, 565);
    glVertex2f(965, 520);
    glEnd();

    glBegin(GL_POLYGON);  //start house4 window3
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(985, 520);
    glVertex2f(985, 565);
    glVertex2f(1025, 565);
    glVertex2f(1025, 520);
    glEnd();


    glBegin(GL_POLYGON);  //start house4 window4
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(1045, 520);
    glVertex2f(1045, 565);
    glVertex2f(1085, 565);
    glVertex2f(1085, 520);
    glEnd();

    glBegin(GL_POLYGON);  //start house5 window1
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(1140, 540);
    glVertex2f(1140, 570);
    glVertex2f(1175, 570);
    glVertex2f(1175, 540);
    glEnd();

    glBegin(GL_POLYGON);  //start house5 window2
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(1185, 540);
    glVertex2f(1185, 570);
    glVertex2f(1220, 570);
    glVertex2f(1220, 540);
    glEnd();

    glBegin(GL_POLYGON);  //start house5 window3
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(1140, 590);
    glVertex2f(1140, 620);
    glVertex2f(1175, 620);
    glVertex2f(1175, 590);
    glEnd();

    glBegin(GL_POLYGON);  //start house5 window4
    glColor3f(getRGB(255), getRGB(255), getRGB(255));
    glVertex2f(1185, 590);
    glVertex2f(1185, 620);
    glVertex2f(1220, 620);
    glVertex2f(1220, 590);
    glEnd();


}

void building()
{
    glColor3f(getRGB(191), getRGB(0), getRGB(0));
    glBegin(GL_POLYGON);  //start house1
    glVertex2f(100, 450);
    glVertex2f(100, 650);
    glVertex2f(200, 650);
    glVertex2f(200,450);
    glEnd();

    glColor3f(getRGB(125), getRGB(0), getRGB(0)); //start house1 side
    glBegin(GL_POLYGON);
    glVertex2f(200,450);
    glVertex2f(200, 650);
    glVertex2f(215, 635);
    glVertex2f(215,455);
    glEnd();


    glBegin(GL_POLYGON);  //start house1 door
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(135, 450);
    glVertex2f(135, 490);
    glVertex2f(165, 490);
    glVertex2f(165,450);
    glEnd();  //end door



    glBegin(GL_POLYGON);  //start house1 window1
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(115, 525);
    glVertex2f(115, 550);
    glVertex2f(145, 550);
    glVertex2f(145, 525);
    glEnd();

    glBegin(GL_POLYGON);  //start house1 window2
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(155, 525);
    glVertex2f(155, 550);
    glVertex2f(185, 550);
    glVertex2f(185, 525);
    glEnd();


    glBegin(GL_POLYGON);  //start house1 window3
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(115, 575);
    glVertex2f(115, 600);
    glVertex2f(145, 600);
    glVertex2f(145, 575);
    glEnd();


    glBegin(GL_POLYGON);  //start house1 window4
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(155, 575);
    glVertex2f(155, 600);
    glVertex2f(185, 600);
    glVertex2f(185, 575);
    glEnd();



    glColor3f(getRGB(255), getRGB(255), getRGB(0));
    glBegin(GL_POLYGON);  //start house2
    glVertex2f(225, 450);
    glVertex2f(225, 575);
    glVertex2f(350, 575);
    glVertex2f(350,450);
    glEnd();

    glColor3f(getRGB(170), getRGB(170), getRGB(0)); //start house2 side
    glBegin(GL_POLYGON);
    glVertex2f(350,450);
    glVertex2f(350, 575);
    glVertex2f(360, 565);
    glVertex2f(360,455);
    glEnd();


    glBegin(GL_POLYGON);  //start house2 door
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(270, 450);
    glVertex2f(270, 490);
    glVertex2f(305, 490);
    glVertex2f(305, 450);
    glEnd();  //end door


    glBegin(GL_POLYGON);  //start house2 window1
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(240., 520);
    glVertex2f(240,  545);
    glVertex2f(280,  545);
    glVertex2f(280,  520);
    glEnd();


    glBegin(GL_POLYGON);  //start house2 window2
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(290., 520);
    glVertex2f(290,  545);
    glVertex2f(330,  545);
    glVertex2f(330,  520);
    glEnd();






    glColor3f(getRGB(0), getRGB(161), getRGB(0));
    glBegin(GL_POLYGON);  //start house3
    glVertex2f(375, 450);
    glVertex2f(375, 700);
    glVertex2f(450, 700);
    glVertex2f(450, 450);
    glEnd();

    glColor3f(getRGB(0), getRGB(117), getRGB(0)); //start house3 side
    glBegin(GL_POLYGON);
    glVertex2f(450,450);
    glVertex2f(450, 700);
    glVertex2f(465, 680);
    glVertex2f(465,455);
    glEnd();


    glBegin(GL_POLYGON);  //start house3 door
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(400, 450);
    glVertex2f(400, 505);
    glVertex2f(422, 505);
    glVertex2f(422, 450);
    glEnd();

    glBegin(GL_POLYGON);  //start house3 window1
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(380, 540);
    glVertex2f(380, 565);
    glVertex2f(405, 565);
    glVertex2f(405, 540);
    glEnd();

    glBegin(GL_POLYGON);  //start house3 window2
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(415, 540);
    glVertex2f(415, 565);
    glVertex2f(440, 565);
    glVertex2f(440, 540);
    glEnd();

    glBegin(GL_POLYGON);  //start house3 window3
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(380, 585);
    glVertex2f(380, 610);
    glVertex2f(405, 610);
    glVertex2f(405, 585);
    glEnd();

    glBegin(GL_POLYGON);  //start house3 window4
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(415, 585);
    glVertex2f(415, 610);
    glVertex2f(440, 610);
    glVertex2f(440, 585);
    glEnd();


    glBegin(GL_POLYGON);  //start house3 window5
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(380, 630);
    glVertex2f(380, 655);
    glVertex2f(405, 655);
    glVertex2f(405, 630);
    glEnd();

    glBegin(GL_POLYGON);  //start house3 window6
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(415, 630);
    glVertex2f(415, 655);
    glVertex2f(440, 655);
    glVertex2f(440, 630);
    glEnd();



    glColor3f(getRGB(0), getRGB(58), getRGB(117));
    glBegin(GL_POLYGON);  //start tower
    glVertex2f(625, 450);
    glVertex2f(625, 675);
    glVertex2f(660, 698);
    glVertex2f(660, 770);
    glVertex2f(660, 770);
    glVertex2f(665, 695);
    glVertex2f(700, 675);
    glVertex2f(700, 450);
    glEnd();


    glBegin(GL_POLYGON);  //start tower door
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(653, 450);
    glVertex2f(653, 535);
    glVertex2f(673, 535);
    glVertex2f(673, 450);
    glEnd();



    glBegin(GL_POLYGON);  //start tower window1
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(635, 555);
    glVertex2f(635, 630);
    glVertex2f(650, 630);
    glVertex2f(650, 555);
    glEnd();



    glBegin(GL_POLYGON);  //start tower window1
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(635, 555);
    glVertex2f(635, 630);
    glVertex2f(650, 630);
    glVertex2f(650, 555);
    glEnd();



    glBegin(GL_POLYGON);  //start tower window1
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(640, 555);
    glVertex2f(640, 630);
    glVertex2f(650, 630);
    glVertex2f(650, 555);
    glEnd();


    glBegin(GL_POLYGON);  //start tower window2
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(665, 555);
    glVertex2f(665, 630);
    glVertex2f(680, 630);
    glVertex2f(680, 555);
    glEnd();


    glColor3f(getRGB(255), getRGB(130), getRGB(4));
    glBegin(GL_POLYGON);  //start house4
    glVertex2f(850, 450);
    glVertex2f(850, 600);
    glVertex2f(1100, 600);
    glVertex2f(1100, 450);
    glEnd();

    glColor3f(getRGB(198), getRGB(99), getRGB(0)); //start house4 side
    glBegin(GL_POLYGON);
    glVertex2f(1100, 600);
    glVertex2f(1100, 450);
    glVertex2f(1115, 455);
    glVertex2f(1115, 585);
    glEnd();

    glBegin(GL_POLYGON);  //start house4 door
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(930, 450);
    glVertex2f(930, 490);
    glVertex2f(1015, 490);
    glVertex2f(1015, 450);
    glEnd();


    glBegin(GL_POLYGON);  //start house4 window1
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(865, 520);
    glVertex2f(865, 565);
    glVertex2f(905, 565);
    glVertex2f(905, 520);
    glEnd();

    glBegin(GL_POLYGON);  //start house4 window2
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(925, 520);
    glVertex2f(925, 565);
    glVertex2f(965, 565);
    glVertex2f(965, 520);
    glEnd();

    glBegin(GL_POLYGON);  //start house4 window3
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(985, 520);
    glVertex2f(985, 565);
    glVertex2f(1025, 565);
    glVertex2f(1025, 520);
    glEnd();


    glBegin(GL_POLYGON);  //start house4 window4
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(1045, 520);
    glVertex2f(1045, 565);
    glVertex2f(1085, 565);
    glVertex2f(1085, 520);
    glEnd();



    glColor3f(getRGB(183), getRGB(0), getRGB(91));
    glBegin(GL_POLYGON);  //start house5
    glVertex2f(1130, 450);
    glVertex2f(1130, 650);
    glVertex2f(1230, 650);
    glVertex2f(1230, 450);
    glEnd();

    glColor3f(getRGB(121), getRGB(0), getRGB(61)); //start house5 side
    glBegin(GL_POLYGON);
    glVertex2f(1230, 450);
    glVertex2f(1230, 650);
    glVertex2f(1245, 635);
    glVertex2f(1245, 455);
    glEnd();


    glBegin(GL_POLYGON);  //start house5 door
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(1165, 450);
    glVertex2f(1165, 500);
    glVertex2f(1195, 500);
    glVertex2f(1195, 450);
    glEnd();  //end door


    glBegin(GL_POLYGON);  //start house5 window1
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(1140, 540);
    glVertex2f(1140, 570);
    glVertex2f(1175, 570);
    glVertex2f(1175, 540);
    glEnd();

    glBegin(GL_POLYGON);  //start house5 window2
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(1185, 540);
    glVertex2f(1185, 570);
    glVertex2f(1220, 570);
    glVertex2f(1220, 540);
    glEnd();

    glBegin(GL_POLYGON);  //start house5 window3
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(1140, 590);
    glVertex2f(1140, 620);
    glVertex2f(1175, 620);
    glVertex2f(1175, 590);
    glEnd();

    glBegin(GL_POLYGON);  //start house5 window4
    glColor3f(getRGB(0), getRGB(0), getRGB(0));
    glVertex2f(1185, 590);
    glVertex2f(1185, 620);
    glVertex2f(1220, 620);
    glVertex2f(1220, 590);
    glEnd();






}

void tree()
{



    glColor3f(0.9,0.2,0.0); //tree1
    glBegin(GL_POLYGON);
    glVertex2f(530,450);
    glVertex2f(530,500);
    glVertex2f(540,500);
    glVertex2f(540,450);
    glEnd();


    glColor3f(getRGB(0), getRGB(130), getRGB(0));
    glBegin(GL_POLYGON);
    glVertex2f(480,500);
    glVertex2f(535,550);
    glVertex2f(590,500);
    glEnd();

    glColor3f(getRGB(0), getRGB(130), getRGB(0));
    glBegin(GL_POLYGON);
    glVertex2f(480,550);
    glVertex2f(535,600);
    glVertex2f(590,550);
    glEnd();



     glColor3f(0.9,0.2,0.0); //tree2
    glBegin(GL_POLYGON);
    glVertex2f(770,450);
    glVertex2f(770,500);
    glVertex2f(780,500);
    glVertex2f(780,450);
    glEnd();

     glColor3f(getRGB(0), getRGB(130), getRGB(0));
    glBegin(GL_POLYGON);
    glVertex2f(720,500);
    glVertex2f(775,550);
    glVertex2f(830,500);
    glEnd();

    glColor3f(getRGB(0), getRGB(130), getRGB(0));
    glBegin(GL_POLYGON);
    glVertex2f(720,550);
    glVertex2f(775,600);
    glVertex2f(830,550);
    glEnd();











}

void darkTree(){



 glColor3f(0.9,0.2,0.0); //tree1
    glBegin(GL_POLYGON);
    glVertex2f(530,450);
    glVertex2f(530,500);
    glVertex2f(540,500);
    glVertex2f(540,450);
    glEnd();


    glColor3f(getRGB(0), getRGB(130), getRGB(0));
    glBegin(GL_POLYGON);
    glVertex2f(480,500);
    glVertex2f(535,550);
    glVertex2f(590,500);
    glEnd();

    glColor3f(getRGB(0), getRGB(130), getRGB(0));
    glBegin(GL_POLYGON);
    glVertex2f(480,550);
    glVertex2f(535,600);
    glVertex2f(590,550);
    glEnd();



     glColor3f(0.9,0.2,0.0); //tree2
    glBegin(GL_POLYGON);
    glVertex2f(770,450);
    glVertex2f(770,500);
    glVertex2f(780,500);
    glVertex2f(780,450);
    glEnd();

     glColor3f(getRGB(0), getRGB(130), getRGB(0));
    glBegin(GL_POLYGON);
    glVertex2f(720,500);
    glVertex2f(775,550);
    glVertex2f(830,500);
    glEnd();

    glColor3f(getRGB(0), getRGB(130), getRGB(0));
    glBegin(GL_POLYGON);
    glVertex2f(720,550);
    glVertex2f(775,600);
    glVertex2f(830,550);
    glEnd();










}
void grass()
{

    glColor3f(0.0,223.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,400);
    glVertex2f(0,480);
    glVertex2f(1366,480);
    glVertex2f(1366,400);
    glEnd();


}
void darkGrass()

{
    glColor3f(getRGB(75),getRGB(126),getRGB(5));
    glBegin(GL_POLYGON);
    glVertex2f(0,400);
    glVertex2f(0,480);
    glVertex2f(1366,480);
    glVertex2f(1366,400);
    glEnd();


}


void dayroad()
{
    glBegin(GL_POLYGON);
    glColor3f(getRGB(100), getRGB(101), getRGB(130));
    glVertex2f(0, 0);
    glVertex2f(0, 400);
    glVertex2f(1366, 400);
    glVertex2f(1366,0);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,15);
    glVertex2f(1366,15);
    glVertex2f(1366,0);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,385);
    glVertex2f(0,400);
    glVertex2f(1366,400);
    glVertex2f(1366,385);
    glEnd();
}

void nightroad()
{
    glBegin(GL_POLYGON);
    glColor3f(getRGB(58), getRGB(58), getRGB(58));
    glVertex2f(0, 0);
    glVertex2f(0, 400);
    glVertex2f(1366, 400);
    glVertex2f(1366,0);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0,15);
    glVertex2f(1366,15);
    glVertex2f(1366,0);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,385);
    glVertex2f(0,400);
    glVertex2f(1366,400);
    glVertex2f(1366,385);
    glEnd();
}

void signal()
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(1300,0);
    glVertex2f(1300,350);
    glVertex2f(1310,350);
    glVertex2f(1310,0);
    glEnd();


    glColor3f(0.7,0.7,0.7);
    glBegin(GL_POLYGON);
    glVertex2f(1280,350);
    glVertex2f(1280,500);
    glVertex2f(1330,500);
    glVertex2f(1330,350);
    glEnd();

    for(int l=0; l<=20; l++)
    {
        glColor3f(0.0,0.0,0.0);
        draw_circle(1305,475,l);
        glColor3f(1.0,1.0,0.0);
        draw_circle(1305,425,l);
        glColor3f(0.0,0.0,0.0);
        draw_circle(1305,375,l);
    }




    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(40,190);
    glVertex2f(40,520);
    glVertex2f(50,520);
    glVertex2f(50,190);
    glEnd();


    glColor3f(0.7,0.7,0.7);
    glBegin(GL_POLYGON);
    glVertex2f(20,470);
    glVertex2f(20,620);
    glVertex2f(70,620);
    glVertex2f(70,470);
    glEnd();

    for(int l=0; l<=20; l++)
    {
        glColor3f(0.0,0.0,0.0);
        draw_circle(45,595,l);
        glColor3f(1.0,1.0,0.0);
        draw_circle(45,548,l);
        glColor3f(0.0,0.0,0.0);
        draw_circle(45,500,l);
    }
}


void devider()
{
    glBegin(GL_POLYGON);
    glColor3f(getRGB(255), getRGB(250), getRGB(0));
    glVertex2f(0, 190);
    glVertex2f(0, 210);
    glVertex2f(1366, 210);
    glVertex2f(1366,190);
    glEnd();




    float x=50;
    float inc =50;
    for(int i=0; i<15; i++)
    {
        glColor3f(getRGB(0), getRGB(0), getRGB(0));
        glBegin(GL_POLYGON);
        glVertex2f(x, 190);
        glVertex2f(x, 210);
        glVertex2f(x+inc, 210);
        glVertex2f(x+inc,190);
        glEnd();
        x=x+100;
    }


}


void daySky()
{
    glBegin(GL_POLYGON);
    glColor3f(getRGB(141),getRGB(215), getRGB(252));
    glVertex2f(0, 400);
    glVertex2f(0, 750);
    glVertex2f(1366, 750);
    glVertex2f(1366,400);
    glEnd();

//cloud1

    for(int l=0; l<=35; l++)
    {
        glColor3f(1.0,1.0,1.0);
        draw_circle(190+m,655,l);
        draw_circle(205+m,685,l);
        draw_circle(260+m,690,l);
        draw_circle(300+m,690,l);
        draw_circle(310+m,655,l);
        draw_circle(250+m,655,l);


    }


//cloud2


    for(int l=0; l<=20; l++)
    {
        glColor3f(1.0,1.0,1.0);
        draw_circle(480+m,695,l);
        draw_circle(595+m,695,l);
    }
    for(int l=0; l<=35; l++)
    {

        glColor3f(1.0,1.0,1.0);
        draw_circle(510+m,695,l);
        draw_circle(535+m,695,l);
        draw_circle(570+m,695,l);
    }




//cloud3

    for(int l=0; l<=30; l++)
    {
        glColor3f(1.0,1.0,1.0);

        draw_circle(690+m,650,l);
        draw_circle(715+m,675,l);
        draw_circle(755+m,630,l);
        draw_circle(760+m,675,l);
        draw_circle(715+m,630,l);
        draw_circle(775+m,655,l);
        //draw_circle(750+m,655,l);


    }

//cloud4


    for(int l=0; l<=20; l++)
    {
        glColor3f(1.0,1.0,1.0);
        draw_circle(875+m,695,l);
        draw_circle(1010+m,695,l);
    }
    for(int l=0; l<=35; l++)
    {

        glColor3f(1.0,1.0,1.0);
        draw_circle(910+m,695,l);
        draw_circle(945+m,705,l);
        draw_circle(980+m,695,l);
        draw_circle(945+m,680,l);
    }



    //cloud5

    for(int l=0; l<=30; l++)
    {
        glColor3f(1.0,1.0,1.0);

        draw_circle(1090+m,700,l);
        draw_circle(1115+m,725,l);
        draw_circle(1155+m,680,l);
        draw_circle(1160+m,725,l);
        draw_circle(1115+m,680,l);
        draw_circle(1175+m,705,l);
        //draw_circle(750+m,655,l);


    }



//sun


    for(int l=0; l<=50; l++)
    {
        glColor3f(1.0,0.9,0.0);
        draw_circle(55,695,l);
    }





}


void nightSky()
{
    glBegin(GL_POLYGON);
    glColor3f(getRGB(53),getRGB(56), getRGB(74));
    glVertex2f(0, 400);
    glVertex2f(0, 750);
    glVertex2f(1366, 750);
    glVertex2f(1366,400);
    glEnd();

//moon


    for(int l=0; l<=35; l++)
    {
        glColor3f(1.0,1.0,1.0);
        draw_circle(55,695,l);
    }


//star1

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(175,703);
    glVertex2f(169,692);
    glVertex2f(181,692);
    glVertex2f(175,688);
    glVertex2f(168,698);
    glVertex2f(182,698);
    glEnd();



    //star2
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(975,743);
    glVertex2f(970,735);
    glVertex2f(980,735);
    glVertex2f(975,732);
    glVertex2f(970,740);
    glVertex2f(980,740);
    glEnd();

//star3
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(875,723);
    glVertex2f(870,715);
    glVertex2f(880,715);
    glVertex2f(875,712);
    glVertex2f(870,720);
    glVertex2f(880,720);
    glEnd();

//star4
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(345,688);
    glVertex2f(340,680);
    glVertex2f(350,680);
    glVertex2f(345,677);
    glVertex2f(340,685);
    glVertex2f(350,685);
    glEnd();

//star5
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(750,728);
    glVertex2f(745,720);
    glVertex2f(755,720);
    glVertex2f(750,718);
    glVertex2f(745,725);
    glVertex2f(755,725);
    glEnd();

//star6
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(1200,728);
    glVertex2f(1195,720);
    glVertex2f(1205,720);
    glVertex2f(1200,718);
    glVertex2f(1195,725);
    glVertex2f(1205,725);
    glEnd();

//star7
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(500,743);
    glVertex2f(495,735);
    glVertex2f(505,735);
    glVertex2f(500,732);
    glVertex2f(495,740);
    glVertex2f(505,740);
    glEnd();

//star8
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(1075,743);
    glVertex2f(1070,735);
    glVertex2f(1080,735);
    glVertex2f(1075,732);
    glVertex2f(1070,740);
    glVertex2f(1080,740);
    glEnd();

    //star9
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(245,688);
    glVertex2f(240,680);
    glVertex2f(250,680);
    glVertex2f(245,677);
    glVertex2f(240,685);
    glVertex2f(250,685);
    glEnd();

    //star8
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(1275,643);
    glVertex2f(1270,635);
    glVertex2f(1280,635);
    glVertex2f(1275,632);
    glVertex2f(1270,640);
    glVertex2f(1280,640);
    glEnd();







}


void traffic_lightRight()
{
    int l;
    if(light==1)
    {
        for(l=0; l<=20; l++)
        {

            glColor3f(0.0,1.0,0.0);
            draw_circle(1305,375,l);
        }
        for(l=0; l<=15; l++)
        {

            glColor3f(1.0,0.0,0.0);
            draw_circle(1305,475,l);

        }

    }

    else
    {

        for(l=0; l<=20; l++)
        {
            glColor3f(1.0,0.0,0.0);
            draw_circle(1305,475,l);
        }
        for(l=0; l<=15; l++)
        {

            glColor3f(0.0,1.0,0.0);
            draw_circle(1305,375,l);

        }
    }
}




void traffic_lightLeft()
{
    int l;
    if(light==1)
    {
        for(l=0; l<=20; l++)
        {

            glColor3f(0.0,1.0,0.0);
            draw_circle(45,500,l);
        }
        for(l=0; l<=15; l++)
        {

            glColor3f(1.0,0.0,0.0);
            draw_circle(45,595,l);

        }

    }

    else
    {

        for(l=0; l<=20; l++)
        {
            glColor3f(1.0,0.0,0.0);
            draw_circle(45,595,l);
        }
        for(l=0; l<=15; l++)
        {

            glColor3f(0.0,1.0,0.0);
            draw_circle(45,500,l);

        }
    }
}



void plane()
{
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(1125+n,625+o);
    glVertex2f(1150+n,640+o);
    glVertex2f(1215+n,640+o);
    glVertex2f(1230+n,650+o);
    glVertex2f(1250+n,650+o);
    glVertex2f(1210+n,625+o);
    glEnd();

    glColor3f(0.8,0.8,0.8);
    glBegin(GL_LINE_LOOP);
    glVertex2f(1125+n,625+o);
    glVertex2f(1150+n,640+o);
    glVertex2f(1215+n,640+o);
    glVertex2f(1230+n,650+o);
    glVertex2f(1250+n,650+o);
    glVertex2f(1210+n,625+o);
    glEnd();

}




void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    if (day==1)
    {
        daySky();

        dayroad();

        grass();
        tree();

        building();
    }

    else
    {
        nightSky();
        nightroad();
         darkGrass();
         darkTree();
        building();



    }

    if (nightWindowValue==1)
    {
        nightWindow();
    }

    if(planee==1)
    {
        plane();
    }
    devider();
    cars();
    signal();
    traffic_lightRight();
    traffic_lightLeft();

    glFlush();

}


void idle()
{
    glClearColor(1.0,1.0,1.0,1.0);

    if(light==0 && (i>=0 && i<=300)) //value of i when first vehicle is near the traffic-signal
    {

        i+=SPEED/20;
        ++m;

        if(planee==1)
        {
            n-=2;
            o+=0.2;
        }

    }

    if(light==0 && (i>=320 && i<=620)) //value of i when second vehicle is near the traffic-signal
    {

        i+=SPEED/20;
        ++m;
        if(planee==1)
        {
            n-=2;
            o+=0.2;
        }

    }

    if(light==0 && (i>=640 && i<=940))// value of i when third vehicle is near the traffic signal
    {

        i+=SPEED/20;
        ++m;
        if(planee==1)
        {
            n-=2;
            o+=0.2;
        }

    }

    if(light==0 && (i>=960 && i<=1300))// value of i when third vehicle is near the traffic signal
    {

        i+=SPEED/20;
        ++m;
        if(planee==1)
        {
            n-=2;
            o+=0.2;
        }

    }

    if(light==0)
    {
        i=i;
        ++m;
        if(planee==1)
        {
            n-=2;
            o+=0.2;
        }

    }

    else
    {

        i+=SPEED/20;
        ++m;
        if(planee==1)
        {
            n-=2;
            o+=0.2;
        }
    }

    if(i>1300)
        i=0.0;
    if(m>1100)
        m=0.0;
    if( o>130)
    {
        n=0;
        o=0;
        planee=0;
    }

    glutPostRedisplay();

}


void keyboardFunc( unsigned char key, int x, int y )
{
    switch( key )
    {
    case 'g':
    case 'G':
        light=1;
        break;

    case 'r':
    case 'R':
        light=0;
        break;

    case 'd':
    case 'D':
        day=1;
        break;

    case 'n':
    case 'N':
        day=0;
        break;

    case 'p':
    case 'P':
        planee=1;
        break;

    case 'w':
    case 'W':
        nightWindowValue=0;
        break;

    case 's':
    case 'S':
        nightWindowValue=1;
        break;

    };

}


void init(void)
{
    glClearColor(getRGB(141),getRGB(215), getRGB(252),0);
    glColor3f(0.0,0.0,1.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1366.0,0.0,750.0);
}




int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowSize(1366,750);
    glutInitWindowPosition(0,0);
    glutCreateWindow("My GC Program");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboardFunc);
    glutMainLoop();

    return 0;
}
