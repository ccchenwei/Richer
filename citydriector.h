///======================================================================
///  Project:   Richer
/// FileName:	citydriector.h
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#ifndef CITYDRIECTOR_H
#define CITYDRIECTOR_H

class CityBuilder;
class CityDirector
{
public:
    CityDirector( CityBuilder * pBuilder );
    virtual ~CityDirector();
    virtual void buildCity() = 0;
protected:
    CityBuilder * builder;
};

class BoxCityDirector: public CityDirector
{
public:
    BoxCityDirector( CityBuilder * pBuilder );
    virtual ~BoxCityDirector();
    virtual void buildCity();
};
#endif // CITYDRIECTOR_H
