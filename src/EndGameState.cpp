#include "EndGameState.h"
#include "Game.h"
#include "GraphicManager.h"
#include "Level.h"

using namespace SM;

EndGameState::EndGameState(InputManager* IM, Game* pG) :
Menu(IM, BACKGROUND_MAIN),
State(static_cast<StateMachine*>(pG)),
pGame(pG),
pIM(IM),
nameP("") {
    GM = GraphicManager::getInstance();

    Button* bt;
    bt = new Button(sf::Vector2f(GM->getWindowSize().x / 2.0f, GM->getWindowSize().y / 2 + 150));
    bt->setMessage("confirm");
    bt->select(true);
    vectorOfButtons.push_back(bt);

    gameOverText.setFont(*(GM->getFont()));
    gameOverText.setCharacterSize(TEXT_SIZE * 4);
    gameOverText.setFillColor(sf::Color::Black);

    gameOverText.setString("GAME OVER");
    sf::FloatRect textRect = gameOverText.getLocalBounds();
    gameOverText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    gameOverText.setPosition(sf::Vector2f(GM->getWindowSize().x / 2, (GM->getWindowSize().y / 2) - 80));

    text.setFont(*(GM->getFont()));
    text.setCharacterSize(TEXT_SIZE);
    text.setFillColor(sf::Color::White);
}

EndGameState::~EndGameState() {
}

void EndGameState::update(float dt) {
    active = true;
    updateName();
}

void EndGameState::render() {
    updateView();
    back.render();
    for (it = vectorOfButtons.begin(); it != vectorOfButtons.end(); ++it)
        (*it)->render();
    GM->render(&gameOverText);
    GM->render(&text);
}

void EndGameState::resetState() {
    pIM->deleteString();
    nickname.clear();
    strcpy(nameP, "");
}

void EndGameState::exec() {
    if (active) {
        if (nickname.getSize() > 1) {
            savePoints();
            changeState(stateID::mainMenu);
        }
        active = false;
    }
}

void EndGameState::updateName() {
    sf::String string;
    nickname = pIM->getString();
    string = "First Name: " + nickname;
    text.setString(string);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    text.setPosition(sf::Vector2f(640, 360));
}

void EndGameState::savePoints() {
    int pointsP = getScore();
    if (pointsP <= 0)
        return;

    std::string s1 = nickname;
    strcpy(nameP, "-");
    for (int i = 0; s1[i] != 32 && s1[i]!=0; i++)
        nameP[i+1] = s1[i];

        
    ifstream getFile(("./assets/Saves/Leaderboard.txt"), ios::in);

    if (!getFile) {
        cout << "ERROR TO OPEN FILE" << endl;
        abort();
    }
    char names[10][30];
    int points[10];
    int i;
    for (i = 0; i < 10; i++) {
        getFile >> names[i] >> points[i];
    }
    getFile.close();

    int min = 0, pos = 0;

    for (i = 0; i < 10; i++) {
        if (min >= points[i]) {
            min = points[i];
            pos = i;
        }
    }
    if (points[pos] <= pointsP) {
        points[pos] = pointsP;
        strcpy(names[pos], nameP);
    }
    char aux[30];
    for (i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (points[j] > points[i]) {
                strcpy(aux, names[j]);
                int ptaux = points[j];
                strcpy(names[j], names[i]);
                points[j] = points[i];
                strcpy(names[i], aux);
                points[i] = ptaux;
            }
        }
    }
    ofstream setFile;
    setFile.open("./assets/Saves/Leaderboard.txt", ios::trunc);
    if (!setFile) {
        cout << "ERROR TO OPEN FILE" << endl;
        abort();
    }
    for (i = 0; i < 10; i++)
        setFile << names[i] << ' ' << points[i] << endl;

    setFile.close();
}

int EndGameState::getScore() {
    return pGame->getPLayer1()->getPoints() + pGame->getPLayer2()->getPoints();
}