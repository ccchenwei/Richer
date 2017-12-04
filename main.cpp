#include <iostream>
using namespace std;
#include "game.h"
#include "manager.h"
int main()
{
    Game * game = Game::getGame();
    try {
        game->init();
        game->run();
        game->term();
    } catch(const char * str) {
        cout << str << endl;
    } catch(...) {
    }
    Manager::releaseMgr();
    Game::releaseGame();
    return 0;
}
