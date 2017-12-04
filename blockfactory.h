///======================================================================
///  Project:   Richer
/// FileName:	blockfactory.h
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#ifndef BLOCKFACTORY_H
#define BLOCKFACTORY_H


class BlockFactory
{
public:
    BlockFactory();
    virtual ~BlockFactory();
    virtual Block* createBlock(int type);
protected:

private:
};

#endif // BLOCKFACTORY_H
