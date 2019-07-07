#include"Circle.h"
#include"TriCircle.h"

double TriCircle::TArea() {
  double totalArea;

  totalArea = c0.CArea() + c1.CArea() + c2.CArea();
  return totalArea;
}
double TriCircle::TLen() {
  double totalLen;

  totalLen = c0.CLen() + c1.CLen() + c2.CLen();
  return totalLen;
}