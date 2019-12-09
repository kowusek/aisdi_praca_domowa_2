//
// Created by kowusek on 09.12.2019.
//

#ifndef CARDS_DECK_H
#define CARDS_DECK_H

#include <algorithm>
#include <random>
#include <iterator>
#include <iostream>


class card {

public:

    enum value { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };
    enum colour { S, H, D, C };

    value v;
    colour c;

    bool operator< ( card const& a ) const;

    friend std::ostream& operator<< ( std::ostream& stream, const card& card );

    card() = default;

    ~card() = default;

    card( const card &p2 ) {

        v = p2.v;
        c = p2.c;
    }
};

class deck {

public:

    struct Node {

        card data;
        struct Node* next;
    };

    std::vector<card*> d;
    struct Node *a = nullptr;

    void initDeck();

    void shuffle();

    void sort();

    void insert( struct Node* node );

    void insertionSort(  );

    void print();
};


#endif //CARDS_DECK_H
