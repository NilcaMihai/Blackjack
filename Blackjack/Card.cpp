#include "Card.h"

Card::Card()
{
}

Card::Card(CardRank rank, CardSuit suit)
{
	m_rank = rank;
	m_suit = suit;
}

void Card::printCard()
{
	switch(m_rank)
	{
	case CardRank::rank_2:		std::cout << "2";  break;
	case CardRank::rank_3:		std::cout << "3";  break;
	case CardRank::rank_4:		std::cout << "4";  break;
	case CardRank::rank_5:		std::cout << "5";  break;
	case CardRank::rank_6:		std::cout << "6";  break;
	case CardRank::rank_7:		std::cout << "7";  break;
	case CardRank::rank_8:		std::cout << "8";  break;
	case CardRank::rank_9:		std::cout << "9";  break;
	case CardRank::rank_10:		std::cout << "10"; break;
	case CardRank::rank_jack:	std::cout << "J";  break;
	case CardRank::rank_queen:	std::cout << "Q";  break;
	case CardRank::rank_king:	std::cout << "K";  break;
	case CardRank::rank_ace:	std::cout << "A";  break;
	default:		std::cout << "Unidentified\n"; break;
	}
	switch(m_suit)
	{
	case CardSuit::club:	 std::cout << "Club";	  break;
	case CardSuit::diamond:  std::cout << "Diamond";  break;
	case CardSuit::heart:	 std::cout << "Heart";	  break;
	case CardSuit::spade:	 std::cout << "Spade";	  break;
	default:		std::cout << "Unidentified\n";	  break;
	}
	std::cout << "\n";
}

int Card::getValue()
{
	switch (m_rank)
	{
	case CardRank::rank_2:		return 2;	break;
	case CardRank::rank_3:		return 3;	break;
	case CardRank::rank_4:		return 4;	break;
	case CardRank::rank_5:		return 5;	break;
	case CardRank::rank_6:		return 6;	break;
	case CardRank::rank_7:		return 7;	break;
	case CardRank::rank_8:		return 8;	break;
	case CardRank::rank_9:		return 9;	break;
	case CardRank::rank_10:		return 10;	break;
	case CardRank::rank_jack:	return 10;  break;
	case CardRank::rank_queen:	return 10;  break;
	case CardRank::rank_king:	return 10;  break;
	case CardRank::rank_ace:	return 11;  break;
	default: std::cout << "No way!\n"; return 0;
	}
}

Card::~Card()
{
}