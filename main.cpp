#include <iostream>
#include "deck.h"

int main() {

    deck d;

    d.initDeck();
    d.shuffle();
    d.copy();
    d.print();
    d.del();
    d.copy();
    d.sort();
    d.print();
}