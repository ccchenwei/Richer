///======================================================================
///  Project:   Richer
/// FileName:	block.h
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#ifndef BLOCK_H
#define BLOCK_H

#include "global.h"

class Block
{
public:
    Block();
    Block(const Block&);
    virtual ~Block();
    virtual const char* name() const = 0;
    virtual Block* clone() const = 0;
public:
    Block*  nextBlock(int& dir);

    Block* getNeighbor(int dir) const { return neighbors[dir]; }
    void   setNeighbor(int dir, Block* b) { neighbors[dir] = b;}
    void   setRowCol(int r, int c) { row = r; col = c;}
    int    getRow() const { return row;}
    int    getCol() const { return col;}
protected:
    int     row = 0;
    int     col = 0;
    Block* neighbors[Direction::DIR_COUNT] = {nullptr};
};

class NormalBlock: public Block
{
public:
    NormalBlock() {}
    virtual ~NormalBlock() {}
    virtual const char* name() const { return "A";}
    virtual NormalBlock* clone() const { return new NormalBlock(*this);}
};

class MoneyBlock: public Block
{
public:
    MoneyBlock() {}
    virtual ~MoneyBlock() {}
    virtual const char* name() const { return "B";}
    virtual MoneyBlock* clone() const { return new MoneyBlock(*this);}
};

class TrapBlock: public Block
{
public:
    TrapBlock() {}
    virtual ~TrapBlock() {}
    virtual const char* name() const { return "C";}
    virtual TrapBlock* clone() const { return new TrapBlock(*this);}
};

class BarBlock: public Block
{
public:
    BarBlock() {}
    virtual ~BarBlock() {}
    virtual const char* name() const { return "D";}
    virtual BarBlock* clone() const { return new BarBlock(*this);}
};

#endif // BLOCK_H
