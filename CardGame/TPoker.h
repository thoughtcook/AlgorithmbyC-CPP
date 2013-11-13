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

#ifndef TPOKER_H
#define TPOKER_H

#include "TCard.h"
#include <iostream>
#define SUIT_NUM 4
#define CARDNUM_PER_SUIT 13

#define CARD_NUM 52

class TPoker
{
private:
  std::vector<TCard> Cards;
public:
  TPoker();
  ~TPoker();
  void Shuffle();
  TCard DealOneCard();
  friend std::ostream& operator << (std::ostream& os, const TPoker& poker);
};

#endif
