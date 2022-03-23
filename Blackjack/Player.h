#pragma once
#include <iostream>
#include <string>
#include "Deck.h"


class Player
{
	std::string m_name{};
	int m_score{ 0 };
	float m_sold{ 0 };
	float m_betMoney{ 0 };
	int m_numberOfGamesPlayed{ 0 };
	int m_numberOfVictories{ 0 };

public:
	//Constructor
	Player();
	Player(std::string name, float sold = 0, int score = 0);

	//Getters & setters
	int getScore();
	void resetScore();
	float getSold();
	int getNumberOfGamesPlayed();
	int getNumberOfVictories();

	//Metods
	void drawCard(Deck &deck);
	bool hit();
	bool isBust();
	void bet();
	void paidBet();
	void paidBlackjack();
	void paidDraw();
	void updateSold();
	void getInfo();

	//Destructor
	~Player();
};