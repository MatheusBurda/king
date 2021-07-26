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
#define WIDTH 1280
#define HEIGHT 720

/* =================================================== */
/*                      PLAYER                         */
/* =================================================== */

#define PLAYER_VELOCITY 150.f
#define JUMP_VELOCITY 3000.f
#define PLAYER_LIFE 100
#define PLAYER_DAMAGE 25
#define PLAYER_WIDTH 80
#define PLAYER_HEIGHT 80
#define PLAYER_JUMP 100

/* =================================================== */
/*                        MAP                          */
/* =================================================== */

#define GRAVITY 980.f
/* =================================================== */
/*                      PLATFORM                       */
/* =================================================== */
#define PLATFORM_WIDTH 300
#define PLATFORM_HEIGHT 150
