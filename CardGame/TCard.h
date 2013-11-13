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

#ifndef TCARDS_H
#define TCARDS_H

#include <vector>
#include <iostream>

class TCard
{
private:
  int Suit;
  int Number;
public:
  int GetSuit() const;
  int GetNumber() const;
  TCard();
  TCard(int suit, int number);
  friend std::ostream& operator<< (std::ostream& os, TCard card);
  ~TCard();
};
#endif
