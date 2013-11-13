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

#include "TPoker.h"
#include "Common.h"
#include <cstdlib>
#include <vector>
#include <ctime>

TPoker::TPoker()
{
  for (int i = 0; i < SUIT_NUM; i++) {
    for (int j = 0; j < CARDNUM_PER_SUIT; j++) {
      TCard tempCard(i + 1, j + 1);
      Cards.push_back(tempCard);
    }
  }
  Cards[CARD_NUM - 1] = TCard (0, 0);
}

TPoker::~TPoker()
{
}

void TPoker::Shuffle()
{
  int i;
  std::vector<int> order;
  srand((unsigned int)time(0));
  for (i = 0; i < CARD_NUM / 2; i++) {
    int shuffleA = rand() % CARD_NUM;
    int shuffleB = rand() % CARD_NUM;
    Swap<TCard>(Cards[shuffleA], Cards[shuffleB]);
  }
}

TCard TPoker::DealOneCard()
{
  TCard tempCard = Cards.back();
  Cards.pop_back();
  return tempCard;
}

std::ostream& operator << (std::ostream& os, const TPoker& poker)
{
  unsigned int i;
  for(i=0; i < poker.Cards.size(); i++) {
    os << "[" << poker.Cards[i].GetSuit() << ", " << poker.Cards[i].GetNumber() << "]-" ;
  }
  os << std::endl;

  return os;
}
