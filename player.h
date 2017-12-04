///======================================================================
///  Project:   Richer
/// FileName:	player.h
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#ifndef PLAYER_H
#define PLAYER_H
#include "global.h"

class Block;

class Player
{
public:
    Player();
    virtual ~Player();
public:
    void advance();
public:
    void    setStand(Block* block)  { stand = block; }
    Block*  getStand() const        { return stand; }
    void    setDir(int d)           { dir = d; }
    int     getDir() const          { return dir; }
protected:
    Block*  stand   = nullptr;
    int     dir     = Direction::DIR_UNKNOW;
};

#endif // PLAYER_H
