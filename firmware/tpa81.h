#pragma once

#include "arduinoConfig.h"

class TPASensor {
public:
  TPASensor();
  byte read(const byte);
  byte val[9];

};
