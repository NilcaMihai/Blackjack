#pragma once
#include <iostream>
#include <string>
#include "Deck.h"

const int g_maxScore{ 21 };
const int g_minimDealerScore{ 17 };

class Player
{
	std::string m_name{};
	int m_score{ 0 };

public:
	//Constructor
	Player();
	Player(std::string name, int score = 0);

	//Getters & setters
	int getScore();

	//Metods
	int drawCard(Deck& deck);
	bool isBust();
	//Destructor
	~Player();

};

