//============================================================================
// Name        : game.cpp
// Author      : Muhammad Bilal Saleem
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Dodge 'Em...
//============================================================================

#ifndef DODGE_CPP_
#define DODGE_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<fstream>
#include <sstream>
 // for basic math functions such as cos, sin, sqrt
using namespace std;
	float x = 420;
	float y = 70;
	float x2 = 360; 
	float y2 = 70;
	float xx = 70;
	float yy = 720;
	int checker[5][4][100][14][14]; 
	int uservelocity=0;
	int oppovelocity=0;
	int counter1=0;
	int counter2=0;
	int counter3=0;
	int score=0;
	int lives=3, tempscore=0;
	int displaylevel=1;
	int newgame=99;
	int condition=1, condition1=0, condition2=0, condition3=0, condition4=0, condition_for_level4=0;
	int hscore[10];
	string line;
	bool loadScore = true, saveScore = true, disableKeys = false;
	bool downrange1=true;
	bool downrange2=true;
	bool downrange3=true;
	bool downrange4=true;
	bool downrange5=true;
	bool uprange1=true;
	bool uprange2=true;
	bool uprange3=true;
	bool uprange4=true;
	bool uprange5=true;
	bool rightrange1=true;
	bool rightrange2=true;
	bool rightrange3=true;
	bool rightrange4=true;
	bool rightrange5=true;
	bool leftrange1=true;
	bool leftrange2=true;
	bool leftrange3=true;
	bool leftrange4=true;
	bool leftrange5=true;

	bool down1range1=true;
	bool down1range2=true;
	bool down1range3=true;
	bool down1range4=true;
	bool down1range5=true;
	bool up1range1=true;
	bool up1range2=true;
	bool up1range3=true;
	bool up1range4=true;
	bool up1range5=true;
	bool right1range1=true;
	bool right1range2=true;
	bool right1range3=true;
	bool right1range4=true;
	bool right1range5=true;
	bool left1range1=true;
	bool left1range2=true;
	bool left1range3=true;
	bool left1range4=true;
	bool left1range5=true;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */




int cits(string s){
	stringstream need(s);
	int x = 0;
	need >> x;
	return x;	
}

string csti(int x){
	ostringstream need;
	need << x;
	string sol = need.str();
	return sol;
}

void loading(){
	ifstream fin;
	fin.open("highscore.txt");
	int i=0;
	while(fin){
		getline(fin,line);
		if(i<10){
			hscore[i] = cits(line);
			i++;
		}
	}
	
	fin.close();
}





void savehscore()
{
DrawSquare( 0 ,0  ,840,colors[BLACK]);
DrawString(290,700,"HIGHSCORE",colors[YELLOW]);
int vertical=630;
for(int w=0;w<10;w++)
{
DrawString(330,vertical,csti(hscore[w]),colors[WHITE]);
vertical-=45;
}
}





//Defining a function to display the menu
void StartUpMenu()
{
	DrawSquare( 0 ,0  ,840,colors[BLACK]);	
	DrawString( 250, 690, "CATCH   ME   IF   YOU   CAN", colors[YELLOW]);

	DrawLine( 300 , 505 ,  490 , 505 , 10 , colors[RED] );
	DrawLine( 300 , 550 ,  490 , 550 , 10 , colors[RED] );
	DrawLine( 300 , 550 ,  300 , 505 , 10 , colors[RED] );
	DrawLine( 490 , 550 ,  490 , 505 , 10 , colors[RED] );
	DrawString( 330, 520, "  New Game", colors[WHITE]);

	DrawLine( 300 , 445 ,  490 , 445 , 10 , colors[RED] );
	DrawLine( 300 , 490 ,  490 , 490 , 10 , colors[RED] );
	DrawLine( 300 , 490 ,  300 , 445 , 10 , colors[RED] );
	DrawLine( 490 , 490 ,  490 , 445 , 10 , colors[RED] );
	DrawString( 320, 460, "   High Score", colors[WHITE]);

	DrawLine( 300 , 385 ,  490 , 385 , 10 , colors[RED] );
	DrawLine( 300 , 430 ,  490 , 430 , 10 , colors[RED] );
	DrawLine( 300 , 430 ,  300 , 385 , 10 , colors[RED] );
	DrawLine( 490 , 430 ,  490 , 385 , 10 , colors[RED] );
	DrawString( 320, 400, "       Help", colors[WHITE]);

	DrawLine( 300 , 325 ,  490 , 325 , 10 , colors[RED] );
	DrawLine( 300 , 370 ,  490 , 370 , 10 , colors[RED] );
	DrawLine( 300 , 370 ,  300 , 325 , 10 , colors[RED] );
	DrawLine( 490 , 370 ,  490 , 325 , 10 , colors[RED] );
	DrawString( 320, 340, "       Quit", colors[WHITE]);
}





