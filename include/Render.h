#pragma once

#include "Object.h"

#include <vector>
#include <memory>

class Render {
private:
  std::vector<std::shared_ptr<Object>> entities;

  VPoint start;
  VPoint end;
  RPoint resolution;

  void resetCamera();

  void zoomIn(float ratio);
  void zoomOut(float ratio);

  void move(VPoint dm);

  RPoint mapToReal(VPoint v);

public:
  Render();

  void addObject(std::shared_ptr<Object> obj);

  void startSimulation();

};