# EssexManagementCodeTest
CodeTest Assignment for Hiring Interview

## Problem Definition:

> Code interview question: Work with the programing language you are most familiar with. 
>
> Create a card game which supports 3 of the operations below. 
> 1.	Shuffle cards in the deck: randomly mix the cards in the card deck, and return a whole deck of cards with a mixed order 
> 2.	Get a card from the top of the deck: get one card from top of the card deck, return a card, and if there is no card left in the deck return error or exception.  
> 3.	Sort cards: take a list of color as parameter and sort the card in that color order. Numbers should be in ascending order.  
>   i.e. If the deck has a card contains with following order (red, 1), (green, 5), (red, 0), (yellow, 3), (green, 2) 
>   Sort cards([yellow, green, red]) will return the cards with following order (yellow, 3), (green, 0), (green, 5), (red, 0), (red, 1)  
> 4.	Determine winners: 2 players play the game. They will draw 3 cards by taking turns. 
>  Whoever has the high score wins the game. (color point calculation, red = 3, yellow =2, green = 1) the point is calculated    by color point * number in the card.   
>  
> Testing: Create test cases to test the above operations. 
> 
> Please put the code in an online repository and provide the link before the interview: github, gitlab, etc. 

## Design Assumptions:
- Requirement is to implement **at least** 3 of the operations below.  I have opted to implement all 4.
- Neither suits nor rank values were explicitly specified in the problem statement. Using the examples provided in the requirements and the need to score based on red, yellow, and green suits, I will assume there are only the 3 color suits and that the rank values will range from 0 to 9.  This will result in a full deck of 30 cards.
- The requirements do not specify if the winner's score is based on the best card they drew or the sum of the three cards.  I am going to assume it is the latter.
- The scoring equation provided allows for the potential for ties.  I am going to allow for this case as well rather than add new rules for breaking ties.
- The requirements say nothing about whether this game demo should be interactive or not.  I will include only minimal user input in my implemtation(s).  Most of the "action" will be driven by front end "robots" that will play the game.  This includes the "decision" about suit ranking (sort order) and the drawing of cards during game play.

## Language of Choice:
- I understand that Python is a desired language by Essex Managmement. While I recognize this preference, I fully believe that programming is an art that uses various languages as its medium and is not tied to any particular language.
- I fully admit that I have only rudimentary Python experience, but have little to no doubt that I can pick Python up as quickly as I have picked up other languages.
- To this end, I am submitting solutions in multiple languages.  I hope to demonstrate along the way that I understand how to use the unique capabilities of each language and not just transliterate between them.
- I hope to provide solutions in the following:
  - C++: the compiled language I have used most heavily in my professional career
  - Perl: the scripting language I have used most heavily in my professional career
  - PHP/Javascript/JQuery/HTML/CSS: why not? It could be fun.
  - Python: *be gentle on me, this is my first attempt after the obligatory Hello World*
  
## Testing:
- Most of the testing that I am familiar with consists of one or more of the following:
  - Logging of function I/O followed by subsequent analysis to verify correctness of result. This may also include logging of intermediate values within the function to validate internal logic.
  - Automated testing (Jenkins) where predefined inputs are fed into an application and outputs are compared to expected results.  Failure to match triggers a need to investigate root cause of discrepancy.
- Requirement 1 above states that the deck must be shuffled **randomly**. This presents a challenge for predefining expected results.  (*I could seed the random number generator, but this would still require a base run to determine the expected results.  This approach undermines any validity of the test.*)  I will, therefore, implement testing through the logging/analysis approach.