void PauseMenu()
{
	DrawSquare( 0 ,0  ,840,colors[BLACK]);	
	DrawString( 250, 690, "CATCH   ME   IF   YOU   CAN", colors[YELLOW]);

	DrawLine( 300 , 505 ,  490 , 505 , 10 , colors[RED] );
	DrawLine( 300 , 550 ,  490 , 550 , 10 , colors[RED] );
	DrawLine( 300 , 550 ,  300 , 505 , 10 , colors[RED] );
	DrawLine( 490 , 550 ,  490 , 505 , 10 , colors[RED] );
	DrawString( 330, 520, "    Resume", colors[WHITE]);

	DrawLine( 300 , 445 ,  490 , 445 , 10 , colors[RED] );
	DrawLine( 300 , 490 ,  490 , 490 , 10 , colors[RED] );
	DrawLine( 300 , 490 ,  300 , 445 , 10 , colors[RED] );
	DrawLine( 490 , 490 ,  490 , 445 , 10 , colors[RED] );
	DrawString( 320, 460, "    New Game", colors[WHITE]);

	DrawLine( 300 , 385 ,  490 , 385 , 10 , colors[RED] );
	DrawLine( 300 , 430 ,  490 , 430 , 10 , colors[RED] );
	DrawLine( 300 , 430 ,  300 , 385 , 10 , colors[RED] );
	DrawLine( 490 , 430 ,  490 , 385 , 10 , colors[RED] );
	DrawString( 320, 400, "    High Score", colors[WHITE]);

	DrawLine( 300 , 325 ,  490 , 325 , 10 , colors[RED] );
	DrawLine( 300 , 370 ,  490 , 370 , 10 , colors[RED] );
	DrawLine( 300 , 370 ,  300 , 325 , 10 , colors[RED] );
	DrawLine( 490 , 370 ,  490 , 325 , 10 , colors[RED] );
	DrawString( 320, 340, "        Help", colors[WHITE]);

	DrawLine( 300 , 265 ,  490 , 265 , 10 , colors[RED] );
	DrawLine( 300 , 310 ,  490 , 310 , 10 , colors[RED] );
	DrawLine( 300 , 310 ,  300 , 265 , 10 , colors[RED] );
	DrawLine( 490 , 310 ,  490 , 265 , 10 , colors[RED] );
	DrawString( 320, 280, "        Quit", colors[WHITE]);

}







// To display the help in menu 
void help()
{
	DrawSquare( 0 ,0  ,840,colors[BLACK]);
	DrawString( 320, 780, "INSTRUCTIONS", colors[ORANGE]);
	DrawString( 50, 580, "Press  (Arrow  up)  key  to  move  upward", colors[ORANGE]);
	DrawString( 50, 540, "Press  (Arrow  down)  key  to  move  downward", colors[ORANGE]);
	DrawString( 50, 500, "Press  (Arrow  right)  key  to  move  right", colors[ORANGE]);
	DrawString( 50, 460, "Press  (Arrow  left)  key  to  move  left", colors[ORANGE]);
	DrawString( 50, 420, "Press  (P)  key  to  pause game and display menu", colors[ORANGE]);
	DrawString( 50, 380, "Press  (Space)  key  to  boost up the speed 2x", colors[ORANGE]);
	DrawString( 50, 340, "Press  (Escape)  key  to  exit game", colors[ORANGE]);
	DrawString( 380, 60, "BACK", colors[ORANGE]);
}




void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}



void savescore(){
	int temp;
	for(int m=0;m<10;m++){
		if(score>hscore[m]){
			cout<<"score is "<<score<<endl;
			hscore[m]=score;
			for(int i=0;i<10;i++)
				{		
					for(int j=i+1;j<10;j++)
					{
						if(hscore[i]<hscore[j])
						{
							temp=hscore[i];
							hscore[i]=hscore[j];
							hscore[j]=temp;
						}
					}
				}
			break;
		}
	}

	ofstream fout;
    	fout.open("highscore.txt");
	int i= 0; 
    while (fout) { 
  
	if(i<10){
         line = csti(hscore[i]); 
        fout << line << endl;
        if (i==9){
            break;
	}
	i++;
	}
    } 
	fout.close();		
}




void gameover()
{
	DrawSquare( 0 ,0  ,840,colors[BLACK]);
	DrawString( 320, 440, "GAME OVER", colors[ORANGE]);
	disableKeys = true;
	if(saveScore){
		savescore();
		saveScore = false;
	}
}

/*
 * Main Canvas drawing function.
 * */


