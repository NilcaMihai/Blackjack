#pragma once
#include "Card.h"
#include <iostream>
#include <random>
#include <Windows.h>

const int g_maxScore{ 21 };
const int g_minimDealerScore{ 17 };

class Deck
{
private:
	 Card m_deck[52];
	 int m_cardIndex{ 0 };

public:
	//Constructor
	Deck();
	//Getters & setters

	//Metods
	void printDeck();
	void shuffleDeck();
	Card& dealCard();
	//Destructor
	~Deck();
};