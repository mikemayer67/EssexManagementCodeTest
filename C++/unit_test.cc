#include <iostream>

#include "Card.h"
#include "Hand.h"
#include "Deck.h"

#define NOTE(s) \
  std::cout << "NOTE:   " #s << std::endl;

#define GIVEN(s) \
  std::cout << "GIVEN:  " #s << std::endl; \
  s;

#define GIVEN_SV(s,v) \
  std::cout << "GIVEN:  " s << v << std::endl;

#define TEST(t) \
  if( (t) ) { std::cout << "PASSED: " #t << std::endl; } \
  else      { std::cout << "FAILED: "  #t << std::endl; } \
  std::cout << std::endl;

#define TEST_EXCEPTION(t) \
  try { \
    t; \
    std::cout << "FAILED: No exception thrown for: " #t << std::endl; \
  } catch(...) { \
    std::cout << "PASSED: Exception thrown for: " #t << std::endl; \
  }\
  std::cout << std::endl;


int main(int argc,char **argv)
{
  // Test 1 - Verify that the card point values are being assessed correctly
  //  Req #4: 
  //   color point calculation, red = 3, yellow =2, green = 1) 
  //   the point is calculated  by color point * number in the card

  std::cout << std::endl << "Card construction tests" << std::endl << std::endl;

  GIVEN( Card c1(RED,5) )
  TEST( c1.pointValue() == 15 )

  GIVEN( Card c2(YELLOW, 3) )
  TEST( c2.pointValue() == 6 )

  GIVEN( Card c3(GREEN,9) )
  TEST( c3.pointValue() == 9 )

  GIVEN( Card c4(RED,0) )
  TEST( c4.pointValue() == 0 )

  TEST_EXCEPTION( Card c4(RED,   -1) )
  TEST_EXCEPTION( Card c4(YELLOW,10) )


  // Test 2 - Verify that sorting of a hand works correctly
  //  Req #3:
  //   Sort cards: take a list of color as parameter and sort the card in that color order. 
  //   Numbers should be in ascending order.  

  std::cout << std::endl << "Sorting of Hands of cards" << std::endl << std::endl;

  Hand hand;
  hand.add(Card(RED,8));
  hand.add(Card(YELLOW,5));
  hand.add(Card(GREEN,3));
  hand.add(Card(GREEN,2));
  hand.add(Card(RED,6));
  hand.add(Card(YELLOW,7));
  hand.add(Card(RED,5));
  hand.add(Card(RED,0));
  hand.add(Card(GREEN,4));
  hand.add(Card(YELLOW,2));
  hand.add(Card(RED,6));

  GIVEN_SV("Unsorted: ", hand.str())
  GIVEN(hand.sort(RED,YELLOW,GREEN))
  TEST(hand.str() == "0R 5R 6R 6R 8R 2Y 5Y 7Y 2G 3G 4G")
  GIVEN(hand.sort(GREEN,YELLOW,RED))
  TEST(hand.str() == "2G 3G 4G 2Y 5Y 7Y 0R 5R 6R 6R 8R")

  // Test 3 - Creating a shuffled deck
  //  Req #1	Shuffle cards in the deck: randomly mix the cards in the card deck, and return a 
  //    whole deck of cards with a mixed order

  std::cout << std::endl << "Shuffling a new deck" << std::endl << std::endl;

  GIVEN(Deck deck)
  GIVEN_SV("Cards: ", deck.str())
  TEST(deck.size() == 30)
  NOTE(Verify that we did not add or lose any cards);
  GIVEN(deck.sort(GREEN,YELLOW,RED))
  TEST(deck.str() == "0G 1G 2G 3G 4G 5G 6G 7G 8G 9G 0Y 1Y 2Y 3Y 4Y 5Y 6Y 7Y 8Y 9Y 0R 1R 2R 3R 4R 5R 6R 7R 8R 9R" )


  std::cout << std::endl << "Dealing from the deck" << std::endl << std::endl;

  std::string truth[] = {
    "0G","1G","2G","3G","4G","5G","6G","7G","8G","9G",
    "0Y","1Y","2Y","3Y","4Y","5Y","6Y","7Y","8Y","9Y",
    "0R","1R","2R","3R","4R","5R","6R","7R","8R","9R" 
  };


  NOTE(Using sorted deck to know what card should be dealt next);
  for(int i=0; i<30; ++i)
  {
    if(i<6 || i > 25)
    {
      GIVEN(Card c = deck.deal())
      GIVEN_SV("Expected next card: ", truth[i])
      TEST(c.str() == truth[i]);
    }
    else
    {
      if(i==6) { 
        NOTE(Skipping to card 25)
        std::cout << std::endl;
      }
      Card c = deck.deal();
    }
  }

  NOTE("Next deal should throw an exception as the deck is now empty")
  TEST_EXCEPTION(Card c = deck.deal());


  // Not going to provide unit tests for the execution of the game
  //   Better testing would include a random deck and examining results.


  std::cout << std::endl << "Tests Complete" << std::endl;

  return 0;
}

