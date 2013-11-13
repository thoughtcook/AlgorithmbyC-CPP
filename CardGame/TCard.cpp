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

#include "TCard.h"

TCard::TCard(int suit, int number)
{
  Suit = suit;
  Number = number;
}

TCard::TCard()
{
  Suit = 0;
  Number = 0;
}

int TCard::GetSuit() const
{
  return Suit;
}

int TCard::GetNumber() const
{
  return Number;
}

std::ostream& operator<< (std::ostream& os, TCard card)
{
  os << "[" << card.Suit << ", " << card.Number << "]";
  return os;
}

TCard::~TCard()
{
  // empty
}
