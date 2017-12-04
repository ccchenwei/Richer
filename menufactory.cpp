///======================================================================
///  Project:   Richer
/// FileName:	menufactory.cpp
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#include "global.h"
#include "menu.h"
#include "menufactory.h"

MenuFactory::MenuFactory()
{
    //ctor
}

MenuFactory::~MenuFactory()
{
    //dtor
}

Menu * MenuFactory::createMenu(int type)
{
    if(type == MenuType::MENU_MAIN)     { return new MenuMain; }
    if(type == MenuType::MENU_LOAD)     { return new MenuLoad; }
    if(type == MenuType::MENU_OPTION)   { return new MenuOption; }
    if(type == MenuType::MENU_VOLUME)   { return new MenuVolume; }
    if(type == MenuType::MENU_RESOLUTION) { return new MenuResolution; }
    if(type == MenuType::MENU_PLAY)     { return new MenuPlay; }
    if(type == MenuType::MENU_SAVE)     { return new MenuSave; }
    throw "Invalid MenuType";
}
