///======================================================================
///  Project:   Richer
/// FileName:	menu.h
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#ifndef MENU_H
#define MENU_H

class Game;
class Menu
{
public:
    Menu();
    virtual ~Menu();
    void process();
protected:
    virtual void show() const  = 0;
    virtual int  getInput() const = 0;
    virtual void processInput(int input) = 0;
protected:
    int getNumber(int intMin, int intMax) const;
};

class MenuMain: public Menu
{
public:
    MenuMain() {}
    virtual ~MenuMain() {}
protected:
    virtual void show() const ;
    virtual int  getInput() const;
    virtual void processInput(int input);
};

class MenuLoad: public Menu
{
public:
    MenuLoad() {}
    virtual ~MenuLoad() {}
protected:
    virtual void show() const ;
    virtual int  getInput() const;
    virtual void processInput(int input);
};

class MenuOption: public Menu
{
public:
    MenuOption() {}
    virtual ~MenuOption() {}
protected:
    virtual void show() const ;
    virtual int  getInput() const;
    virtual void processInput(int input);
};

class MenuVolume: public Menu
{
public:
    MenuVolume() {}
    virtual ~MenuVolume() {}
protected:
    virtual void show() const ;
    virtual int  getInput() const;
    virtual void processInput(int input);
};

class MenuResolution: public Menu
{
public:
    MenuResolution() {}
    virtual ~MenuResolution() {}
protected:
    virtual void show() const ;
    virtual int  getInput() const;
    virtual void processInput(int input);
};

class MenuPlay: public Menu
{
public:
    MenuPlay() {}
    virtual ~MenuPlay() {}
protected:
    virtual void show() const ;
    virtual int  getInput() const;
    virtual void processInput(int input);
};


class MenuSave: public Menu
{
public:
    MenuSave() {}
    virtual ~MenuSave() {}
protected:
    virtual void show() const ;
    virtual int  getInput() const;
    virtual void processInput(int input);
};
#endif // MENU_H
