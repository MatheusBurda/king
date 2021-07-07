#include"stdafx.h"
#include "Player.h"
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "king++");
    Player Burda;
    Burda.setWindow(&window);



    while(1){
        window.clear();
        Burda.update();
        window.display();
    }

    return 0;
}