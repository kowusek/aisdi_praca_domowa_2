//
// Created by kowusek on 09.12.2019.
//

#include "deck.h"

bool card::operator<( const card &a ) const {

    return this->v < a.v;
}

std::ostream &operator<<( std::ostream &stream, const card &c ) {

    stream << c.c << " " << c.v;

    return stream;
}

void deck::initDeck() {

    for( int i = 0; i < 13; ++i ) {
        for( int j = 0; j < 4; ++j ) {

            card* x = new card;
            x->v = static_cast<card::value>( i );
            x->c = static_cast<card::colour>( j );
            d.push_back( x );
        }
    }
}

void deck::shuffle() {

    std::random_device rd;
    std::mt19937 g( rd() );

    std::shuffle( d.begin(), d.end(), g );
}

void deck::sort() {

    selectionSort();
}


void deck::push( card & value ) {

    auto* temp = new Node;

    temp->data = value;
    temp->next = a;
    a = temp;
}

void deck::copy() {

    for( auto & i : d ) {

        push( *i );
    }
}

void deck::print() {

    struct Node *temp = a;

    while( temp != nullptr ) {

        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
    std::cout << std::endl;
}

void deck::selectionSort() {

    Node* temp = a;

    while ( temp ) {

        Node* min = temp;
        Node* b = temp->next;

        while ( b ) {

            if ( b->data < min->data )
                min = b;

            b = b->next;
        }

        card x = temp->data;
        temp->data = min->data;
        min->data = x;
        temp = temp->next;
    }
}

void deck::del() {

    a = nullptr;
}