//
// Created by Sara Bullers on 5/10/22.
//

#ifndef BULLERS_ASSIGNMENT4_SKIPLIST_H
#define BULLERS_ASSIGNMENT4_SKIPLIST_H

#include <iostream>

using namespace std;

class SkipList {

    // display with level
    friend ostream &operator<<(ostream &os, const SkipList &list);

private:
    // private SNode
    struct SNode {
        explicit SNode(int data);
        int data;
        // link to Next SNode
        SNode *next;
        // link to Prev SNode
        SNode *prev;
        // link to up one level
        SNode *upLevel;
        // link to down one level
        SNode *downLevel;
    };

    using SNode = struct SNode;

    // Depth of SkipList
    int depth;

    // array of Depth SNode* objects as FrontGuards linking levels
    SNode **FrontGuards;

    // array of Depth SNode* objects as RearGuards linking levels
    SNode **RearGuards;

    // given a SNode, place it before the given NextNode
    static void addBefore(SNode *NewNode, SNode *NextNode);

    // return true 50% of time,
    // each node has a 50% chance of being at higher level
    bool alsoHigher() const;

public:
    // default SkipList has Depth of 1, just one doubly-linked list
    explicit SkipList(int depth = 1);

    // destructor
    virtual ~SkipList();

    // return true if successfully added, no duplicates
    bool Add(int data);

    // return true if successfully removed
    bool Remove(int data);

    // return true if found in SkipList
    bool Contains(int data);
};


#endif //BULLERS_ASSIGNMENT4_SKIPLIST_H
