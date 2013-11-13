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

#include <iostream>
#include <vector>
#include <queue>

#include "TPlayer.h"
#include "TPoker.h"
#include "CardFunc.h"
using namespace std;

int main()
{
  TPlayer PlayerA ("Qiang");
  TPlayer PlayerB ("Lin");


  TPoker poker;

  for (int i = 0; i < 3; i++) {
  cout << endl;
  }
  cout << "      ===============================================" << endl;
  cout << "      ====== Welcome to the awesome CARD GAME =======" << endl;
  cout << "      ===============================================" << endl;
  cout << endl;
  usleep(SLEEP_TIME);
  cout << poker << endl;
  cout << "      >>>>>>>>>Let's Shuffle the cards" << endl <<endl;
  poker.Shuffle();
  cout << "Now the poker is: " << poker << endl;
  cout << "      ------>Player A: " << PlayerA.GetName() << endl;
  cout << "      .......Deal:" << endl;
  PlayerA.Deal(poker);
  cout << PlayerA << endl;
  cout << endl;
  cout << "      ------>Player B: " << PlayerB.GetName() << endl;
  cout << "      .......Deal:" << endl;
  PlayerB.Deal(poker);
  cout << PlayerB << endl ;
  cout << endl;

  //Begin play game
  if(PlayGame(PlayerA, PlayerB) == true) {
    cout << PlayerA.GetName() << " Won !!!=======" << endl;
  }
  else {
    cout << PlayerB.GetName() << " Won !!!=======" << endl;
  }

  return 0;
}
