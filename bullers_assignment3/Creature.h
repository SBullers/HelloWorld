//
// Assignment 3 - Created by Sara Bullers on 4/25/22.
//

#ifndef ASSIGNMENT3_CREATURE_H
#define ASSIGNMENT3_CREATURE_H

#include "Maze.h"
#include <iostream>
using namespace std;

class Maze;

class Creature {

    friend ostream& operator<<(ostream& out, const Creature  &creature);

public:
    // Creature constructor
    explicit Creature(int row, int col);
    // if path is found, adds direction to beginning of string and parks its as path
    void pathFound(int row, int col, string direction, Maze &maze);
    // checks if creature is at the exit
    static bool atExit(int row, int col, const Maze& maze) ;
    // checks if creature can move forward in each direction (N,S,E,W)
    bool move(int row, int col, Maze &maze);
    // tells creature to solve the maze
    string Solve (Maze &maze);

private:
    int creatureRow;
    int creatureCol;
    string path;
};

#endif //ASSIGNMENT3_CREATURE_H
