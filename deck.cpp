//
// Created by kowusek on 09.12.2019.
//

#include "deck.h"

bool card::operator<( const card &a ) const {

    if( this->v < a.v )
        return true;

    else if( this->v == a.v ) {

        if( this->c < a.c )
            return true;
    }
    return false;
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

    insertionSort();
}

void deck::insert( deck::Node *node ) {

    struct Node* current;

    if ( a == nullptr || node->data < a->data || (node->data < a->data && a->data < node->data ) ) {

        node->next = a;
        a = node;
    }
    else {

        current = a;

        while ( current->next!= nullptr && current->next->data < node->data ) {

            current = current->next;
        }

        node->next = current->next;
        current->next = node;
    }
}

void deck::insertionSort() {

    for( auto & i : d ) {

        auto temp = new struct Node;
        temp->data = *i;
        temp->next = nullptr;
        deck::insert( temp );
    }
}

void deck::print() {

    struct Node *temp = a;

    while( temp != nullptr ) {

        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
}
