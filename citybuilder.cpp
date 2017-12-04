///======================================================================
///  Project:   Richer
/// FileName:	citybuilder.cpp
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#include "manager.h"
#include "block.h"
#include "city.h"
#include "citybuilder.h"

CityBuilder::CityBuilder()
{
    //ctor
    city = new City;
}

CityBuilder::~CityBuilder()
{
    //dtor
}
///----------------------------
void NormalCityBuilder::buildBlock( int type, int r, int c )
{
    Block* b = Manager::getMgr()->cloneBlock( type );
    b->setRowCol( r, c );
    city->addBlock(b);
}

void NormalCityBuilder::buildNeighbors(int index,int left,int up,int right,int down)
{
    city->setNeighbors(index,left,up,right,down);
}
