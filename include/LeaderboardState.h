#pragma once

#include "Menu.h"
#include "State.h"
#include <vector>

class InputManager;
class GraphicManager;

#define BACKGROUND_MAIN "./assets/Backgrounds/MenuBackground.png"
#define LEADERBOARD_TXT_PATH "./assets/Saves/Leaderboard.txt"
#define TEXT_SIZE 24

namespace SM {

class Game;

class LeaderboardState : public Menu, public State {
private:
    Game* pGame;
    std::vector<sf::Text*> vectorOfTexts;
    std::vector<sf::Text*>::iterator itr;
    GraphicManager* GM;

public:
    LeaderboardState(InputManager* IM = NULL, Game* pG = NULL);
    ~LeaderboardState();

    void update(float dt);
    void render();
    void resetState();
    void exec();
};

}
