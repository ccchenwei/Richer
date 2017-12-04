///======================================================================
///  Project:   Richer
/// FileName:	manager.cpp
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#include "manager.h"
#include "menu.h"
#include "menufactory.h"
#include "block.h"
#include "blockfactory.h"
#include "citybuilder.h"
#include "citydirector.h"

Manager* Manager::mgr = nullptr;
Manager* Manager::getMgr()
{
    if(mgr == nullptr) { mgr = new Manager; }
    return mgr;
}
void Manager::releaseMgr()
{
    delete mgr;
    mgr = nullptr;
}

Manager::Manager()
{
    //ctor
    facMenu = new MenuFactory;
    facBlock = new BlockFactory;
    for(int i = 0; i < MenuType::MENU_COUNT; ++i) {
        menus[i] = nullptr;
    }

    for(int i = 0; i < BlockType::BLOCK_COUNT; ++i) {
        blocks[i] = facBlock->createBlock(i);
    }
    /**
    blocks[BlockType::BLOCK_NORMAL] = new NormalBlock;
    blocks[BlockType::BLOCK_MONEY] = new MoneyBlock;
    blocks[BlockType::BLOCK_TRAP] = new TrapBlock;
    blocks[BlockType::BLOCK_BAR] = new BarBlock;
    */
}

Manager::~Manager()
{
    for(int i = 0; i < BlockType::BLOCK_COUNT; ++i) {
        delete blocks[i];
    }
    for(int i = 0; i < MenuType::MENU_COUNT; ++i) {
        delete menus[i];
    }
    delete facBlock;
    delete facMenu;
}

Menu* Manager::getMenu(int type)
{
    if(menus[type] == nullptr) {
        menus[type] = facMenu->createMenu(type);
    }
    return menus[type];
}

Block*  Manager::cloneBlock(int type)
{
    //return facBlock->createBlock(type);
    return blocks[type]->clone();
}

City * Manager::createCity()
{
    CityBuilder *  builder   = new NormalCityBuilder;
    CityDirector * director  = new BoxCityDirector(builder);

    director->buildCity();
    City * city = builder->getCity();

    delete director;
    delete builder;

    return city;
}
