///======================================================================
///  Project:   Richer
/// FileName:	city.h
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#ifndef CITY_H
#define CITY_H
#include <vector>
using namespace std;

class Block;
class Player;
class City
{
public:
    City();
    virtual ~City();
public:
    void show( Player* player ) const;

public:
    void    addBlock( Block * b ) { blocks.push_back( b );}
    Block*  getBlock( int index ) const { return blocks[index];}
    void    setNeighbors( int index, int left, int up, int right, int down );

protected:
    vector<Block*>  blocks;
    //Block *  blocks[5];
};

#endif // CITY_H
