#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

/* =================================================== */
/*                      DEFINES                        */
/* =================================================== */
/*              WINDOW AND GRAPHIC STUFF               */
/* =================================================== */

#define FRAME_RATE 60
#define HEIGHT 600
#define WIDTH 800

/* =================================================== */
/*                      PLAYER                         */
/* =================================================== */

#define PLAYER_VELOCITY 1000.f
#define JUMP_VELOCITY 3000.f
#define PLAYER_LIFE 100
#define PLAYER_DAMAGE 25
#define PLAYER_WIDTH 50
#define PLAYER_HEIGHT 50

/* =================================================== */
/*                        MAP                          */
/* =================================================== */

#define GRAVITY 980.f
/* =================================================== */
/*                      PLATFORM                       */
/* =================================================== */
#define PLATFORM_WIDTH 300
#define PLATFORM_HEIGHT 150
