#include <iostream>

#include "SkipList.h"
#include <cassert>

using namespace std;

// test for the Add method using random numbers
void test01() {
    SkipList s (5);
    for (int i = 0; i < 20; i++)
    {
        int number = rand() % 100;
        s.Add(number);
        cout << "After adding " << number << endl;
        cout << s << endl;
    }
}

// test for Remove and Contain methods using specific numbers
void test02(){
    SkipList s (5);
    s.Add(10);
    s.Add(15);
    s.Add(35);
    s.Add(70);
    s.Add(120);
    cout << "After adding 10, 15, 35, 70, 120" << endl;
    cout << s << endl;
    s.Remove(15);
    cout << "After Removing 15 " << endl;
    cout << s << endl;
    assert(s.Contains(15) == false);
}

int main() {
    test01();
    test02();
}







