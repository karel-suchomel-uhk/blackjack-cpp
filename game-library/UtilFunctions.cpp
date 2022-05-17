//
// Created by Karel Suchomel on 27.04.2022.
//

#include "UtilFunctions.h"
#include <cmath>
#include <vector>
#include <iostream>

double roundUp(double value, int decimal_places) {
  const double multiplier = pow(10.0, decimal_places);
  return round(value * multiplier) / multiplier;
}

bool isNumber(const std::string &s) {
  bool hitDecimal = false;
  for (char c: s) {
    if (c == '.' && !hitDecimal) // 2 '.' in string mean invalid
      hitDecimal = true; // first hit here, we forgive and skip
    else if (!isdigit(c))
      return false; // not ., not
  }
  return true;
}

void clear()
{
#if defined _WIN32
  system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
  system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (__APPLE__)
  system("clear");
#endif
}