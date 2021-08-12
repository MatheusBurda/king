#pragma once

#include "Menu.h"
#include "State.h"

class InputManager;
class Level;
class GraphicManager;

#define BACKGROUND_MAIN "./assets/Backgrounds/MenuBackground.png"
#define LEADERBOARD_TXT_PATH "./assets/Saves/Leaderboard.txt"
#define TEXT_SIZE 24

namespace SM {

class Game;

class EndGameState : public Menu, public State {
private:
    Game* pGame;
    sf::Text text;
    sf::Text gameOverText;
    GraphicManager* GM;
    InputManager* pIM;

    char nameP[30];
    sf::String nickname;

public:
    EndGameState(InputManager* IM = NULL, Game* pG = NULL);
    ~EndGameState();

    void update(float dt);
    void render();
    void resetState();
    void exec();
    void savePoints();
    void updateName();
    int getScore();
};

}
