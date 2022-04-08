// Sara Bullers
// Assignment 1 - Library


#include "Library.h"

#include <cassert>

using namespace std;


void Test1()
{
    Library libs("UWB");
    libs.AddBook("Don Quixote");
    libs.AddBook("In Search of Lost Time");
    libs.AddBook("Ulysses");
    libs.AddBook("The Odyssey");
    libs.ListAllBooks();
    // should generate already in library message and return true
    bool result = libs.IsInLibrary("The Odyssey");
    assert(result);
    // cannot add book twice, result should be false
    result = libs.AddBook("The Odyssey");
    assert(!result);

    // test remove, result should be true
    // removal at index 2 should be The Odyssey now
    // index 3 should now be nullptr
    result = libs.RemoveBook("Ulysses");
    assert(result);
    assert(libs.findBook("Ulysses") == -1);
    assert(libs.findBook("The Odyssey") == 2);

    // not in library, result should be false
    result = libs.IsInLibrary("Ulysses");
    assert(!result);

    // cannot remove twice, result should be false
    result = libs.RemoveBook("Ulysses");
    assert(!result);
}

// Testing for index out of bounds
void Test2()
{
    Library libs("UWB");
    for (int i = 0; i < 100; i++) {
        string bookName = "A Book " + to_string(i);
        libs.AddBook(bookName);
    }
    bool result = libs.AddBook("Should break");
    assert(!result);
}

// Testing if trying to remove book when library is already empty.
void Test3()
{
    Library libs("UWB");
    bool result = libs.RemoveBook("Some Book");
    assert(!result);
}

void TestAll() {
   Test1();
   Test2();
   Test3();
   cout << "Successfully completed all tests." << endl;
} 

int main() {
   TestAll(); 
   return 0;

}