void Level4()
{	
	// Drawing opponent car for level 4
	float width = 8; 
	float height = 5;
	float* color = colors[RED]; 
	float radius = 5.0;
	DrawRoundRect(xx,yy,width,height,color,radius); // bottom left tyre
	DrawRoundRect(xx+width*3,yy,width,height,color,radius); // bottom right tyre
	DrawRoundRect(xx+width*3,yy+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(xx,yy+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(xx, yy+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(xx+width, yy+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(xx+width*3, yy+height*2, width, height, color, radius/2); // body right rect
}


void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.
	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	// calling some functions from util.cpp file to help students
	//Square at 400,20 position
if(loadScore){
	loading();
	loadScore = false;
}

//Integer to string conversion
string str1=to_string(score);
string str2=to_string(lives);
string str3=to_string(displaylevel);





//To draw and remove food and count score
int xaxis=80;
int yaxis=80;

for (int i=0 ; i<14 ; i++) {
  for (int j=0 ; j<14 ; j++) {	
if (checker[displaylevel][lives][newgame][i][j]==0) {	
        if ((x2>=xaxis-18 && x2<=xaxis+9) && (y2>=yaxis-18 && y2<=yaxis+9 )) {
        checker[displaylevel][lives][newgame][i][j]=1;
	score+=5; tempscore+=5;    
      }
	if (checker[displaylevel][lives][newgame][i][j]==0) {
	DrawSquare( xaxis , yaxis ,10,colors[BROWN]);

	}

}
	yaxis+=50;
  }
xaxis+=50;
yaxis=80;
}





//For Head-on collision
        if ((x2>=x-40 && x2<=x+31) && (y2>=y-40 && y2<=y+31)) {	
	tempscore=0;
	lives--;
	if (lives==0) {
	condition1=1;
	}
	x2=360; y2=70;
	x=420; y=70;
	}




//To draw black food in the centre 
for (int i=330; i<=480; i=i+50)
{
	for (int j=330; j<=480; j=j+50) {
	DrawSquare( i , j ,10,colors[BLACK]);
	}
}

//For changing level
if (tempscore==900) {
tempscore=0;
displaylevel++;
	x2=360; y2=70;
	x=420; y=70;
	uservelocity=5; oppovelocity=5;

}
 	


	//Square at 250,250 position
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 
	//Display Score




//To display lives and Score
	DrawString( 700, 785, str1 , colors[ORANGE]);
	DrawString( 80, 785, "LIVES : ",colors[ORANGE]);
	DrawString( 170, 785, str2, colors[ORANGE]);
	DrawString( 350, 785, "LEVEL :", colors[ORANGE]);
	DrawString( 450, 785, str3, colors[ORANGE]);

	//Triangle at 300, 450 position
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] ); 
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//Circle at 50, 670 position
	//DrawCircle(50,670,10,colors[RED]);
	//Line from 550,50 to 550,480 with width 10
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );	

	// Drawing user car
{
	float width = 8; 
	float height = 5;
	float* color = colors[DARK_GREEN]; 
	float radius = 5.0;
	DrawRoundRect(x2,y2,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x2+width*3,y2,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x2+width*3,y2+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x2,y2+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x2, y2+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x2+width, y2+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x2+width*3, y2+height*2, width, height, color, radius/2); // body right rect
}
{	
	// Drawing opponent car
	float width = 8; 
	float height = 5;
	float* color = colors[RED]; 
	float radius = 5.0;
	DrawRoundRect(x,y,width,height,color,radius); // bottom left tyre
	DrawRoundRect(x+width*3,y,width,height,color,radius); // bottom right tyre
	DrawRoundRect(x+width*3,y+height*4,width,height,color,radius); // top right tyre
	DrawRoundRect(x,y+height*4,width,height,color,radius); // top left tyre
	DrawRoundRect(x, y+height*2, width, height, color, radius/2); // body left rect
	DrawRoundRect(x+width, y+height, width*2, height*3, color, radius/2); // body center rect
	DrawRoundRect(x+width*3, y+height*2, width, height, color, radius/2); // body right rect
}


{
	// Drawing Arena 1
	int gap_turn = 70;
	int sx = 60;
	int sy = 50;
	int swidth = 700/2 - gap_turn/2; // half width
	int sheight = 6;
	float *scolor = colors[BLUE_VIOLET];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*1, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*1, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+710, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+710, swidth, sheight, scolor); // top right
	DrawRectangle(sx-sheight*1, sy+sheight+swidth+gap_turn, sheight*1, swidth, scolor); // left up
	DrawRectangle(sx-sheight*1, sy+sheight, sheight*1, swidth, scolor); // left down


}

{
	// Drawing Arena 2
	int gap_turn = 70;
	int sx = 110;
	int sy = 100;
	int swidth = 600/2 - gap_turn/2; // half width
	int sheight = 6;
	float *scolor = colors[BLUE_VIOLET];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*1, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*1, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+610, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+610, swidth, sheight+1, scolor); // top right
	DrawRectangle(sx-sheight*1, sy+sheight+swidth+gap_turn, sheight*1, swidth, scolor); // left up
	DrawRectangle(sx-sheight*1, sy+sheight, sheight*1, swidth, scolor); // left down


}



{
	// Drawing Arena 3
	int gap_turn = 70;
	int sx = 160;
	int sy = 150;
	int swidth = 500/2 - gap_turn/2; // half width
	int sheight = 6;
	float *scolor = colors[BLUE_VIOLET];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*1, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*1, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+510, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+510, swidth, sheight+1, scolor); // top right
	DrawRectangle(sx-sheight*1, sy+sheight+swidth+gap_turn, sheight*1, swidth, scolor); // left up
	DrawRectangle(sx-sheight*1, sy+sheight, sheight*1, swidth, scolor); // left down


}


{
	// Drawing Arena 4
	int gap_turn = 70;
	int sx = 210;
	int sy = 200;
	int swidth = 400/2 - gap_turn/2; // half width
	int sheight = 6;
	float *scolor = colors[BLUE_VIOLET];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*1, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*1, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+410, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+410, swidth, sheight+1, scolor); // top right
	DrawRectangle(sx-sheight*1, sy+sheight+swidth+gap_turn, sheight*1, swidth, scolor); // left up
	DrawRectangle(sx-sheight*1, sy+sheight, sheight*1, swidth, scolor); // left down


}



{
	// Drawing Arena 5
	int gap_turn = 70;
	int sx = 260;
	int sy = 250;
	int swidth = 300/2 - gap_turn/2; // half width
	int sheight = 6;
	float *scolor = colors[BLUE_VIOLET];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*1, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*1, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+310, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+310, swidth, sheight+1, scolor); // top right
	DrawRectangle(sx-sheight*1, sy+sheight+swidth+gap_turn, sheight*1, swidth, scolor); // left up
	DrawRectangle(sx-sheight*1, sy+sheight, sheight*1, swidth, scolor); // left down


}


