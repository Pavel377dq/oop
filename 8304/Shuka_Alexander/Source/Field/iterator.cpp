#include "iterator.h"


GameFieldIterator::GameFieldIterator(const GameField& gameField) : gameField(gameField)
{
    this->i = 0;
    this->j = 0;
    this->width = gameField.width;
    this->height = gameField.height;
}


bool GameFieldIterator::hasNext() const
{
    if (i < gameField.height && j < gameField.width) {
        return true;
    }

    return false;
}


void GameFieldIterator::first()
{
    j = 0;
    i = 0;
}


const GameFieldIterator& operator++(GameFieldIterator& it)
{
    if (it.j + 1 < it.width) {
        ++it.j;
    }
    else {
        ++it.i;
        it.j = 0;
    }

    return it;
}


const GameFieldIterator operator++(GameFieldIterator& it, int)
{
    GameFieldIterator tmp(it);
    ++it;
    return tmp;
}


CellOfField& GameFieldIterator::operator*() const
{
    return gameField.array[i][j];
}
