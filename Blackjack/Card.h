#pragma once
#include <iostream>

class Card
{
public:
	enum class CardRank
	{
		rank_2,
		rank_3,
		rank_4,
		rank_5,
		rank_6,
		rank_7,
		rank_8,
		rank_9,
		rank_10,
		rank_jack,
		rank_queen,
		rank_king,
		rank_ace,
		max_ranks,
	};
	enum class CardSuit
	{
		club,
		diamond,
		heart,
		spade,
		max_suits,
	};

private:
	CardRank m_rank{};
	CardSuit m_suit{};

public:
	//Constructor
	Card();
	Card(CardRank rank, CardSuit suit);
	//Metods
	void printCard();

	//Getters & setters
	int getValue();

	//Destructor
	~Card();
};