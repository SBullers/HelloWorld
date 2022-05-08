//
// Assignment 3 - Created by Sara Bullers on 4/25/22.
//

#include "Maze.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ostream &operator<<(ostream &out, Maze &maze)
{
    for (int row = 0; row < maze.mazeHeight; ++row)
    {
        for (int col = 0; col < maze.mazeWidth; ++col)
        {
            out<<maze.mazeField[row][col];
        }
        out << endl;
    } return out;
}

__attribute__((unused)) Maze::Maze(string mazeFile)
{
    ifstream inFile;
    inFile.open(mazeFile);
    if (!inFile.is_open())
    {
        cout << "Unable to open file";
        exit(1);
    }
    inFile >> this->mazeWidth >> this->mazeHeight;
    inFile >> this->exitRow >> this->exitCol;

    string str;
    int row = 0, col = 0;
    while (getline(inFile,str))
    {
        if (str == "\r" || str == "\n" || str == "")
        {
            continue;
        }
        for (int i = 0; i < str.length(); i++)
        {
            if (i == this->mazeWidth)
            {
                break;
            }
            if (str[i] == 'x' || str[i]== ' ')
            {
                mazeField[row][col] = str[i];
                col++;
            }
        }
        row ++;
        col = 0;
    }
    inFile.close();
}

bool Maze::isClear(int row, int col) const
{
    return mazeField[row][col] == ' ';
}

void Maze::markAsPath(int row, int col)
{
    mazeField[row][col] = '*';
}

void Maze::markAsVisited(int row, int col)
{
    mazeField[row][col] = '+';
}

int Maze::getExitRow() const
{
    return exitRow;
}

int Maze::getExitCol() const
{
    return exitCol;
}




