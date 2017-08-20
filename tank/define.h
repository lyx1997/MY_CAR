#ifndef TANK_H
#define TANK_H

#include "windows.h"
#include "stdio.h"


#define GREEN			2
#define BLUE			1
#define RED				4
#define PINK			5

#define UP				1
#define LEFT			2
#define DOWN			3
#define RIGHT			4

#define HIGHSPEED		20
#define NORMALSPEED		42
#define SLOWSPEED		200	

#define CLEAN			0

COORD pos;

int showtank(int color,int direct);
int movetank(int direct);
int printrighttank();
int printlefttank();
int printuptank();
int printbigtank();
int clean(int dir);
int keyboardcontrol();
int showbullet(int color,int direct);

#endif