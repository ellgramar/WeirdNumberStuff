//
// Created by Elliot Marshall on 3/20/23.
//
#ifndef NATURAL_H
#define NATURAL_H
// includes
#include <stdint.h>
#include <stdlib.h>
// struct
typedef struct natural {
    uint64_t val;
    struct natural * prev;
    struct natural * next;
}natural;
// functions
struct natural newNatural();
struct natural longToNatural(long number);
void freeNatural(struct natural n);


// convenience functions
struct natural getHead(struct natural n);
struct natural getTail(struct natural n);
struct natural append(struct natural old, struct natural addition);
struct natural prepend(struct natuarl old, struct natural addition);
struct natural insertByIndex(uint64_t index, struct natural n);
void delByValue(long value, struct natuarl n);
void delByIndex(int index, struct natuarl n);
#endif // NATURAL_H
