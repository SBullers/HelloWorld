//
// Created by Sara Bullers on 5/10/22.
//

#include <climits>
#include <cstdlib>
#include <iostream>

#include "SkipList.h"
#include <cassert>

using namespace std;

ostream &operator<<(ostream &os, const SkipList &list) {
    //loop to output every level
    for(int i=list.depth-1;i>=0;i--){
        os<<"Level: "<<i<<" -- ";

        SkipList::SNode *node=list.FrontGuards[i];
        //loop to output this level
        while(node!= nullptr){
            if(node->next == nullptr)
            {
                os<<node->data;
            } else
            {
                os<<node->data<<", ";
            }

            node=node->next;
        }
        os<<endl;
    }
    return os;
}

SkipList::SNode::SNode(int data) {
    this->data=data;

    this->next= nullptr;
    // link to Prev SNode
    this->prev= nullptr;
    // link to up one level
    this->upLevel= nullptr;
    // link to down one level
    this->downLevel= nullptr;
}

SkipList::SkipList(int depth) {
    this->depth=depth;

    //allocate space for skiplist
    this->FrontGuards=new SNode *[depth];
    this->RearGuards=new SNode *[depth];

    int i;
    //loop to initialize the skiplist
    for(i=0;i<depth;i++){
        this->FrontGuards[i]=new SNode(INT_MIN);
        this->RearGuards[i]=new SNode(INT_MAX);
        this->FrontGuards[i]->next=this->RearGuards[i];
        this->RearGuards[i]->prev=this->FrontGuards[i];

        //link to the downlevel
        if(i>0){
            this->FrontGuards[i]->downLevel=this->FrontGuards[i-1];
            this->FrontGuards[i-1]->upLevel=this->FrontGuards[i];
            this->RearGuards[i]->downLevel=this->RearGuards[i-1];
            this->RearGuards[i-1]->upLevel=this->RearGuards[i];
        }
    }

    this->FrontGuards[0]->downLevel= nullptr;
    this->FrontGuards[depth-1]->upLevel= nullptr;
    this->RearGuards[0]->downLevel= nullptr;
    this->RearGuards[depth-1]->upLevel= nullptr;
}

bool SkipList::alsoHigher() const {
    int number = rand() % 2;

    //50% chance to add to higher level
    if(number==1)
        return  true;

    return false;
}

bool SkipList::Add(int data) {
    SNode *nextNode=FrontGuards[0]->next;

    //As long as nextNode->next is not null and nextNode->data < data, keep moving nextNode to the right
    while(nextNode->next!= nullptr && nextNode->data < data)
        nextNode=nextNode->next;

    //if duplicate
    if(nextNode->data == data)
        return false;

    //create the node
    SNode *newNode=new SNode(data);
    //add before nextNode
    addBefore(newNode, nextNode);

    int count=1;
    while(count<depth){
        if(alsoHigher()){//add to upper list
            SNode *newUpper=new SNode(data);
            newUpper->downLevel=newNode;
            newNode->upLevel=newUpper;

            SNode *node=newNode->prev;
            //get the last node uplevel
            while(node->upLevel == nullptr)
                node=node->prev;
            node=node->upLevel;

            //add newUpper
            node=node->next;
            addBefore(newUpper, node);

            //set to newNode
            newNode=newUpper;
            count++;
        }else
            break;
    }

    return true;
}

void SkipList::addBefore(SNode *NewNode, SNode *NextNode) {
    assert(NewNode != nullptr && NextNode != nullptr &&NewNode->data < NextNode->data);
    //add before NextNode
    SNode *prevNode=NextNode->prev;
    prevNode->next=NewNode;
    NewNode->prev=prevNode;

    NewNode->next=NextNode;
    NextNode->prev=NewNode;

    assert (NewNode->next == NextNode && NextNode->prev == NewNode);
    assert (NewNode->prev != nullptr && NewNode->prev->data < NewNode->data);
}

SkipList::~SkipList() {
    // need to delete individual nodes
    SNode *node,*last;

    //loop to delete nodes
    for(int i=depth-1;i>=0;i--){
        node=FrontGuards[i];
        while(node!= nullptr){
            last=node;
            node=node->next;
            delete last;
        }
    }

    //delete skiplist guards array
    delete [] FrontGuards;
    delete [] RearGuards;
}

bool SkipList::Remove(int data) {
    SNode *current=FrontGuards[0]->next;
    SNode *last;

    //search from the highest skiplist
    while(current != nullptr){
        //Keep moving right as long as the current->next->data is less than value
        while(current->data<data && current->next != nullptr) {
            current = current->next;
        }

        //if find the data
        if(current->data==data){

            while(current != nullptr){
                last=current;

                //up one level
                current=current->upLevel;

                //delete node last
                if (last->prev != nullptr){
                    last->prev->next = last->next;
                }
                delete last;
            }
            return true;
        }
        current=current->upLevel;
    }
    return false;
}

bool SkipList::Contains(int data) {
    SNode *current=FrontGuards[0];

    //search from the highest skiplist
    while(current!= nullptr){
        //Keep moving right as long as the current->next->data is less than value
        while(current->next->data<data)
            current=current->next;

        //if find the data
        if(current->next->data==data)
            return true;

        //up one level from current node
        current=current->upLevel;
    }

    return false;
}


