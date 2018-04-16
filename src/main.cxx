#include <iostream>

#include "Render.h"
#include "Figures/Detail.h"

int main(int argc, char **argv) {

  Render r;

  r.addObject(std::make_shared<Detail>(VPoint(300, 400), 150,  sf::Color::Red));
  r.addObject(std::make_shared<Detail>(VPoint(1000,600),  75, sf::Color::Blue));

  r.startSimulation();
}