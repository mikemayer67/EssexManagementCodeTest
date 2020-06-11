////////////////////////////////////////////////////////////////////////////////
// File: Deck.h
//
// Project: C++ implementation of the Essex Management Code Test
//
// Description:
// 
//   This class defines a specialized Hand which initializes itself to
//     a randomized (shuffled) set of all cards (one of each)
//
//   The Deck class adds the ability to deal one card at a time off the
//     top of the stack.
//
// Change Log:
// 2020.06.10   Mike Mayer   Initial Development
////////////////////////////////////////////////////////////////////////////////

#ifndef _DECK_H_
#define _DECK_H_

#include "Hand.h"

class Deck : public Hand
{
  public:

    // Constructor - builds a shuffled hand with all possible cards
    Deck();

    // size - number of cards remaining in the deck
    int size() { return _cards.size(); }

    // deal - returns a single card off the top of the deck
    //   the card is then removed from the deck
    //   throws an exception (integer 0) if the deck is empty
    Card deal();
};

#endif // _DECK_H_

