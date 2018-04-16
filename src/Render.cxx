#include "Render.h"

#include <SFML/Graphics.hpp>

void Render::resetCamera() {
  this->start = VPoint(0,0);
  this->end   = VPoint(1280,720);
}

void Render::zoomIn(float ratio) {

}

void Render::zoomOut(float ratio) {

}

void Render::move(VPoint dm) {
  start += dm;
  end += dm;
}

RPoint Render::mapToReal(VPoint v) {
    VPoint offset(v.x - start.x, v.y - start.y);
    offset.x /= end.x - start.x;
    offset.y /= end.y - start.y;
    offset.x *= resolution.x;
    offset.y *= resolution.y;
    return RPoint(offset.x, offset.y);
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
    while (win.pollEvent(event)) {
      switch(event.type) {
        case sf::Event::KeyPressed:
          switch (event.key.code) {
            case sf::Keyboard::Left:
              move(VPoint(-100, 0));
            break;
            case sf::Keyboard::Right:
              move(VPoint( 100, 0));
            break;
            case sf::Keyboard::Up:
              move(VPoint(0, -100));
            break;
            case sf::Keyboard::Down:
              move(VPoint(0, 100));
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
        sf::CircleShape circ(circle.radius);
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