{
	// Drawing Arena 6
	int gap_turn = 0;
	int sx = 310;
	int sy = 300;
	int swidth = 200/2 - gap_turn/2; // half width
	int sheight = 6;
	float *scolor = colors[BLUE_VIOLET];
	DrawRectangle(sx, sy, swidth, sheight, scolor); // bottom left
	DrawRectangle(sx + swidth + gap_turn, sy, swidth, sheight, scolor); // bottom right
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight, sheight*1, swidth, scolor); // right down
	DrawRectangle(sx+swidth*2+gap_turn, sy+sheight+swidth+gap_turn, sheight*1, swidth, scolor); // right up
	DrawRectangle(sx + swidth + gap_turn, sy+210, swidth, sheight, scolor); // top left
	DrawRectangle(sx, sy+210, swidth, sheight+1, scolor); // top right
	DrawRectangle(sx-sheight*1, sy+sheight+swidth+gap_turn, sheight*1, swidth, scolor); // left up
	DrawRectangle(sx-sheight*1, sy+sheight, sheight*1, swidth, scolor); // left down
}



	if (condition==1) {
	StartUpMenu();
	}

	if (condition1==1) {
	gameover();
	}

	if (condition2==1) {
	help();	
	}

	if (condition3==1) {
	PauseMenu();
	}

	if (condition4==1) {
	savehscore();
	}

	if (condition_for_level4==1) {

	Level4();
		if ((x2>=xx-40 && x2<=xx+31) && (y2>=yy-40 && y2<=yy+31))
		{ xx=70; yy=720; x2=360; y2=70; }

	}

	glutSwapBuffers(); // do not modify this line.. or draw anything below this line}


}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */





void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
	if (x2>=120 && x2<=270 && y2>=370 && y2<=415) { 	
	x2-=50; }
	if (x2<=720 && x2>=570 && y2>=370 && y2<=415) { 	
	x2-=50; }
//	else if (x2==70 && y2>=370 && y2<=415) {
//	x2=720; y2=395; }
	}
	 if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
	if (x2>=70 && x2<=220 && y2<=415 && y2>=370) { 	
	x2+=50; }
	if (x2<=670 && x2>=520 && y2>=370 && y2<=415) { 	
	x2+=50; }
//	else if (x2==720 && y2>=370 && y2<=415) {
//	x2=70; y2=395; }
	} 
	 if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
	 if (y2<=670 && y2>=520 && x2<=410 && x2>=375) {
	 y2+=50; }
	 if (y2<=220 && y2>=70 && x2<=410 && x2>=375) {
	 y2+=50; }
//	 else if (y2==720 && x2<=410 && x2>=375) {
//	 y2=70; x2=395; }
	}
	if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
 	if (y2<=720 && y2>=570 && x2<=410 && x2>=375) {
	y2-=50; }
	if (y2<=270 && y2>=120 && x2<=410 && x2>=375) {
	y2-=50; }	
