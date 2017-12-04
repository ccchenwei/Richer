///======================================================================
///  Project:   Richer
/// FileName:	menufactory.h
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#ifndef MENUFACTORY_H
#define MENUFACTORY_H

class Menu;
class MenuFactory
{
public:
    MenuFactory();
    virtual ~MenuFactory();
    virtual Menu* createMenu(int type);
};

#endif // MENUFACTORY_H
