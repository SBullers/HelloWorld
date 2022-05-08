
#include "Maze.h"
#include "Creature.h"
#include <iostream>
#include <cassert>


using namespace std;

// Test 1 tests the creature solving a maze using maze.txt
void test1 ()
{
    Maze maze("../maze.txt");
    Creature C (5,15);
    cout << "Creature starting location: " << C <<endl;
    cout << "Path: ";
    string s;
    s = C.Solve(maze);
    assert (s == "EEENNNNN");
    cout << s << endl;
    cout << maze;
    cout << "Test 1 passed." << endl;
}

// Test 2 tests the creature using maze0.txt
void test2()
{
    Maze maze ("../maze0.txt");
    Creature C (2,7);
    cout << "Creature starting location: " << C <<endl;
    cout << "Path: " << endl;
    string s;
    s = C.Solve(maze);
    assert (s == "ENN");
    cout << s << endl;
    cout << maze << endl;
    cout << "Test 2 passed." << endl;

}

// Test 3 tests the creature using mazeSimple.txt
void test3()
{
    Maze maze ("../mazeSimple.txt");
    Creature C (1,1);
    cout << "Creature starting location: " << C <<endl;
    cout << "Path: "<< endl;
    string s;
    s = C.Solve(maze);
    assert (s == "SSSSES");
    cout << s << endl;
    cout << maze << endl;
    cout << "Test 3 passed." << endl;
}

// Test 4 tests the creature using mazeNoExit1.txt
void test4()
{
    Maze maze ("../mazeNoExit1.txt");
    Creature C (4,4);
    cout << "Creature starting location: " << C <<endl;
    cout << "Path: " << endl;
    string s;
    s = C.Solve(maze);
    assert (s == "");
    cout << "Test 4 passed." << endl;
}

int main() {

  test1();
  test2();
  test3();
  test4();
  cout << "All tests are done. " << endl;
  return 0;

}
