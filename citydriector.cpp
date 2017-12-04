///======================================================================
///  Project:   Richer
/// FileName:	citydriector.cpp
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#include "citybuilder.h"
#include "citydiector.h"

CityDriector::CityDriector(CityBuilder * pBuilder)
:builder(pBuilder)
{
    //ctor
}

CityDriector::~CityDriector()
{
    //dtor
}

///----------------------------
BoxCityDirector::BoxCityDirector(CityBuilder * pBuilder)
:CityDirector(pBuilder)
{
}

void BoxCityDirector::buildCity()
{
    static const int layout[][8] = {
        {1, BlockType::BLOCK_NORMAL, 0, 0, 2, 6, 0, 0},
        {2, BlockType::BLOCK_NORMAL, 1, 0, 3, 0, 0, 1},
        {3, BlockType::BLOCK_NORMAL, 2, 0, 4, 0, 0, 2},
        {4, BlockType::BLOCK_NORMAL, 3, 0, 5, 0, 0, 3},
        {5, BlockType::BLOCK_NORMAL, 4, 0, 0, 7, 0, 4},

        {6, BlockType::BLOCK_MONEY, 0, 1, 0, 8, 1, 0},
        {7, BlockType::BLOCK_MONEY, 0, 5, 0, 9, 1, 4},

        {8, BlockType::BLOCK_TRAP, 0, 6, 0, 10, 2, 0},
        {9, BlockType::BLOCK_TRAP, 0, 7, 0, 11, 2, 4},

        {10, BlockType::BLOCK_BAR, 0, 8, 0, 12, 3, 0},
        {11, BlockType::BLOCK_BAR, 0, 9, 0, 16, 3, 4},

        {12, BlockType::BLOCK_NORMAL, 0, 10, 13, 0, 4, 0},
        {13, BlockType::BLOCK_NORMAL, 12, 0, 14, 0, 4, 1},
        {14, BlockType::BLOCK_NORMAL, 13, 0, 15, 0, 4, 2},
        {15, BlockType::BLOCK_NORMAL, 14, 0, 16, 0, 4, 3},
        {16, BlockType::BLOCK_NORMAL, 15, 11, 0, 0, 4, 4}
    };
    const int blockCount = sizeof(layout) / sizeof(int) / 8;

    for(int i = 0; i < blockCount; ++i) {
        builder->buildBlock(layout[i][1],layout[i][6], layout[i][7]);

        //Block* b = Manager::getMgr()->createBlock(layout[i][1]);
        //b->setRowCol(layout[i][6], layout[i][7]);
        //blocks.push_back(b);
    }
    for(int i = 0; i < blockCount; ++i) {
        builder->buildNeighbors(layout[i][0],layout[i][2],layout[i][3],layout[i][4],layout[i][4]);

        /**
        Block* block = blocks[i];
        if(layout[i][2] > 0) { block->setNeighbor(Direction::DIR_LEFT, blocks[layout[i][2] - 1]); }
        if(layout[i][3] > 0) { block->setNeighbor(Direction::DIR_UP, blocks[layout[i][3] - 1]); }
        if(layout[i][4] > 0) { block->setNeighbor(Direction::DIR_RIGHT, blocks[layout[i][4] - 1]); }
        if(layout[i][5] > 0) { block->setNeighbor(Direction::DIR_DOWN, blocks[layout[i][5] - 1]); }
        **/
    }
}