//	else if (y2==70 && x2>=375 && x2<=410) {
//	x2=395; y2=720; }
	}
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
//		exit(1);  // exit the program when escape key is pressed.
	if (condition==0) {	
	condition3=1;
	counter3++;
	uservelocity=0;
	oppovelocity=0;
		if (counter3%2==0) {
		condition3=0;
		uservelocity=5;		
		oppovelocity=5;	}
	}
	if (condition==1)
	exit(1);
	}
	

	if (key == 'b' || key == 'B')
			{
		//do something if b is pressed
		cout << "b pressed" << endl;
	}


	if (key == 32) {
	if (y2==70 && x2>80 ) {x2-=10;}
	else if (x2==70 && y2<710 ) {y2+=10;}
	else if (y2==720 && x2<710 ) {x2+=10;}
	else if (x2==720 && y2>80 ) {y2-=10;}

	else if (y2==120 && x2>130 && x2<=670) {x2-=10;}
	else if (x2==120 && y2<660 && y2>=120) {y2+=10;}
	else if (y2==670 && x2<660 && x2>=120) {x2+=10;}
	else if (x2==670 && y2>130 && y2<=670) {y2-=10;}

	else if ((y2==170 && x2>180 && x2<=620)) {x2-=10;}
	else if ((x2==170 && y2<610 && y2>=170)) {y2+=10;}
	else if ((y2==620 && x2<610 && x2>=170)) {x2+=10;}
	else if ((x2==620 && y2>180 && y2<=620)) {y2-=10;}

	else if ((y2==220 && x2>230 && x2<=570)) {x2-=10;}
	else if ((x2==220 && y2<560 && y2>=220)) {y2+=10;}
	else if ((y2==570 && x2<560 && x2>=220)) {x2+=10;}
	else if ((x2==570 && y2>230 && y2<=570)) {y2-=10;}

	else if (y2==270 && x2>280 && x2<=520) {x2-=10;}
	else if (x2==270 && y2<510 && y2>=270) {y2+=10;}
	else if (y2==520 && x2<510 && x2>=270) {x2+=10;}
	else if (x2==520 && y2>280 && y2<=520) {y2-=10;}	
	}
	

	if (key == 'p' || key == 'P') {
	uservelocity=0;
	oppovelocity=0;
	counter2++;
	condition3=1;
		if (counter2%2==0) {
		uservelocity=5;
		oppovelocity=5;
		condition3=0;
		}
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
	int smartturn;
	unsigned seed= time(0);
	srand (seed);


//			cout<<"score is "<<score<<endl;
if(!disableKeys){
//Opponent loops
if (y==70 && x<720) {x+=oppovelocity;}
else if (x==720 && y<720) {y+=oppovelocity;}
else if (y==720 && x>70) {x-=oppovelocity;}
else if (x==70 && y>70) {y-=oppovelocity;} 

if (y==120 && x>=120 && x<670) {x+=oppovelocity;}
else if (x==120 && y<=670 && y>120) {y-=oppovelocity;}
else if (y==670 && x<=670 && x>120) {x-=oppovelocity;}
else if (x==670 && y>=120 && y<670) {y+=oppovelocity;}

if (y==170 && x>=170 && x<620) {x+=oppovelocity;}
else if (x==170 && y<=620 && y>170) {y-=oppovelocity;}
else if (y==620 && x<=620 && x>170) {x-=oppovelocity;}
else if (x==620 && y>=170 && y<620) {y+=oppovelocity;}

if (y==220 && x>=220 && x<570) {x+=oppovelocity;}
else if (x==220 && y<=570 && y>220) {y-=oppovelocity;}
else if (y==570 && x<=570 && x>220) {x-=oppovelocity;}
else if (x==570 && y>=220 && y<570) {y+=oppovelocity;}

if (y==270 && x>=270 && x<520) {x+=oppovelocity;}
else if (x==270 && y<=520 && y>270) {y-=oppovelocity;}
else if (y==520 && x<=520 && x>270) {x-=oppovelocity;}
else if (x==520 && y>=270 && y<520) {y+=oppovelocity;}




//SMART COMPUTER

// For bottom ranges
	if (x<=410 && x>=375 && y==70 && downrange1) {
	const int MIN_VALUE=70; const int MAX_VALUE=71;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==71) {
			y=120; }
		else if (smartturn==70) {
		    y=70;}
	downrange2=false;
	}
	
	if (x<=410 && x>=375 && y==120 && downrange2) {
	const int MIN_VALUE=70; const int MAX_VALUE=72;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==70) {
			y=70; }
		else if (smartturn==71) {
		    y=120;}
		else if (smartturn==72) {
		    y=170;}
	downrange3=false;
	downrange1=false;
	}

	if (x<=410 && x>=375 && y==170 && downrange3) {
	const int MIN_VALUE=71; const int MAX_VALUE=73;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==71) {
		y=120; }
		else if (smartturn==72) {
		    y=170;}
		else if (smartturn==73) {
	    y=220;}
	downrange4=false;
	downrange2=false;
	}

	if (x<=410 && x>=375 && y==220 && downrange4) {
	const int MIN_VALUE=72; const int MAX_VALUE=74;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
	if (smartturn==72) {
			y=170; }
		else if (smartturn==73) {
		    y=220;}
	else if (smartturn==74) {
		    y=270;}
	downrange5=false;
	downrange3=false;
	}
	
	if (x<=410 && x>=375 && y==270 && downrange5) {
	const int MIN_VALUE=74; const int MAX_VALUE=75;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
	if (smartturn==74) {
			y=220; }
		else if (smartturn==75) {
		    y=270;}
	downrange4=false;
	}
	

	
	
	if (y<=720 && y>=520 && x<=442 && x>=375) {
	downrange1=true;
	downrange2=true;
	downrange3=true;
	downrange4=true;
	downrange5=true;
	}

	
	
	
	
	//For top ranges 
	if (x<=410 && x>=375 && y==720 && uprange1) {
	const int MIN_VALUE=79; const int MAX_VALUE=80;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
	if (smartturn==80) {
			y=720; }
		else if (smartturn==79) {
		    y=670;}
	uprange2=false;
	}

	if (x<=410 && x>=375 && y==670 && uprange2) {
	const int MIN_VALUE=78; const int MAX_VALUE=80;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==80) {
			y=720; }
		else if (smartturn==79) {
	    y=670;}
		else if (smartturn==78) {
		    y=620;}
	uprange1=false;
	uprange3=false;
	}
	
	if (x<=410 && x>=375 && y==620 && uprange3) {
	const int MIN_VALUE=77; const int MAX_VALUE=79;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==79) {
			y=670; }
		else if (smartturn==78) {
		    y=620;}
		else if (smartturn==77) {
		    y=570;}
	
	uprange2=false;
	uprange4=false;
	}
	
	if (x<=410 && x>=375 && y==570 && uprange4) {
	const int MIN_VALUE=76; const int MAX_VALUE=78;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==78) {
			y=620; }
		else if (smartturn==77) {
		    y=570;}
		else if (smartturn==76) {
		    y=520;}
	uprange5=false;
	uprange3=false;
	}
	
	if (x<=410 && x>=375 && y==520 && uprange5) {
	const int MIN_VALUE=76; const int MAX_VALUE=77;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==77) {
			y=570; }
		else if (smartturn==76) {
		    y=520;}
	uprange4=false;
	}
	
	

	 if (y<=720 && y>=520 && x<=410 && x>=375) {
	uprange1=true;
	uprange2=true;
	uprange3=true;
	uprange4=true;
	uprange5=true;
	}	





// User loops
	if (y2==70 && x2>70 ) {x2-=uservelocity;}
	else if (x2==70 && y2<720 ) {y2+=uservelocity;}
	else if (y2==720 && x2<720 ) {x2+=uservelocity;}
	else if (x2==720 && y2>70 ) {y2-=uservelocity;}

	if (y2==120 && x2>120 && x2<=670) {x2-=uservelocity;}
	else if (x2==120 && y2<670 && y2>=120) {y2+=uservelocity;}
	else if (y2==670 && x2<670 && x2>=120) {x2+=uservelocity;}
	else if (x2==670 && y2>120 && y2<=670) {y2-=uservelocity;}

	if ((y2==170 && x2>170 && x2<=620)) {x2-=uservelocity;}
	else if ((x2==170 && y2<620 && y2>=170)) {y2+=uservelocity;}
	else if ((y2==620 && x2<620 && x2>=170)) {x2+=uservelocity;}
	else if ((x2==620 && y2>170 && y2<=620)) {y2-=uservelocity;}

	if ((y2==220 && x2>220 && x2<=570)) {x2-=uservelocity;}
	else if ((x2==220 && y2<570 && y2>=220)) {y2+=uservelocity;}
	else if ((y2==570 && x2<570 && x2>=220)) {x2+=uservelocity;}
	else if ((x2==570 && y2>220 && y2<=570)) {y2-=uservelocity;}

	if (y2==270 && x2>270 && x2<=520) {x2-=uservelocity;}
	else if (x2==270 && y2<520 && y2>=270) {y2+=uservelocity;}
	else if (y2==520 && x2<520 && x2>=270) {x2+=uservelocity;}
	else if (x2==520 && y2>270 && y2<=520) {y2-=uservelocity;}	

}


