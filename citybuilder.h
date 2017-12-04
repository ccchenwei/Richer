///======================================================================
///  Project:   Richer
/// FileName:	citybuilder.h
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#ifndef CITYBUILDER_H
#define CITYBUILDER_H

class City;
class CityBuilder
{
public:
    CityBuilder();
    virtual ~CityBuilder();
    virtual void buildBlock(int type,int r,int c) = 0;
    virtual void buildNeighbors(int index,int left,int up,int right,int down) = 0;
    City * getCity() const { return city;}
protected:
    City * city;
};

class NormalCityBuilder: public CityBuilder
{
public:
    NormalCityBuilder(){}
    virtual ~NormalCityBuilder(){}
    virtual void buildBlock(int type,int r,int c);
    virtual void buildNeighbors(int index,int left,int up,int right,int down);
};
#endif // CITYBUILDER_H
