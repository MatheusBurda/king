#include "LeaderboardState.h"
#include "Game.h"

using namespace SM;

LeaderboardState::LeaderboardState(InputManager* IM, Game* pG) :
Menu(IM, BACKGROUND_MAIN),
State(static_cast<StateMachine*>(pG)),
pGame(pG) {
    GM = GraphicManager::getInstance();
    Button* bt = NULL;

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, 13 * 48));
    bt->setMessage("Back to main menu");
    bt->select(true);
    vectorOfButtons.push_back(bt);

    sf::Text* text;
    for (int i = 0; i < 10; i++) {
        text = new Text();

        text->setFont(*(GM->getFont()));
        text->setCharacterSize(TEXT_SIZE);
        text->setFillColor(sf::Color::White);

        vectorOfTexts.push_back(text);
    }

    max = 0;
}

LeaderboardState::~LeaderboardState() {
    sf::Text* text = NULL;
    while (vectorOfTexts.size() != 0) {
        text = vectorOfTexts.back();
        delete (text);
        vectorOfTexts.pop_back();
    }
    vectorOfTexts.clear();
}

void LeaderboardState::update(float dt) {
    active = true;
}

/* Menu operation to render all it's objects. */
void LeaderboardState::render() {
    updateView();
    back.render();
    for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
        (*it)->render();
    for (itr = vectorOfTexts.begin(); itr != vectorOfTexts.end(); ++itr)
        GM->render(*(itr));
}

void LeaderboardState::exec() {
    if (active) {
        switch (selected) {
        case 0:
            changeState(stateID::mainMenu);
            break;
        default:
            break;
        }
    }
    active = false;
}

void LeaderboardState::resetState() {
    ifstream textFile(LEADERBOARD_TXT_PATH, ios::in);
    if (!textFile) {
        cout << "Cant Open txt on Load Map" << endl;
        exit(100);
    }

    sf::String string;
    char name[100];
    sf::Text* text;

    int score, j, count;
    for (int i = 1; i < 11; i++) {
        text = vectorOfTexts[i - 1];
        textFile >> name >> score;

        string = to_string(i);
        string += "  -  ";
        string += name;

        count = 0;
        for (j = 0; name[j] != '\0'; j++) {
            count++;
        }

        for (j = 0; j < 30 - count; j++) {
            string += '_';
        }

        string += to_string(score);

        text->setString(string);
        sf::FloatRect textRect = text->getLocalBounds();
        text->setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        text->setPosition(sf::Vector2f(GM->getWindowSize().x / 2, 48 + (i)*48));
    }

    textFile.close();
}
