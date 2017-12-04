///======================================================================
///  Project:   Richer
/// FileName:	menu.cpp
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#include <iostream>
using namespace std;
#include "global.h"
#include "menu.h"
#include "game.h"

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}

void Menu::process()
{
    show();
    int input = getInput();
    processInput(input);
}

int Menu::getNumber(int intMin, int intMax) const
{
    int input;
    cin>>input;
    while(input < intMin || input > intMax) {
        cout << "The Number Is Invalid. Please Input Again:";
        cin >> input;
    }
    return input;
}

///----------------------------
void MenuMain::show() const
{
    cout << endl;
    cout << "-- Main Menu --" << endl;
    cout << "1. New" << endl;
    cout << "2. Load Record" << endl;
    cout << "3. Option" << endl;
    cout << "0. Exit" << endl;
    cout << "Your Selected:";
}

int  MenuMain::getInput() const
{
    return getNumber(0, 3);
}

void MenuMain::processInput(int input)
{
    if(input == 0) {
        Game::getGame()->setRunning(false);
    } else if(input == 1) {
        Game::getGame()->setMenuState(MenuType::MENU_PLAY);
    } else if(input == 2) {
        Game::getGame()->setMenuState(MenuType::MENU_LOAD);
    } else if(input == 3) {
        Game::getGame()->setMenuState(MenuType::MENU_OPTION);
    }
}

///----------------------------
void MenuLoad::show() const
{
    cout << endl;
    cout << "-- Load Menu --" << endl;
    cout << "1. Load Record 1" << endl;
    cout << "2. Load Record 2" << endl;
    cout << "3. Load Record 3" << endl;
    cout << "4. Load Record 4" << endl;
    cout << "5. Load Record 5" << endl;
    cout << "0. Back to MainMenu" << endl;
    cout << "Your Selected:";
}

int  MenuLoad::getInput() const
{
    return getNumber(0, 5);
}

void MenuLoad::processInput(int input)
{
    if(input == 0) {
        Game::getGame()->setMenuState(MenuType::MENU_MAIN);
    } else if(input >= 1 && input <= 5) {
        cout << "Load Record " << input << endl;
        Game::getGame()->setMenuState(MenuType::MENU_PLAY);
    }
}

///----------------------------
void MenuOption::show() const
{
    cout << endl;
    cout << "-- Option Menu --" << endl;
    cout << "1. Set Volume" << endl;
    cout << "2. Set Resolution" << endl;
    cout << "0. Back to MainMenu" << endl;
    cout << "Your Selected:";
}

int  MenuOption::getInput() const
{
    return getNumber(0, 2);
}

void MenuOption::processInput(int input)
{
    if(input == 0) {
        Game::getGame()->setMenuState(MenuType::MENU_MAIN);
    } else if(input == 1) {
        Game::getGame()->setMenuState(MenuType::MENU_VOLUME);
    } else if(input == 2) {
        Game::getGame()->setMenuState(MenuType::MENU_RESOLUTION);
    }
}
///----------------------------
void MenuVolume::show() const
{
    cout << endl;
    cout << "-- Volume Menu --" << endl;
    cout << "1. Set Volume(0-100):" << endl;
}

int  MenuVolume::getInput() const
{
    return getNumber(0, 100);
}

void MenuVolume::processInput(int input)
{
    cout << "Set Volumen to " << input << endl;
    Game::getGame()->setMenuState(MenuType::MENU_OPTION);
}
///----------------------------
void MenuResolution::show() const
{
    cout << endl;
    cout << "-- Resolution Menu --" << endl;
    cout << "1.Set Resolution(640*480)" << endl;
    cout << "2.Set Resolution(800*600)" << endl;
    cout << "3.Set Resolution(1024*768)" << endl;
    cout << "Your Selected:";
}

int  MenuResolution::getInput() const
{
    return getNumber(1, 3);
}

void MenuResolution::processInput(int input)
{
    if(input == 1) {
        cout << "Set Resolution to 640*480" << endl;
    } else if(input == 2) {
        cout << "Set Resolution to 800*600" << endl;
    } else if(input == 3) {
        cout << "Set Resolution to 1024*768" << endl;
    }
    Game::getGame()->setMenuState(MenuType::MENU_OPTION);
}

///----------------------------
void MenuPlay::show() const
{
    cout << endl;
    cout << "-- Play Menu --" << endl;
    cout << "1.Continue ..." << endl;
    cout << "2.Use Magic to" << endl;
    cout << "3.Save to" << endl;
    cout << "0.Back To MainMenu" << endl;
    cout << "Your Selected:";
}

int  MenuPlay::getInput() const
{
    return getNumber(0, 3);
}

void MenuPlay::processInput(int input)
{
    if(input == 0) {
        Game::getGame()->setMenuState(MenuType::MENU_MAIN);
    } else if(input == 1) {
        Game::getGame()->show();
        Game::getGame()->play();
        Game::getGame()->show();
        //cout << "前进一格" << endl;
    } else if(input == 2) {
        cout << "Use Magic to...." << endl;
    } else if(input == 3) {
        Game::getGame()->setMenuState(MenuType::MENU_SAVE);
    }
}
///----------------------------
void MenuSave::show() const
{
    cout << endl;
    cout << "-- Save Menu --" << endl;
    cout << "1.Save to Record 1" << endl;
    cout << "2.Save to Record 2" << endl;
    cout << "3.Save to Record 3" << endl;
    cout << "4.Save to Record 4" << endl;
    cout << "5.Save to Record 5" << endl;
    cout << "0.Back" << endl;
    cout << "Your Selected:";
}

int  MenuSave::getInput() const
{
    return getNumber(0, 5);
}

void MenuSave::processInput(int input)
{
    if(input == 0) {
        Game::getGame()->setMenuState(MenuType::MENU_PLAY);
    } else if(input >= 1 && input <= 5) {
        cout << "Save to Record " << input << endl;
    }
}
