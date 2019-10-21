#include <string.h>

//#include "toolbox.h"
#include "input.h"
#include "tonc_core.h"
#include "tonc_video.h"

#define BTN_PAL  5
#define CLR_UP   RGB15(27,27,29)

#define BALL_SIZE 10
#define PADDLE_WIDTH_SIZE 10
#define PADDLE_HEIGHT_SIZE 30

#define SEG_SPACE 1
#define SEG_WIDTH 3
#define TOT_SEG_WIDTH 10

// top left corner:
#define INIT_X  108
#define INIT_Y  72

#define ZERO 0x7E
#define ONE  0x30
#define TWO  0x6D
#define THREE 0x79
#define FOUR  0x33
#define FIVE  0x5B
#define SIX   0x5F
#define SEVEN 0x70
#define EIGHT 0x7F
#define NINE  0x7B


void seven_seg(u8 x, u8 y, u8 val, COLOR clr) {
    // a
    u8 ax = x + SEG_WIDTH + SEG_SPACE; 
    u8 ay = y;
    // b
    u8 bx = x + 2 * SEG_SPACE + SEG_WIDTH + TOT_SEG_WIDTH;
    u8 by = y + SEG_WIDTH + SEG_SPACE;
    // c
    u8 cx = bx;
    u8 cy = by + 2 * SEG_SPACE + SEG_WIDTH + TOT_SEG_WIDTH;
    // d
    u8 dx = ax;
    u8 dy = ay + 2 * SEG_WIDTH + 4 * SEG_SPACE + 2 * TOT_SEG_WIDTH;
    // e
    u8 ex = x;
    u8 ey = ay + 3 * SEG_SPACE + 2 * SEG_WIDTH + TOT_SEG_WIDTH;
    // f
    u8 fx = x;
    u8 fy = ay + SEG_SPACE + SEG_WIDTH;
    // g
    u8 gx = ax;
    u8 gy = ay + 2 * SEG_SPACE + SEG_WIDTH + TOT_SEG_WIDTH;

    if (0x40 & val)
        m3_rect(ax, ay, ax + TOT_SEG_WIDTH, ay + SEG_WIDTH, clr);
    if (0x20 & val)
        m3_rect(bx, by, bx + SEG_WIDTH, by + TOT_SEG_WIDTH, clr);
    if (0x10 & val)
        m3_rect(cx, cy, cx + SEG_WIDTH, cy + TOT_SEG_WIDTH, clr);
    if (0x8 & val)
        m3_rect(dx, dy, dx + TOT_SEG_WIDTH, dy + SEG_WIDTH, clr);
    if (0x4 & val)
        m3_rect(ex, ey, ex + SEG_WIDTH, ey + TOT_SEG_WIDTH, clr);
    if (0x2 & val)
        m3_rect(fx, fy, fx + SEG_WIDTH, fy + TOT_SEG_WIDTH, clr);
    if (0x1 & val)
        m3_rect(gx, gy, gx + TOT_SEG_WIDTH, gy + SEG_WIDTH, clr);
}

