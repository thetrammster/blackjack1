#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Card {
  int rank;
  int suit;
  const char *name;
} Card;
// penis but
Card deck[] = {{1, 0, "Ace of Hearts"},    {1, 1, "Ace of Diamonds"},
               {1, 2, "Ace of Clubs"},     {1, 3, "Ace of Spades"},
               {2, 0, "2 of Hearts"},      {2, 1, "2 of Diamonds"},
               {2, 2, "2 of Clubs"},       {2, 3, "2 of Spades"},
               {3, 0, "3 of Hearts"},      {3, 1, "3 of Diamonds"},
               {3, 2, "3 of Clubs"},       {3, 3, "3 of Spades"},
               {4, 0, "4 of Hearts"},      {4, 1, "4 of Diamonds"},
               {4, 2, "4 of Clubs"},       {4, 3, "4 of Spades"},
               {5, 0, "5 of Hearts"},      {5, 1, "5 of Diamonds"},
               {5, 2, "5 of Clubs"},       {5, 3, "5 of Spades"},
               {6, 0, "6 of Hearts"},      {6, 1, "6 of Diamonds"},
               {6, 2, "6 of Clubs"},       {6, 3, "6 of Spades"},
               {7, 0, "7 of Hearts"},      {7, 1, "7 of Diamonds"},
               {7, 2, "7 of Clubs"},       {7, 3, "7 of Spades"},
               {8, 0, "8 of Hearts"},      {8, 1, "8 of Diamonds"},
               {8, 2, "8 of Clubs"},       {8, 3, "8 of Spades"},
               {9, 0, "9 of Hearts"},      {9, 1, "9 of Diamonds"},
               {9, 2, "9 of Clubs"},       {9, 3, "9 of Spades"},
               {10, 0, "10 of Hearts"},    {10, 1, "10 of Diamonds"},
               {10, 2, "10 of Clubs"},     {10, 3, "10 of Spades"},
               {11, 0, "Jackof Hearts"},   {11, 1, "Jack of Diamonds"},
               {11, 2, "Jack of Clubs"},   {11, 3, "Jack of Spades"},
               {12, 0, "Queen of Hearts"}, {12, 1, "Queen of Diamonds"},
               {12, 2, "Queen of Clubs"},  {12, 3, "Queen of Spades"},
               {13, 0, "King of Hearts"},  {13, 1, "King of Diamonds"},
               {13, 2, "King of Clubs"},   {13, 3, "King of Spades"}};

const int NUM_CARDS = sizeof(deck) / sizeof(deck[0]);

typedef struct Player {
} Player;

Card hand[10];     // Example hand size, can be adjusted
int cardIndex = 0; // Global variable to track the current card index

int handSize = sizeof(hand) / sizeof(hand[0]);

void FisherYatesShuffle(Card deck[], int size) {
  int n, k;
  Card temp;
  // Seed the random number generator
  srand((unsigned int)time(NULL));

  // Iterate through the array in reverse order
  for (n = size - 1; n > 0; n--) {
    // Generate a random index 'k' between 0 and n (inclusive)
    k = rand() % (n + 1);

    // Swap the elements at indices 'n' and 'k'
    temp = deck[n];
    deck[n] = deck[k];
    deck[k] = temp;
  }
}

void draw(int numCards, Card deck[], Card hand[]) {
  // Card arr[10];
  int i;
  for (i = cardIndex; i < numCards && cardIndex < NUM_CARDS; i++) {
    hand[i] = deck[cardIndex++];
  }
}

void initGame(Card deck[], int numCards) {
  // Shuffle the deck
  FisherYatesShuffle(deck, numCards);

  // Deal initial cards
}

int main(void) {
  printf("welcome to blackjack\n");

  FisherYatesShuffle(deck, NUM_CARDS);
  draw(3, deck, hand);

  for (int i = 0; i < NUM_CARDS; i++) {
    printf("%s\n", deck[i].name);
  }
  for (int i = 0; i < 3; i++) {
    printf("%s\n", hand[i].name);
  }
  for (int i = 0; i < 3; i++) {
    printf("%s\n", hand[i].name);
  }
  return 0;
}
