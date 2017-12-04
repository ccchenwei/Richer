///======================================================================
///  Project:   Richer
/// FileName:	blockfactory.cpp
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#include "global.h"
#include "block.h"
#include "blockfactory.h"

BlockFactory::BlockFactory()
{
    //ctor
}

BlockFactory::~BlockFactory()
{
    //dtor
}
Block* BlockFactory::createBlock(int type)
{
    if(type == BlockType::BLOCK_NORMAL) { return new NormalBlock; }
    if(type == BlockType::BLOCK_MONEY)  { return new MoneyBlock; }
    if(type ==  BlockType::BLOCK_TRAP)  { return new TrapBlock; }
    if(type ==  BlockType::BLOCK_BAR)   { return new BarBlock; }
    throw "Invalid BlockType";
}