int main()							//******************* Left paddle is controlled: UP == UP, DOWN == DOWN *******************
{								//******************* Right paddle is controlled: LEFT == UP,  RIGHT == DOWN ******************
    int frame=0;						//******************* LEFT is Player 2, RIGHT is Player 1, First to 10 gives an end screen ******************

    REG_DISPCNT= DCNT_MODE3 | DCNT_BG2;

    u8 xcoord = INIT_X;
    u8 ycoord = INIT_Y;

    u8 xpaddleRight = M3_WIDTH-10;
    u8 ypaddleRight = M3_HEIGHT/2;

    u8 xpaddleLeft = 0;
    u8 ypaddleLeft = M3_HEIGHT/2;

    u8 ypaddleR_Change = 0;
    u8 ypaddleL_Change = 0;

    u8 xchange = 1;
    u8 ychange = 1;

    u8 right_Score = ZERO;
    u8 left_Score = ZERO;
    int stop = 0;


    while(stop == 0)
    {
        // Draw before screen refresh
	seven_seg(M3_WIDTH/5, M3_HEIGHT/8, left_Score, CLR_BLUE);		//Left Score Indicator
	seven_seg((4*M3_WIDTH)/5, (M3_HEIGHT)/8, right_Score, CLR_BLUE);	//Right Score Indicator

	m3_rect(xcoord, ycoord, xcoord + BALL_SIZE, ycoord + BALL_SIZE, CLR_LIME);	//Ball

	m3_rect(xpaddleRight, ypaddleRight, xpaddleRight + PADDLE_WIDTH_SIZE, ypaddleRight + PADDLE_HEIGHT_SIZE, CLR_RED);	//Right Paddle

	m3_rect(xpaddleLeft, ypaddleLeft, xpaddleLeft + PADDLE_WIDTH_SIZE, ypaddleLeft + PADDLE_HEIGHT_SIZE, CLR_RED);		//Left Paddle

        vid_vsync();
        if (frame % 4 != 0) {frame++; continue;} // Slow down redraws

        // Actions

        key_poll();
        if (key_hit(KEY_A)) {
            ypaddleR_Change = -1;
        }
        if (key_hit(KEY_B)) {
            ypaddleR_Change = 1;
        }
        if (key_hit(KEY_UP)) {
            ypaddleL_Change = -1;
        }
        if (key_hit(KEY_DOWN)) {
            ypaddleL_Change = 1;
        }

        // Make sure the ball stays in bounds

        if (ycoord >= M3_HEIGHT - BALL_SIZE){		//if the ball hits the bottom of screen
            ychange = -1;
        } else if (ycoord == 0) {			//if the ball hits the top of screen
            ychange = 1;
        }

	if (xcoord >= M3_WIDTH - BALL_SIZE) {				//if the ball hits right side of screen
          xchange = -1;
	    ychange = -1;
	    xcoord = INIT_X;
	    ycoord = INIT_Y;
	    
	if(left_Score == ZERO){
		left_Score = ONE;				//changing score values and stop value if  == 10
	    } else if(left_Score == ONE){
		left_Score = TWO;
	    } else if(left_Score == TWO){
		left_Score = THREE;
	    } else if(left_Score == THREE){
		left_Score = FOUR;
	    } else if(left_Score == FOUR){
		left_Score = FIVE;
	    } else if(left_Score == FIVE){
		left_Score = SIX;
	    } else if(left_Score == SIX){
		left_Score = SEVEN;
	    } else if(left_Score == SEVEN){
		left_Score = EIGHT;
	    } else if(left_Score == EIGHT){
		left_Score = NINE;
	    } else if(left_Score == NINE){
		left_Score = 10;
		stop = 1;
	    } 

        }
 
	if (xcoord + BALL_SIZE > xpaddleRight && 				//if the ball hits right paddle
	   xcoord + BALL_SIZE < xpaddleRight + PADDLE_WIDTH_SIZE &&
	   ycoord + BALL_SIZE < ypaddleRight + PADDLE_HEIGHT_SIZE &&
           ycoord + BALL_SIZE > ypaddleRight) {  
		xcoord = M3_WIDTH - PADDLE_WIDTH_SIZE - BALL_SIZE;
            	xchange = -1;
        } 

	if(xcoord == 0){						//if the ball hits left side of screen
	    xchange = 1;
	    ychange = 1;
	    xcoord = INIT_X;
	    ycoord = INIT_Y;
		if(right_Score == ZERO){
		right_Score = ONE;
	    } else if(right_Score == ONE){
		right_Score = TWO;
	    } else if(right_Score == TWO){
		right_Score = THREE;
	    } else if(right_Score == THREE){
		right_Score = FOUR;
	    } else if(right_Score == FOUR){
		right_Score = FIVE;
	    } else if(right_Score == FIVE){
		right_Score = SIX;
	    } else if(right_Score == SIX){
		right_Score = SEVEN;
	    } else if(right_Score == SEVEN){
		right_Score = EIGHT;
	    } else if(right_Score == EIGHT){
		right_Score = NINE;
	    } else if(right_Score == NINE){
		right_Score = 10;
		stop = 1;
	    } 

	} else if(xcoord < xpaddleLeft + PADDLE_WIDTH_SIZE && 		//if the ball hits the left paddle
	   xcoord > xpaddleLeft &&
	   ycoord < ypaddleLeft + PADDLE_HEIGHT_SIZE &&
           ycoord > ypaddleLeft){
		xcoord = PADDLE_WIDTH_SIZE;
		xchange = 1;
		}
	

	if(ypaddleLeft >= M3_HEIGHT - PADDLE_HEIGHT_SIZE ){		//if the left paddle hits bottom of screen
	    ypaddleL_Change = 0;
		if(key_hit(KEY_UP))
		    ypaddleL_Change = -1;
	} else if(ypaddleLeft <= 0){					//if the left paddle hit top of screen
	    ypaddleL_Change = 0;
		if(key_hit(KEY_DOWN))
		    ypaddleL_Change = 1;
	}

	if(ypaddleRight >= M3_HEIGHT - PADDLE_HEIGHT_SIZE){		//if the right paddle hits the bottom of screen
	    ypaddleR_Change = 0;
	    if(key_hit(KEY_A))
		ypaddleR_Change = -1;
	} else if(ypaddleRight <= 0){					//if the right paddle hits the top of screen
	    ypaddleR_Change = 0;
	    if(key_hit(KEY_B))
	        ypaddleR_Change = 1;
	}
        // Draw after screen refresh
        m3_fill(CLR_BLACK);

        // updates
        xcoord += xchange;
        ycoord += ychange;

	ypaddleLeft += ypaddleL_Change;
	ypaddleRight += ypaddleR_Change;
        frame++;
    }
	m3_fill(CLR_BLACK);
	if(right_Score == 10)
	{
		seven_seg(M3_WIDTH/2, M3_HEIGHT/3, 0x67, CLR_BLUE);		//"P"
		seven_seg(M3_WIDTH/2 + 20, M3_HEIGHT/3, 0x30, CLR_BLUE);	//"1"
	} if(left_Score == 10){
		seven_seg(M3_WIDTH/2, M3_HEIGHT/3, 0x67, CLR_BLUE);		//"P"
		seven_seg(M3_WIDTH/2 + 20, M3_HEIGHT/3, 0x6D, CLR_BLUE);	//"2"

	}
    return 0;
}
