#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>



/* =================================================== */
/*                      DEFINES                        */
/* =================================================== */
/*              WINDOW AND GRAPHIC STUFF               */
/* =================================================== */

#define FRAME_RATE 100
#define WIDTH 1280
#define HEIGHT 720

/* =================================================== */
/*                      PLAYER                         */
/* =================================================== */

#define PLAYER_VELOCITY 600.f
#define JUMP_VELOCITY 3000.f
#define PLAYER_LIFE 2000000000
#define PLAYER_DAMAGE 25
#define PLAYER_WIDTH 44
#define PLAYER_HEIGHT 105
#define PLAYER_JUMP 200

/* =================================================== */
/*                     ENEMY                           */
/* =================================================== */

#define ENEMY_LIFE 1000
#define ENEMY_DAMAGE 25
#define ENEMY_WIDTH 44
#define ENEMY_HEIGHT 105

/* =================================================== */
/*                        MAP                          */
/* =================================================== */

#define GRAVITY 3000.f
#define DIV0 0.0000001f //used to guarantee that the division isnt by 0

/* =================================================== */
/*                      PLATFORM                       */
/* =================================================== */

#define PLATFORM_WIDTH 30
#define PLATFORM_HEIGHT 30


/* =================================================== */
/*                      WALL                           */
/* =================================================== */

#define PLATFORM_WIDTH 30
#define PLATFORM_HEIGHT 30


/* =================================================== */
/*                      FIREBALL                       */
/* =================================================== */

#define FIREBALL_WIDTH 40
#define FIREBALL_HEIGHT 24
#define FIREBALL_VELOCITYX 400
#define FIREBALL_HMAX 200
#define FIREBALL_DAMAGE 50