// For Level2
if (displaylevel==2 || displaylevel==3) {

	if (displaylevel==3) {
//	oppovelocity=10;
	if (y==720 && x>80 ) {x-=10;}
	else if (x==720 && y<710 ) {y+=10;}
	else if (y==70 && x<710 ) {x+=10;}
	else if (x==70 && y>80 ) {y-=10;}

	else if (y==670 && x>130 && x<=670) {x-=10;}
	else if (x==670 && y<660 && y>=120) {y+=10;}
	else if (y==120 && x<660 && x>=120) {x+=10;}
	else if (x==120 && y>130 && y<=670) {y-=10;}

	else if ((y==620 && x>180 && x<=620)) {x-=10;}
	else if ((x==620 && y<610 && y>=170)) {y+=10;}
	else if ((y==170 && x<610 && x>=170)) {x+=10;}
	else if ((x==170 && y>180 && y<=620)) {y-=10;}

	else if ((y==570 && x>230 && x<=570)) {x-=10;}
	else if ((x==570 && y<560 && y>=220)) {y+=10;}
	else if ((y==220 && x<560 && x>=220)) {x+=10;}
	else if ((x==220 && y>230 && y<=570)) {y-=10;}

	else if (y==520 && x>280 && x<=520) {x-=10;}
	else if (x==520 && y<510 && y>=270) {y+=10;}
	else if (y==270 && x<510 && x>=270) {x+=10;}
	else if (x==270 && y>280 && y<=520) {y-=10;}	


	}

		// For right ranges
	if (y<=415 && y>=375 && x==70 && rightrange1) {
	const int MIN_VALUE=70; const int MAX_VALUE=71;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==71) {
			x=120; }
		else if (smartturn==70) {
		    x=70;}
	rightrange2=false;
	}

	if (y<=415 && y>=375 && x==120 && rightrange2) {
	const int MIN_VALUE=70; const int MAX_VALUE=72;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==70) {
			x=70; }
		else if (smartturn==71) {
		    x=120;}
		else if (smartturn==72) {
		    x=170;}
	rightrange3=false;
	rightrange1=false;
	}
	
	if (y<=415 && y>=375 && x==170 && rightrange3) {
	const int MIN_VALUE=71; const int MAX_VALUE=73;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==71) {
			x=120; }
		else if (smartturn==72) {
		    x=170;}
		else if (smartturn==73) {
		    x=220;}
	rightrange4=false;
	rightrange2=false;
	}
	
	if (y<=415 && y>=375 && x==220 && rightrange4) {
	const int MIN_VALUE=72; const int MAX_VALUE=74;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==72) {
			x=170; }
		else if (smartturn==73) {
		    x=220;}
		else if (smartturn==74) {
	    x=270;}
	rightrange5=false;
	rightrange3=false;
	}
	
	if (y<=415 && y>=375 && x==270 && rightrange5) {
	const int MIN_VALUE=74; const int MAX_VALUE=75;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==74) {
			x=220; }
		else if (smartturn==75) {
		    x=270;}
	rightrange4=false;
	}
	
		if (x>=520 && x<=720 && y<=415 && y>=370) { 	
		rightrange1=true;
		rightrange2=true;
		rightrange3=true;
		rightrange4=true;
		rightrange5=true;
		}
	
	
	
	
	// For left ranges
	if (y<=415 && y>=375 && x==720 && leftrange1) {
	const int MIN_VALUE=79; const int MAX_VALUE=80;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
		cout<<smartturn<<endl;
		if (smartturn==80) {
			x=720; }
		else if (smartturn==79) {
		    x=670;}
	leftrange2=false;
	}

		if (y<=415 && y>=375 && x==670 && leftrange2) {
	const int MIN_VALUE=78; const int MAX_VALUE=80;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==80) {
			x=720; }
		else if (smartturn==79) {
		    x=670;}
		else if (smartturn==78) {
		    x=620;}
	leftrange1=false;
	leftrange3=false;
	}
	
	if (y<=415 && y>=375 && x==620 && leftrange3) {
	const int MIN_VALUE=77; const int MAX_VALUE=79;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==79) {
			x=670; }
		else if (smartturn==78) {
		    x=620;}
		else if (smartturn==77) {
	    x=570;}

	leftrange2=false;
	leftrange4=false;
	}

	if (y<=415 && y>=375 && x==570 && leftrange4) {
	const int MIN_VALUE=76; const int MAX_VALUE=78;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==78) {
			x=620; }
		else if (smartturn==77) {
		    x=570;}
		else if (smartturn==76) {
		    x=520;}
	leftrange5=false;
	leftrange3=false;
	}
	
	if (y<=415 && y>=375 && x==520 && leftrange5) {
	const int MIN_VALUE=76; const int MAX_VALUE=77;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
	if (smartturn==77) {
		x=570; }
	else if (smartturn==76) {
	    x=520;}
	leftrange4=false;
	}

		if (x>=70 && x<=270 && y<=415 && y>=370) { 	
		leftrange1=true;
		leftrange2=true;
		leftrange3=true;
		leftrange4=true;
		leftrange5=true;
		}
}



