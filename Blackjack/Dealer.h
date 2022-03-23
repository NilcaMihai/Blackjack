#pragma once
#include"Deck.h"

class Dealer
{
	int d_score{ 0 };

public:
	//Constructor
	Dealer();
	//Getters & setters
	int getScore();
	//Metods
	void drawCard(Deck &deck);
	//Destructor
	~Dealer();
};