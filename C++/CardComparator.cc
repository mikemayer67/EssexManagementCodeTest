////////////////////////////////////////////////////////////////////////////////
// File: CardComparator.cc
//
// Project: C++ implementation of the Essex Management Code Test
//
// Description: (Refer to header file)
//
// Change Log:
// 2020.06.10   Mike Mayer   Initial Development
////////////////////////////////////////////////////////////////////////////////

#include "CardComparator.h"

//------------------------------------------------------------------------------
// Constructor
//   establishes sort indices associated with each suit
//   specified suits must all be unique
//------------------------------------------------------------------------------

CardComparator::CardComparator(Suit suit1, Suit suit2, Suit suit3)
{
  assert(suit1 != suit2);
  assert(suit1 != suit3);
  assert(suit2 != suit3);

  _order[suit1] = 1;
  _order[suit2] = 2;
  _order[suit3] = 3;
}

bool CardComparator::operator()(const Card &card1, const Card &card2) const
{
  // examine suit first

  SuitOrder::const_iterator it;

  it = _order.find(card1.suit());
  assert( it != _order.end() );  // failure is a code logic error, not a runtime error
  int suitOrder1 = it->second;

  it = _order.find(card2.suit());
  assert( it != _order.end() );
  int suitOrder2 = it->second;

  // return immediately if suit alone can determine order
  if(suitOrder1 < suitOrder2) return true;
  if(suitOrder2 < suitOrder1) return false;

  // if we got here, suits must be equal... compare rank
  Card::Rank rank1 = card1.rank();
  Card::Rank rank2 = card2.rank();

  // return whether or not card 1 belongs BEFORE card 2
  return rank1 < rank2;
}
