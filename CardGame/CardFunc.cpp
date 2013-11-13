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

#include "CardFunc.h"
#include <iostream>

using namespace std;

int FindCard(std::vector<TCard> cardQue, TCard card)
{
  int i;
  for (i = 0; i < cardQue.size(); ++i) {
    if (cardQue[i].GetNumber() == card.GetNumber()) {
      break;
    }
  }
  if (i < cardQue.size()) {
    cout << "The " << i<<" Card is the same as present card." << endl;
    return i;
  }
  return -1;
}

void PlaceCardOnBridge(std::vector<TCard>& bridge, TPlayer& player)
{
  TCard handCard;
  int bridgeLength;
  handCard = player.PlaceOneCard();

  if (bridge.size() >= 1) {
    int positionFind;
    positionFind = FindCard(bridge, handCard);

    if (positionFind != -1) {
      bridge.push_back(handCard);
      bridgeLength = bridge.size();
      for(unsigned int i = positionFind; i < bridgeLength; i++) {
        player.GetOneCard(bridge.back());
        bridge.pop_back();
      }
      PlaceCardOnBridge(bridge, player);
    }
    else {
      bridge.push_back(handCard);
    }
  }
  else {
    bridge.push_back(handCard);
  }
}

void WatchBridge(const std::vector<TCard>& bridge)
{
  cout << endl;
  cout << "================The Bridge===============" << endl;
  for (unsigned int i = 0; i < bridge.size(); ++i) {
    cout << bridge[i] << " ";
  }
}

void Watch2PlayerCards(const TPlayer& playerA, const TPlayer& playerB)
{
  cout << endl;
  cout << "-----------------------------------------" <<endl;
  cout << "playA: " << playerA << endl;
  cout << "playB: " << playerB << endl;
  cout << "-----------------------------------------" <<endl;
  cout << endl << endl;
}

bool PlayGame(TPlayer& playerA, TPlayer& playerB)
{
  vector<TCard> bridge;
  while (playerA.HasCards() && playerB.HasCards()) {
    PlaceCardOnBridge(bridge, playerA);
    WatchBridge(bridge);
    Watch2PlayerCards(playerA, playerB);

    PlaceCardOnBridge(bridge, playerB);
    WatchBridge(bridge);
    Watch2PlayerCards(playerA, playerB);
  }
  if (playerA.HasCards()) {
    return true;
  }
  return false;
}
