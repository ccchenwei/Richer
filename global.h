///======================================================================
///  Project:   Richer
/// FileName:	global.h
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================

#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

struct State {
    static const int STATE_MENU_MAIN    = 0;
    static const int STATE_MENU_LOAD    = 1;
    static const int STATE_MENU_OPTION  = 2;
    static const int STATE_MENU_VOLUME  = 3;
    static const int STATE_MENU_RESOLUTION = 4;
    static const int STATE_MENU_PLAY    = 5;
    static const int STATE_MENU_SAVE    = 6;
    static const int STATE_MENU_COUNT   = 7;
};

struct Direction {
    static const int DIR_UNKNOW = 0;
    static const int DIR_LEFT   = 1;
    static const int DIR_UP     = 2;
    static const int DIR_RIGHT  = 3;
    static const int DIR_DOWN   = 4;
    static const int DIR_COUNT  = 5;
    static int  oppositive(int dir);
};
inline int  Direction::oppositive(int dir)
{
    if(dir == DIR_LEFT) { return DIR_RIGHT; }
    if(dir == DIR_UP) { return DIR_DOWN; }
    if(dir == DIR_RIGHT) { return DIR_LEFT; }
    if(dir == DIR_DOWN) { return DIR_UP; }
    return DIR_UNKNOW;
}

struct MenuType {
    static const int MENU_MAIN      = 0;
    static const int MENU_LOAD      = 1;
    static const int MENU_OPTION    = 2;
    static const int MENU_VOLUME    = 3;
    static const int MENU_RESOLUTION = 4;
    static const int MENU_PLAY      = 5;
    static const int MENU_SAVE      = 6;
    static const int MENU_COUNT     = 7;
};

struct BlockType {
    static const int BLOCK_NORMAL   = 0;
    static const int BLOCK_MONEY    = 1;
    static const int BLOCK_TRAP     = 2;
    static const int BLOCK_BAR      = 3;
    static const int BLOCK_COUNT    = 4;
};

#endif // GLOBAL_H_INCLUDED
