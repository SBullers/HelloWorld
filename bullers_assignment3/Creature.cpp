//
// Assignment 3 - Created by Sara Bullers on 4/25/22.
//

#include "Creature.h"
#include <iostream>

using namespace std;

ostream &operator <<(ostream& out, const Creature &creature)
{
    out<< "(" << creature.creatureRow<< "," <<creature.creatureCol<< ")";
    return out;
}

// constructor
Creature::Creature(int row, int col)
{
    creatureRow = row;
    creatureCol = col;
}

bool Creature::move(int row, int col, Maze &maze)
{

    if (Creature::atExit(row, col, maze))
    {
        maze.markAsPath(row, col);
        return true;
    }

    maze.markAsVisited(row, col);

    // try going North
    if (maze.isClear( row-1, col))
    {
        bool found = this->move(row -1, col, maze);
        if (found)
        {
            pathFound(row, col, "N", maze);
            return found;
        }
    }
    // try going West
    if (maze.isClear(row, col -1))
    {
        bool found = this->move(row, col -1, maze);
        if (found)
        {
            pathFound(row, col-1, "W", maze);
            return found;
        }
    }

    // try going South
    if (maze.isClear(row +1, col))
    {
        bool found = this->move(row +1, col, maze);
        if (found)
        {
            pathFound(row, col, "S", maze);
            return found;
        }
    }

    // try going East
    if (maze.isClear(row, col+ 1))
    {
        bool found = this->move(row, col+1, maze);
        if (found)
        {
            pathFound(row, col, "E", maze);
            return found;
        }
    }
    return false;
}

void Creature::pathFound(int row, int col, string direction, Maze &maze)
{
    this->path.insert(0, direction);
    maze.markAsPath(row, col);
}

// checks if creature is at the exit
bool Creature::atExit(int row, int col, const Maze &maze)
{
    return (row == maze.getExitRow() && col == maze.getExitCol());
}

string Creature::Solve(Maze &maze)
{
   this->move(this->creatureRow, this->creatureCol, maze);
   return this->path;
}

