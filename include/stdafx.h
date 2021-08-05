#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;
using std::string;

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
#define PLAYER_LIFE 200
#define PLAYER_DAMAGE 25
#define PLAYER_WIDTH 46
#define PLAYER_HEIGHT 105
#define PLAYER_JUMP 200
#define PLAYER_ATTACK 150 //Pixels that the sword hit the enemy

/* =================================================== */
/*                     ENEMY                           */
/* =================================================== */

#define ENEMY_LIFE 2000
#define ENEMY_DAMAGE 25
#define ENEMY_VELOCITYX 100 
#define ENEMY_MOTIONX_MAX 500 //max pixels that enemy identify the player
#define ENEMY_MOTIONX_MIN 200 //min pixels that enemy identify the player

/* =================================================== */
/*                     WIZARD                          */
/* =================================================== */
#define WIZARD_WIDTH 44
#define WIZARD_HEIGHT 105
/* =================================================== */
/*                     ARCHER                          */
/* =================================================== */
#define ARCHER_WIDTH 50
#define ARCHER_HEIGHT 105

/* =================================================== */
/*                        MAP                          */
/* =================================================== */

#define GRAVITY 3000.f
#define DIV0 0.0000001f //used to guarantee that the division isnt by 0

/* =================================================== */
/*                      PLATFORM                       */
/* =================================================== */

#define PLATFORM_WIDTH 45
#define PLATFORM_HEIGHT 45

/* =================================================== */
/*                      WALL                           */
/* =================================================== */

#define PLATFORM_WIDTH 45
#define PLATFORM_HEIGHT 45

/* =================================================== */
/*                      FIREBALL                       */
/* =================================================== */

#define FIREBALL_WIDTH 40
#define FIREBALL_HEIGHT 24
#define FIREBALL_VELOCITYX 400
#define FIREBALL_HMAX 200

/* =================================================== */
/*                      PROJECTILE                     */
/* =================================================== */
#define PROJECTILE_DAMAGE 50
/* =================================================== */
/*                     LAVA                            */
/* =================================================== */
#define LAVA_DAMAGE 500
/* =================================================== */
/*                     ARROW                           */
/* =================================================== */
#define ARROW_VELOCITYX 500
#define ARROW_HMAX 100