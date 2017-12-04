///======================================================================
///  Project:   Richer
/// FileName:	city.cpp
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#include <iostream>
using namespace std;
#include "global.h"
#include "city.h"
#include "block.h"
#include "player.h"

City::City()
{
}

City::~City()
{
    for ( Block* b : blocks ) {
        delete b;
    }
}

void City::show( Player* player ) const
{
    cout << endl;
    int r = 0;
    int c = 0;
    for ( Block* b : blocks ) {
        while ( r < b->getRow() ) {
            cout << endl;
            ++r;
            c = 0;
        }
        while ( c < b->getCol() ) {
            cout << "   ";
            ++c;
        }
        if ( player->getStand() == b ) {
            cout << "(" << b->name() << ")";
        } else {
            cout << " " << b->name() << " ";
        }
        ++c;
    }
    cout << endl;
}

void City::setNeighbors( int index, int left, int up, int right, int down )
{
    Block* block = blocks[index - 1];
    if ( left > 0 )     { block->setNeighbor( Direction::DIR_LEFT, blocks[left - 1] );  }
    if ( up > 0 )       { block->setNeighbor( Direction::DIR_UP, blocks[up - 1]);       }
    if ( right > 0 )    { block->setNeighbor( Direction::DIR_RIGHT, blocks[right - 1] );}
    if ( down > 0 )     { block->setNeighbor( Direction::DIR_DOWN, blocks[down - 1] );  }
}

/*
Block* City::nextBlock(Block* b, int& dir)
{

    for(int i = 0; i < 5; ++i) {
        if(blocks[i] == b) {
            if(dir == Direction::DIR_UNKNOW) {
                if(i == 4) {
                    dir = Direction::DIR_LEFT;
                    return blocks[3];
                } else {
                    dir = Direction::DIR_RIGHT;
                    return blocks[i + 1];
                }
            } else if(dir == Direction::DIR_LEFT) {
                if(i == 0) {
                    dir = Direction::DIR_RIGHT;
                    return blocks[1];
                } else {
                    return blocks[i - 1];
                }
            } else if(dir == Direction::DIR_RIGHT) {
                if(i == 4) {
                    dir = Direction::DIR_LEFT;
                    return blocks[3];
                } else {
                    return blocks[i + 1];
                }
            }
        }
    }

}
*/
