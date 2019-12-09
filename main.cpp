#include <iostream>
#include "deck.h"

int main() {

    deck d;

    d.initDeck();
    d.shuffle();
    d.sort();
    d.print();
}