if (displaylevel==4) {
condition_for_level4=1;






if (yy==70 && xx<720) {xx+=oppovelocity;}
else if (xx==720 && yy<720) {yy+=oppovelocity;}
else if (yy==720 && xx>70) {xx-=oppovelocity;}
else if (xx==70 && yy>70) {yy-=oppovelocity;} 

if (yy==120 && xx>=120 && xx<670) {xx+=oppovelocity;}
else if (xx==120 && yy<=670 && yy>120) {yy-=oppovelocity;}
else if (yy==670 && xx<=670 && xx>120) {xx-=oppovelocity;}
else if (xx==670 && yy>=120 && yy<670) {yy+=oppovelocity;}

if (yy==170 && xx>=170 && xx<620) {xx+=oppovelocity;}
else if (xx==170 && yy<=620 && yy>170) {yy-=oppovelocity;}
else if (yy==620 && xx<=620 && xx>170) {xx-=oppovelocity;}
else if (xx==620 && yy>=170 && yy<620) {yy+=oppovelocity;}

if (yy==220 && xx>=220 && xx<570) {xx+=oppovelocity;}
else if (xx==220 && yy<=570 && yy>220) {yy-=oppovelocity;}
else if (yy==570 && xx<=570 && xx>220) {xx-=oppovelocity;}
else if (xx==570 && yy>=220 && yy<570) {yy+=oppovelocity;}

if (yy==270 && xx>=270 && xx<520) {xx+=oppovelocity;}
else if (xx==270 && yy<=520 && yy>270) {yy-=oppovelocity;}
else if (yy==520 && xx<=520 && xx>270) {xx-=oppovelocity;}
else if (xx==520 && yy>=270 && yy<520) {yy+=oppovelocity;}

	if (xx<=410 && xx>=375 && yy==70 && down1range1) {
	const int MIN_VALUE=70; const int MAX_VALUE=71;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==71) {
			yy=120; }
		else if (smartturn==70) {
		    yy=70;}
	down1range2=false;
	}
	
	if (xx<=410 && xx>=375 && yy==120 && down1range2) {
	const int MIN_VALUE=70; const int MAX_VALUE=72;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==70) {
			yy=70; }
		else if (smartturn==71) {
		    yy=120;}
		else if (smartturn==72) {
		    yy=170;}
	down1range3=false;
	down1range1=false;
	}

	if (xx<=410 && xx>=375 && yy==170 && down1range3) {
	const int MIN_VALUE=71; const int MAX_VALUE=73;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==71) {
		yy=120; }
		else if (smartturn==72) {
		    yy=170;}
		else if (smartturn==73) {
	    yy=220;}
	down1range4=false;
	down1range2=false;
	}

	if (xx<=410 && xx>=375 && yy==220 && down1range4) {
	const int MIN_VALUE=72; const int MAX_VALUE=74;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
	if (smartturn==72) {
			yy=170; }
		else if (smartturn==73) {
		    yy=220;}
	else if (smartturn==74) {
		    yy=270;}
	down1range5=false;
	down1range3=false;
	}
	
	if (xx<=410 && xx>=375 && yy==270 && down1range5) {
	const int MIN_VALUE=74; const int MAX_VALUE=75;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
	if (smartturn==74) {
			yy=220; }
		else if (smartturn==75) {
		    yy=270;}
	down1range4=false;
	}
	

	
	
	if (yy<=720 && yy>=520 && xx<=442 && xx>=375) {
	down1range1=true;
	down1range2=true;
	down1range3=true;
	down1range4=true;
	down1range5=true;
	}

	
	
	
	
	//For top ranges 
	if (xx<=410 && xx>=375 && yy==720 && up1range1) {
	const int MIN_VALUE=79; const int MAX_VALUE=80;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
	if (smartturn==80) {
			yy=720; }
		else if (smartturn==79) {
		    yy=670;}
	up1range2=false;
	}

	if (xx<=410 && xx>=375 && yy==670 && up1range2) {
	const int MIN_VALUE=78; const int MAX_VALUE=80;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==80) {
			yy=720; }
		else if (smartturn==79) {
	    yy=670;}
		else if (smartturn==78) {
		    yy=620;}
	up1range1=false;
	up1range3=false;
	}
	
	if (xx<=410 && xx>=375 && yy==620 && up1range3) {
	const int MIN_VALUE=77; const int MAX_VALUE=79;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==79) {
			yy=670; }
		else if (smartturn==78) {
		    yy=620;}
		else if (smartturn==77) {
		    yy=570;}
	
	up1range2=false;
	up1range4=false;
	}
	
	if (xx<=410 && xx>=375 && yy==570 && up1range4) {
	const int MIN_VALUE=76; const int MAX_VALUE=78;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==78) {
			yy=620; }
		else if (smartturn==77) {
		    yy=570;}
		else if (smartturn==76) {
		    yy=520;}
	up1range5=false;
	up1range3=false;
	}
	
	if (xx<=410 && xx>=375 && yy==520 && up1range5) {
	const int MIN_VALUE=76; const int MAX_VALUE=77;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==77) {
			yy=570; }
		else if (smartturn==76) {
		    yy=520;}
	up1range4=false;
	}
	
	

	 if (yy<=670 && yy>=520 && xx<=410 && xx>=375) {
	up1range1=true;
	up1range2=true;
	up1range3=true;
	up1range4=true;
	up1range5=true;
	}	

		// For right ranges
	if (yy<=415 && yy>=375 && xx==70 && right1range1) {
	const int MIN_VALUE=70; const int MAX_VALUE=71;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==71) {
			xx=120; }
		else if (smartturn==70) {
		    xx=70;}
	right1range2=false;
	}

	if (yy<=415 && yy>=375 && xx==120 && right1range2) {
	const int MIN_VALUE=70; const int MAX_VALUE=72;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==70) {
			xx=70; }
		else if (smartturn==71) {
		    xx=120;}
		else if (smartturn==72) {
		    xx=170;}
	right1range3=false;
	right1range1=false;
	}
	
	if (yy<=415 && yy>=375 && xx==170 && right1range3) {
	const int MIN_VALUE=71; const int MAX_VALUE=73;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==71) {
			xx=120; }
		else if (smartturn==72) {
		    xx=170;}
		else if (smartturn==73) {
		    xx=220;}
	right1range4=false;
	right1range2=false;
	}
	
	if (yy<=415 && yy>=375 && xx==220 && right1range4) {
	const int MIN_VALUE=72; const int MAX_VALUE=74;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==72) {
			xx=170; }
		else if (smartturn==73) {
		    xx=220;}
		else if (smartturn==74) {
	    xx=270;}
	right1range5=false;
	right1range3=false;
	}
	
	if (yy<=415 && yy>=375 && xx==270 && right1range5) {
	const int MIN_VALUE=74; const int MAX_VALUE=75;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==74) {
			xx=220; }
		else if (smartturn==75) {
		    xx=270;}
	right1range4=false;
	}
	
		if (xx>=520 && xx<=720 && yy<=415 && yy>=370) { 	
		right1range1=true;
		right1range2=true;
		right1range3=true;
		right1range4=true;
		right1range5=true;
		}
	
	
	
	
	// For left ranges
	if (yy<=415 && yy>=375 && xx==720 && left1range1) {
	const int MIN_VALUE=79; const int MAX_VALUE=80;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
		cout<<smartturn<<endl;
		if (smartturn==80) {
			xx=720; }
		else if (smartturn==79) {
		    xx=670;}
	left1range2=false;
	}

		if (yy<=415 && yy>=375 && xx==670 && left1range2) {
	const int MIN_VALUE=78; const int MAX_VALUE=80;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==80) {
			xx=720; }
		else if (smartturn==79) {
		    xx=670;}
		else if (smartturn==78) {
		    xx=620;}
	left1range1=false;
	left1range3=false;
	}
	
	if (yy<=415 && yy>=375 && xx==620 && left1range3) {
	const int MIN_VALUE=77; const int MAX_VALUE=79;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==79) {
			xx=670; }
		else if (smartturn==78) {
		    xx=620;}
		else if (smartturn==77) {
	    xx=570;}

	left1range2=false;
	left1range4=false;
	}

	if (yy<=415 && yy>=375 && xx==570 && left1range4) {
	const int MIN_VALUE=76; const int MAX_VALUE=78;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
		if (smartturn==78) {
			xx=620; }
		else if (smartturn==77) {
		    xx=570;}
		else if (smartturn==76) {
		    xx=520;}
	left1range5=false;
	left1range3=false;
	}
	
	if (yy<=415 && yy>=375 && xx==520 && left1range5) {
	const int MIN_VALUE=76; const int MAX_VALUE=77;  
	smartturn=(rand()%(MAX_VALUE-MIN_VALUE+1))+MIN_VALUE;
	cout<<smartturn<<endl;
	if (smartturn==77) {
		xx=570; }
	else if (smartturn==76) {
	    xx=520;}
	left1range4=false;
	}

		if (xx>=70 && xx<=270 && yy<=415 && yy>=370) { 	
		left1range1=true;
		left1range2=true;
		left1range3=true;
		left1range4=true;
		left1range5=true;
		}

}







