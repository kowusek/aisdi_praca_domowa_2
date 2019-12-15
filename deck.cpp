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
        Node* b = temp;

        while ( b ) {

            if ( b->data < min->data )
                min = b;

            b = b->next;
        }

        card y = min->data;

        b = temp;


        card z = b->data;
        card v = b->data;

        while (b->next && b != min) {

            v = z;
            z = b->next->data;
            b->next->data = v;
            b = b->next;
        }
        temp->data = y;
        temp = temp->next;
    }

}

void stableSelectionSort(int a[], int n)
{
    // Iterate through array elements
    for (int i = 0; i < n - 1; i++)
    {

        // Loop invariant : Elements till a[i - 1]
        // are already sorted.

        // Find minimum element from
        // arr[i] to arr[n - 1].
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (a[min] > a[j])
                min = j;

        // Move minimum element at current i.
        int key = a[min];
        while (min > i)
        {
            a[min] = a[min - 1];
            min--;
        }
        a[i] = key;
    }
}

void deck::del() {

    a = nullptr;
}