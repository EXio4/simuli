#include "Render.h"

#include <SFML/Graphics.hpp>

void Render::resetCamera() {
  this->start = VPoint(0,0);
  this->end   = VPoint(1280,720);
}

void Render::zoom(float ratio) {

  VPoint delta = ((end - start) * VPoint(ratio) - (end - start)) / VPoint(2);

  start -= delta;
  end   += delta;
}


void Render::move(VPoint dm) {
  start += dm;
  end += dm;
}

RPoint Render::mapToReal(VPoint v) {
    VPoint offsetV = VPoint(resolution.x, resolution.y) * (v - start) / (end - start);
    return RPoint(offsetV.x, offsetV.y);
}


Render::Render() {
  resetCamera();
}

void Render::addObject(std::shared_ptr<Object> obj) {
  entities.push_back(obj);
}

void Render::startSimulation() {

  sf::RenderWindow win(sf::VideoMode(1280,720), "Simuli");
  resolution = RPoint(1280, 720);

  while (win.isOpen()) {
    sf::Event event;
    VPoint mov = (end - start) / VPoint(20);

    while (win.pollEvent(event)) {
      switch(event.type) {
        case sf::Event::KeyPressed:
          switch (event.key.code) {
            case sf::Keyboard::Left:
              move(mov * VPoint(-1,0));
            break;
            case sf::Keyboard::Right:
              move(mov * VPoint( 1,0));
            break;
            case sf::Keyboard::Up:
              move(mov * VPoint(0,-1));
            break;
            case sf::Keyboard::Down:
              move(mov * VPoint(0, 1));
            break;
            case sf::Keyboard::A:
              zoom(1.2);
            break;
            case sf::Keyboard::Z:
              zoom(0.8);
            break;
          }
        break;
        case sf::Event::Closed:
          win.close();
        break;
      }
    }

    win.clear();

    for (auto obj : entities) {
    
      sf::Color color = obj->getColor();
      CollisionData data = obj->getCollisionData();

      for (auto circle : data.circles) {
        RPoint r = mapToReal(circle.center);
        auto rad_scale = mapToReal(circle.center + VPoint(circle.radius)) - r;
        sf::CircleShape circ(1);
        circ.setScale(rad_scale.x,rad_scale.y);
        circ.setPosition(r.x, r.y);
        circ.setFillColor(color);
        win.draw(circ);
      }
      for (auto rectangle : data.rectangles) {
        RPoint r1 = mapToReal(rectangle.p1);
        RPoint r2 = mapToReal(rectangle.p2);
        sf::RectangleShape rect(sf::Vector2f(r2.x-r1.x, r2.y-r1.y));
        rect.setPosition(r1.x,r1.y);
        rect.setFillColor(color);
        win.draw(rect);
      }
    }

    
    win.display();
  }


};