glutPostRedisplay();

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc((500.0/FPS), Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x3, int y3) {
//cout <<"Mouse is here x "<< x3 <<endl;
//cout<< "Mouse is here y " << y3 << endl;
	glutPostRedisplay();
}
void MouseMoved(int x4, int y4) {
//	cout << x4 << " " << y4 << endl;



	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */



void MouseClicked(int button, int state, int x5, int y5) {
cout<<x5<<" click  "<<y5<<endl;
	if (button == GLUT_LEFT_BUTTON) { // dealing only with left button			 
		if (x5>=305 && x5<=483 && y5>=250 && y5<=278 && condition==1) // For StartUpMenu
	        {
		  condition=0; 
		  uservelocity=5;
		  oppovelocity=5;
		}
		if (x5>=305 && x5<=483 && y5>=250 && y5<=278 && condition3==1) // To resume game in PauseMenu
	        {
		  condition3=0; 
		  uservelocity=5;
		  oppovelocity=5;
		}
		if (x5>=305 && x5<=483 && y5>=300 && y5<=325 && condition3==1) // For New Game in PauseMenu
		{
		condition3=0;
		score=0;
		displaylevel=1;
		lives=3;
		x2=360; y2=70, uservelocity=5;
		x=420; y=70, oppovelocity=5;
		newgame--;
		}

		 if ((x5>=305 && x5<=475) && (y5>=405 && y2<=425) && (condition==1 && condition2==0)) // For StartUpMenu
		{
		  exit(1);
		}
		 if (x5>=306 && x5<=483 && y5>=352 && y5<=375 && condition==1) {   //Help for StartUpMenu
		  condition2=1; }
		 if (x5>=380 && x5<=449 && y5>=639 && y5<=660 && condition2==1) {  //Exit for StartUpMenu
		  condition2=0; }
		 if (x5<=485 && x5>=305 && y5<=328 && y5>=301 && condition==1) { // High Score for StartUpMenu
		  condition4=1; }
		 if (x5<=485 && x5>=305 && y5>=350 && y5<=375 && condition3==1 && condition==0) { // High Score for PauseMenu
		  condition3=0;
		  condition4=1; }
		 if (x5>=306 && x5<=483 && y5>=400 && y5<=425 && condition3==1) {   //Help for PauseMenu
		  condition2=1; }
 		 if (x5>=306 && x5<=485 && y5>=450 && y5<=475 && condition3==1) {  //Exit for PauseMenu
	          exit(1); }		 
	
	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}


/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	//b = new Board(60, 60); // create a new board object to use in the Display Function ...

	int width = 840, height = 840; // i have set my window size to be 800 x 600
	//b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("CATCH ME IF YOU CAN"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse


	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */

