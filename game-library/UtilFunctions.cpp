//
// Created by Karel Suchomel on 27.04.2022.
//

#include "UtilFunctions.h"
#include <cmath>

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