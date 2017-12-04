///======================================================================
///  Project:   Richer
/// FileName:	game.cpp
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#include "global.h"
#include "game.h"
#include "menu.h"
#include "manager.h"
#include "city.h"
#include "player.h"

Game * Game::game = nullptr;
Game * Game::getGame()
{
    if(game == nullptr) { game = new Game; }
    return game;
}
void Game::releaseGame()
{
    delete game;
    game = nullptr;
}

Game::Game()
    : state(State::STATE_MENU_MAIN), menustate(MenuType::MENU_MAIN)
{
    city = Manager::getMgr()->createCity();
    player = new Player;
    player->setStand(city->getBlock(0));
    player->setDir(Direction::DIR_UNKNOW);
}

Game::~Game()
{
    delete player;
    delete city;
}

///----------------------------
void Game::init()
{
}

void Game::run()
{
    running = true;
    while(running) {
        Manager::getMgr()->getMenu(menustate)->process();
    }
}

void Game::term()
{
}
void Game::show() const
{
    city->show(player);
}

void Game::play()
{
    player->advance();
}

