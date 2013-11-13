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

#ifndef CARDFUNC_H
#define CARDFUNC_H

#include <queue>
#include <vector>
#include <unistd.h>

#include "TCard.h"
#include "TPlayer.h"

#define SLEEP_TIME 800000

int FindCard(std::queue<TCard> cardQue, TCard card);
void PlaceCardOnBridge(std::vector<TCard>& bridge, TPlayer& player);
void WatchBridge(const std::vector<TCard>& bridge);
void Watch2PlayerCards(const TPlayer& playerA, const TPlayer& playerB);
bool PlayGame(TPlayer& playerA, TPlayer& playerB);
#endif
