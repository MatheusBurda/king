#include "NewGameState.h"

using namespace SM;

NewGameState::NewGameState(InputManager* IM, StateMachine* pSM) :
Menu(IM, BACKGROUND_MAIN_MENU),
State(pSM) {
    GraphicManager* GM = GraphicManager::getInstance();
    Button* bt = NULL;

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2));
    bt->setMessage("NOME PLAYER 1");
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 80));
    bt->setMessage("NOME PLAYER 2");
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 160));
    bt->setMessage("PLAY");
    bt->select(true);
    vectorOfButtons.push_back(bt);

    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 240));
    bt->setMessage("RETURN");
    vectorOfButtons.push_back(bt);

    selected = 2;

    max = 3;

    if (!font.loadFromFile(FONT_PATH)) {
        cout << "Error loading Font!" << endl;
        std::exit(1);
    }

    playerText.setFont(font);
    playerText.setCharacterSize(TEXT_SIZE);

    playerText.setOrigin(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 80));
    playerText.setPosition(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 80));
    playerText.setFillColor(sf::Color::White);
}

NewGameState::~NewGameState() {
}

void NewGameState::update() {
    active = true;
    /*     sf::Event event;
    if (event.type == sf::Event::TextEntered) {
        playerInput += event.text.unicode;
        playerText.setString(playerInput);
    } */
}

/* Menu operation to render all it's objects. */
void NewGameState::render() {
    back.render();
    for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
        (*it)->render();
}

void NewGameState::exec() {
    if (active) {
        switch (selected) {
        case 0:
            cout << "new PLAYER 1" << endl;
            break;
        case 1:
            cout << "new PLAYER 2" << endl;
            break;
        case 2:
            cout << "new JOGAR" << endl;
            break;
        case 3:
            changeState(stateID::mainMenu);
            break;
        default:
            break;
        }
    }
    active = false;
}
