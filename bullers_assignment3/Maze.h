//
// Assignment 3 - Created by Sara Bullers on 4/25/22.
//

#ifndef ASSIGNMENT3_MAZE_H
#define ASSIGNMENT3_MAZE_H

#include <ostream>

using namespace std;

class Maze {

    // follows the format provided regarding printing the maze
    friend ostream& operator<<(ostream& out, Maze& maze);
public:
    // Maze constructor
    __attribute__((unused)) explicit Maze (string mazeFile);
    // checks if given location is clear
    bool isClear( int row, int col) const;
    // marks given location with a *
    void markAsPath(int row, int col);
    // marks given location with a + if visited
    void markAsVisited(int row, int col);
    // getters for exit row
    int getExitRow() const;
    // getters for exit col
    int getExitCol() const;

private:
    int mazeWidth = 0;
    int mazeHeight = 0;
    int exitRow = 0;
    int exitCol = 0;
    const static int MAX_SIZE = 100;
    char mazeField[MAX_SIZE][MAX_SIZE];
};

#endif //ASSIGNMENT3_MAZE_H
