////////////////////////////////////////////////////////////////////////////////
// File: CardComparator.h
//
// Project: C++ implementation of the Essex Management Code Test
//
// Description:
// 
//   This structure defines the function used to compare the relative sort
//     order for two cards.  This function returns true if the specified
//     cards are already in sorted order or false if they are not (or if
//     the two cards are equal with respect to their sort order).
//
//   The cards are compared first by suit (using the order specified on
//     construction of the comparator) and then by rannk (in ascending order).
//
// Change Log:
// 2020.06.10   Mike Mayer   Initial Development
////////////////////////////////////////////////////////////////////////////////

#ifndef _CARDSORTER_H_
#define _CARDSORTER_H_

#include "Card.h"

#include <map>

class CardComparator
{
  public:

    // Constructor - the arguments specify the suit sort order
    CardComparator(Suit suit1, Suit suit2, Suit suit3);

    // The actual comparison function
    //   true  = card1 belongs before card2
    //   false = card1 belongs after (or alongside) card2
    bool operator()(const Card &card1, const Card &card2) const;

  private:
    typedef std::map<Suit,int> SuitOrder;

    SuitOrder _order; // mapping from Suit to sort order on suit
};

#endif // _CARDSORTER_H_
