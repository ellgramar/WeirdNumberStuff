//
// Created by Elliot Marshall on 3/20/23.
//

#include "natural.h"

// constructor for a natural number
struct natural newNatural(){
    struct natural * n = calloc(1,sizeof(natural));
    n.val = NULL;
    n.prev = NULL;
    n.next = NULL;
    return n;
}
// convert a long to a natural
struct natural longToNatural(long number){
    natural n = newNatural();
    n.val = (uint64_t)number;
    return n;
}
// frees the natural number in a list
void freeNatural(struct natural n){
    // set n to the last node
    n = getTail(n);
    // iterate from the last node and free each one until the first node
    while (n.prev != NULL){
        n.val = NULL
        n = n.prev;
        n.next.prev = NULL;
        free(n.next);
        n.next = NULL;
    }
    // now free the first node
    n.val = NULL;
    n.prev = NULL;
    n.next = NULL;
    free(n);
    return;
}

// convenience functions
// get the head of the LL of the number
struct natural getHead(struct natural n){
    // while n is not the first one, reset n to be the previous one
    while (n.prev != NULL){
        n = n.prev;
    }
    return n;
}
// get the tail of the linked list of the natural
struct natural getTail(struct natural n){
    // while n is not the lst one, reset n to be the next one
    while (n.next != NULL){
        n = n.next;
    }
    return n;
}
// append a number to the tail of the list
struct natural append(struct natural old, struct natural addition){
    old = getTail(old);
    old.next = addition;
    additon.prev = old;
    old = getHead(old);
    return old;
}
// append a list to a natural
struct natural prepend(struct natuarl old, struct natural addition){
    old = getHead(old);
    old.prev = addition;
    addition.next = old;
    old = getHead(old);
    return old;
}
// deletes a specific value in a LL if it exists, only the first value, so be careful
void delByValue(long value, struct natural n){
    n = getHead(n);
    while (n.val != value){
        n = n.next;
    }
    if ((n.val == value) && (n.prev != NULL)){
        n = n.prev;
        free(n.next);
    } else if ((n.val == value) && (n.next != NULL)){
        n = n.next;
        free(n.prev);
    } else{
        free(n);
    }
    return;
}
// deletes a natural in a list by index
struct natural delByIndex(int index, struct natural n){
    n = getHead(n);
    while ((index > 0) && n.next != NULL){
        n = n.next;
    }
    free(n);
    return;
}