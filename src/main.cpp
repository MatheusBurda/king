#include "GraphicManager.h"
#include "Player.h"
#include "stdafx.h"

int main() {
    GraphicManager graphicM;
   
    Player Burda;
    Burda.setWindow(graphicM.getWindow());

    while (graphicM.isWindowOpen()) {
        graphicM.clear();
        Burda.update();
        graphicM.display();
    }

    return 0;
}