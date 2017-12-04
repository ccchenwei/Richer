///======================================================================
///  Project:   Richer
/// FileName:	game.h
///     Desc:
///   Author:	ChenWei, JLU, ccchenwei@163.com
///  History:
///======================================================================
#ifndef GAME_H
#define GAME_H

class Player;
class City;
class Block;

class Game
{
public:
    static Game* getGame();
    static void  releaseGame();
private:
    static Game* game;
    Game();
    Game(const Game&) = delete;
    Game(const Game&&) = delete;
    Game& operator=(const Game&) = delete;
    Game& operator=(const Game&&) = delete;
public:
    virtual ~Game();
public:
    void init();
    void run();
    void term();
public:
    void    show() const;
    void    play();
public:
    void        setRunning(bool flag)   { running = flag;}
    void        setState(int sta)       { state = sta;}
    void        setMenuState(int sta)   { menustate = sta;}
    Player*     getPlayer() const       { return player;}
    City*       getCity() const         { return city;}
protected:
    bool        running = true;
    int         state;
    int         menustate;
    City*       city;
    Player*     player;
};

#endif // GAME_H
