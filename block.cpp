///======================================================================
///  Project:   Richer
/// FileName:	block.cpp
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#include "block.h"

Block::Block()
{
    //ctor
}
Block::Block(const Block& )
{
    row = col = 0;
    for(int i = 0; i < Direction::DIR_COUNT; ++i) {
        neighbors[i] = nullptr;
    }
}

Block::~Block()
{
    //dtor
}

Block* Block::nextBlock(int& dir)
{
    if(dir == Direction::DIR_UNKNOW) {
        for(int i = Direction::DIR_LEFT; i < Direction::DIR_COUNT; ++i) {
            if(neighbors[i]) {
                dir = i;
                return neighbors[i];
            }
        }
    } else {
        for(int i = Direction::DIR_LEFT; i < Direction::DIR_COUNT; ++i) {
            if(neighbors[i] && i != Direction::oppositive(dir)) {
                dir = i;
                return neighbors[i];
            }
        }
    }
    throw "Invalid NextBlock";
}
