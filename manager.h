///======================================================================
///  Project:   Richer
/// FileName:	manager.h
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#ifndef MANAGER_H
#define MANAGER_H

#include "global.h"

class MenuFactory;
class BlockFactory;
class Block;
class City;

class Menu;

class Manager
{
public:
    static Manager* getMgr();
    static void     releaseMgr();
private:
    static Manager* mgr;
    Manager();
    Manager(const Manager&) = delete;
    Manager(const Manager&&) = delete;
    Manager& operator=(const Manager&) = delete;
    Manager& operator=(const Manager&&) = delete;
public:
    ~Manager();
    Menu*   getMenu(int type);
    Block*  cloneBlock(int type);
    City *  createCity();
protected:
    MenuFactory*    facMenu     = nullptr;
    BlockFactory*   facBlock    = nullptr;
    Menu*           menus[MenuType::MENU_COUNT] = {nullptr};
    Block*          blocks[BlockType::BLOCK_COUNT] = { nullptr};
};

#endif // MANAGER_H
