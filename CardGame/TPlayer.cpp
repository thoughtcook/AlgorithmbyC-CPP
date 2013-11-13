//
//    Author: Johnny Huang
//    Email: thoughtcook@163.com
//    Website: http://www.thoughtcook.com
//    Copyright (C) 2013 All rights reserved.
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.

#include "TPlayer.h"
#include <iterator>

TPlayer::TPlayer(std::string playerName)
{
  PlayerName = playerName;
}

TPlayer::~TPlayer()
{
}

std::string TPlayer::GetName()
{
  return PlayerName;
}

void TPlayer::Deal(TPoker& poker)
{
  for (int i = 0; i < CARD_NUM / 2; i++) {
    Cards.push_back(poker.DealOneCard());
  }
}

std::list<TCard> TPlayer::GetHandCards() const
{
  return Cards;
}

void TPlayer::GetOneCard(TCard card)
{
  Cards.push_front(card);
}

TCard TPlayer::PlaceOneCard()
{
  TCard tempCard = Cards.back();
  Cards.pop_back();
  return tempCard;
}

bool TPlayer::HasCards()
{
  return Cards.size() != 0;
}

std::ostream& operator<< (std::ostream& os, const TPlayer player)
{
  os << player.PlayerName << ":" << std::endl;
  std::list<TCard> CardList;
  CardList = player.GetHandCards();
  std::copy(CardList.begin(), CardList.end(), std::ostream_iterator<TCard>(std::cout, " "));

  return os;
}
