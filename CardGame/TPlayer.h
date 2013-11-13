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

#ifndef TPLAYER_H
#define TPLAYER_H

#include <string>
#include <list>
#include "TCard.h"
#include "TPoker.h"
#include <iostream>
#include <algorithm>

class TPlayer
{
private:
  std::string PlayerName;
  std::list<TCard> Cards;
public:
  TPlayer(std::string playerName);
  ~TPlayer();
  std::string GetName();
  void Deal(TPoker& poker);
  std::list<TCard> GetHandCards() const;
  void GetOneCard(TCard card);
  TCard PlaceOneCard();
  bool HasCards();
  friend std::ostream& operator<< (std::ostream& os, const TPlayer player);
};

#endif
