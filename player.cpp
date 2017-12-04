///======================================================================
///  Project:   Richer
/// FileName:	player.cpp
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#include "player.h"
#include "game.h"
#include "block.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::advance()
{
    //stand = stand->nextBlock(dir);
    stand = stand->nextBlock(dir);
    stand = stand->nextBlock(dir);
    stand = stand->nextBlock(dir);
}
