////////////////////////////////////////////////////////////////////////////////
// File: Deck.cc
//
// Project: C++ implementation of the Essex Management Code Test
//
// Description: (Refer to header file)
//
// Change Log:
// 2020.06.10   Mike Mayer   Initial Development
////////////////////////////////////////////////////////////////////////////////

#include "Deck.h"

#include <random>

#include <unistd.h>

//--------------------------------------------------------------------------------
// Deck consstructor - shuffled complete set of cards
//--------------------------------------------------------------------------------
Deck::Deck()
{
  // start by creating an unshuffled set of all cards

  Cards unshuffled;
  for(Card::Rank rank=0; rank<10; ++rank)
  {
    unshuffled.push_back( Card(RED,   rank) );
    unshuffled.push_back( Card(YELLOW,rank) );
    unshuffled.push_back( Card(GREEN, rank) );
  }

  // This is not the most robust random number generator, but it should
  //   be good enough here and is simple to use
  std::default_random_engine generator;
  generator.seed(getpid());

  int numUnshuffled = unshuffled.size();  // should be 30, but won't assume that

  while(numUnshuffled > 0)
  {
    // yes, the following is "silly" when numUnshuffled is 1, but it works
    //   and doesn't require near duplication of code

    // pick a card at random from the unshuffled deck
    int cardIndex = generator() % numUnshuffled; // not perfectly uniform, but fairly close

    // remove it from the unshuffled deck and add it to our hand (the new shuffled deck)

    Card card = unshuffled.at(cardIndex);
    unshuffled.erase(unshuffled.begin() + cardIndex);

    _cards.push_back(card);

    numUnshuffled -= 1;
  }
}

//------------------------------------------------------------------------------
// deal() - deals a single card off the top of the deck
//   throws an exception when the deck is empty
//------------------------------------------------------------------------------
Card Deck::deal()
{
  if( _cards.empty() ) { throw 0; }

  // would actually be slightly more efficient to use pop_back to pull a 
  //   card from the end of the list... but I wouldn't want to be accused
  //   of cheating by dealing off the bottom of the deck.

  Card rval = _cards.at(0);
  _cards.erase(_cards.begin());

  return rval;
}
