#include "TeemoMove.h"
TeemoMove::TeemoMove(/* args */) {

}

void TeemoMove::begin() {
  ServoL1.attach(L1);
  ServoL2.attach(L2);
  ServoR1.attach(R1);
  ServoR2.attach(R2);
	delay(10);
  setServo(1, 90);
  setServo(2, 90);
  setServo(3, 90);
  setServo(4, 90);
}

void TeemoMove::defaul() {
  servoNow(1, 2, 3, 4, 90, 90, 90, 90, 5);
}

void TeemoMove::setServo(uint8_t pSevor, uint8_t _angle) {
  switch (pSevor)
  {
  case 1:
    _angle += ERROR_L1;
    _angle = constrain(_angle, MIN_L1, MAX_L1);
    ServoL1.write(_angle);
    break;
  case 2:
    _angle += ERROR_L2;
    _angle = constrain(_angle, MIN_L2, MAX_L2);
    ServoL2.write(_angle);
    break;
  case 3:
    _angle += ERROR_R1;
    _angle = constrain(_angle, MIN_R1, MAX_R1);
    ServoR1.write(_angle);
    break;
  case 4:
    _angle = 180 - _angle;
    _angle += ERROR_R2;
    _angle = constrain(_angle, MIN_R2, MAX_R2);
    ServoR2.write(_angle);
    break;
  default:
    break;
  }
}

void TeemoMove::servoNow(uint8_t pSevor, uint8_t _angle, uint16_t _speed) {
  do {
    if (angleNow[pSevor] > _angle) setServo(pSevor, --angleNow[pSevor]);
    else if (angleNow[pSevor] < _angle) setServo(pSevor, ++angleNow[pSevor]);
    // vTaskDelay(_speed);
    delay(_speed);
  }
  while (angleNow[pSevor] != _angle);
}

void TeemoMove::servoNow(uint8_t pSevor1, uint8_t pSevor2, uint8_t _angle1, uint8_t _angle2, uint16_t _speed) {
  do {
    if (angleNow[pSevor1] > _angle1) setServo(pSevor1, --angleNow[pSevor1]);
    else if (angleNow[pSevor1] < _angle1) setServo(pSevor1, ++angleNow[pSevor1]);

    if (angleNow[pSevor2] > _angle2) setServo(pSevor2, --angleNow[pSevor2]);
    else if (angleNow[pSevor2] < _angle2) setServo(pSevor2, ++angleNow[pSevor2]);
    // vTaskDelay(_speed);
    delay(_speed);
  }
  while ((angleNow[pSevor1] != _angle1) || (angleNow[pSevor2] != _angle2));
}

void TeemoMove::servoNow(uint8_t pSevor1, uint8_t pSevor2, uint8_t pSevor3, uint8_t _angle1, uint8_t _angle2, uint8_t _angle3, uint16_t _speed) {
  do {
    if (angleNow[pSevor1] > _angle1) setServo(pSevor1, --angleNow[pSevor1]);
    else if (angleNow[pSevor1] < _angle1) setServo(pSevor1, ++angleNow[pSevor1]);

    if (angleNow[pSevor2] > _angle2) setServo(pSevor2, --angleNow[pSevor2]);
    else if (angleNow[pSevor2] < _angle2) setServo(pSevor2, ++angleNow[pSevor2]);

    if (angleNow[pSevor3] > _angle3) setServo(pSevor3, --angleNow[pSevor3]);
    else if (angleNow[pSevor3] < _angle3) setServo(pSevor3, ++angleNow[pSevor3]);
    // vTaskDelay(_speed);
    delay(_speed);
  }
  while ((angleNow[pSevor1] != _angle1) || (angleNow[pSevor2] != _angle2) || (angleNow[pSevor3] != _angle3));
}

void TeemoMove::servoNow(uint8_t pSevor1, uint8_t pSevor2, uint8_t pSevor3, uint8_t pSevor4, uint8_t _angle1, uint8_t _angle2, uint8_t _angle3, uint8_t _angle4, uint16_t _speed) {
  do {
    if (angleNow[pSevor1] > _angle1) setServo(pSevor1, --angleNow[pSevor1]);
    else if (angleNow[pSevor1] < _angle1) setServo(pSevor1, ++angleNow[pSevor1]);

    if (angleNow[pSevor2] > _angle2) setServo(pSevor2, --angleNow[pSevor2]);
    else if (angleNow[pSevor2] < _angle2) setServo(pSevor2, ++angleNow[pSevor2]);

    if (angleNow[pSevor3] > _angle3) setServo(pSevor3, --angleNow[pSevor3]);
    else if (angleNow[pSevor3] < _angle3) setServo(pSevor3, ++angleNow[pSevor3]);

    if (angleNow[pSevor4] > _angle4) setServo(pSevor4, --angleNow[pSevor4]);
    else if (angleNow[pSevor4] < _angle4) setServo(pSevor4, ++angleNow[pSevor4]);
    // vTaskDelay(_speed);
    delay(_speed);
  }
  while ((angleNow[pSevor1] != _angle1) || (angleNow[pSevor2] != _angle2) || (angleNow[pSevor3] != _angle3) || (angleNow[pSevor4] != _angle4));
}

void TeemoMove::forward(uint8_t number, uint8_t _speed) {
  for (uint8_t i = 0; i < number; i++) {
    servoNow(4, 110, _speed);
    servoNow(2, 70, _speed);
    servoNow(1, 3, 80, 80, _speed);
    servoNow(2, 90, _speed);
    servoNow(4, 90, _speed);
    servoNow(2, 110, _speed);
    servoNow(4, 70, _speed);
    servoNow(1, 3, 100, 100, _speed);
    servoNow(4, 90, _speed);
    servoNow(2, 90, _speed);
  }
   servoNow(1, 2, 3, 4, 90, 90, 90, 90, _speed);
}

void TeemoMove::backward(uint8_t number, uint8_t _speed) {
  for (uint8_t i = 0; i < number; i++) {
    servoNow(4, 110, _speed);
    servoNow(2, 70, _speed);
    servoNow(1, 3, 100, 100, _speed);
    servoNow(2, 90, _speed);
    servoNow(4, 90, _speed);
    servoNow(2, 110, _speed);
    servoNow(4, 70, _speed);
    servoNow(1, 3, 80, 80, _speed);
    servoNow(4, 90, _speed);
    servoNow(2, 90, _speed);
  }
  servoNow(1, 2, 3, 4, 90, 90, 90, 90, _speed);
}

void TeemoMove::turnRigh(uint8_t number, uint8_t _speed) {
  for (uint8_t i = 0; i < number; i++) {
    servoNow(4, 110, _speed);
    servoNow(2, 70, _speed);
    servoNow(1, 3, 100, 80, _speed);
    servoNow(2, 90, _speed);
    servoNow(4, 90, _speed);
    servoNow(2, 110, _speed);
    servoNow(4, 70, _speed);
    servoNow(1, 3, 80, 100, _speed);
    servoNow(4, 90, _speed);
    servoNow(2, 90, _speed);
  }
  servoNow(1, 2, 3, 4, 90, 90, 90, 90, _speed);
}

void TeemoMove::turnLeft(uint8_t number, uint8_t _speed) {
  for (uint8_t i = 0; i < number; i++) {
    servoNow(4, 110, _speed);
    servoNow(2, 70, _speed);
    servoNow(1, 3, 80, 100, _speed);
    servoNow(2, 90, _speed);
    servoNow(4, 90, _speed);
    servoNow(2, 110, _speed);
    servoNow(4, 70, _speed);
    servoNow(1, 3, 100, 80, _speed);
    servoNow(4, 90, _speed);
    servoNow(2, 90, _speed);
  }
  servoNow(1, 2, 3, 4, 90, 90, 90, 90, _speed);
}

void TeemoMove::dance1(uint8_t number, uint8_t _speed) {
  for (uint8_t i = 0; i < number; i++) {
    servoNow(1, 110, _speed);
    servoNow(3, 110, _speed);
    servoNow(1, 70, _speed);
    servoNow(3, 70, _speed);
    
    servoNow(1, 3, 110, 110, _speed);
    servoNow(1, 3, 70, 70, _speed);
    servoNow(1, 3, 110, 110, _speed);
    servoNow(1, 3, 70, 70, _speed);
  }
  servoNow(1, 2, 3, 4, 90, 90, 90, 90, _speed);
}

void TeemoMove::dance2(uint8_t number, uint8_t _speed) {
  for (uint8_t i = 0; i < number; i++) {
    servoNow(1, 70, _speed);
    servoNow(3, 110, _speed);
    servoNow(1, 110, _speed);
    servoNow(3, 70, _speed);
    servoNow(1, 3, 70, 110, _speed);
    servoNow(1, 3, 110, 70, _speed);
    servoNow(1, 3, 70, 110, _speed);
    servoNow(1, 3, 110, 70, _speed);
  }
  servoNow(1, 2, 3, 4, 90, 90, 90, 90, _speed);
}

void TeemoMove::dance3(uint8_t number, uint8_t _speed) {
  for (uint8_t i = 0; i < number; i++) {
    servoNow(2, 120, _speed);
    servoNow(2, 90, _speed);
    servoNow(4, 120, _speed);
    servoNow(4, 90, _speed);
  }
  servoNow(1, 2, 3, 4, 90, 90, 90, 90, _speed);
}

void TeemoMove::dance4(uint8_t number, uint8_t _speed) {
  servoNow(4, 10, _speed);
  servoNow(2, 30, _speed);
  servoNow(4, 30, _speed);
  for (uint8_t i = 0; i < number; i++) {
    servoNow(1, 3, 70, 70, _speed);
    servoNow(1, 3, 110, 110, _speed);
    servoNow(1, 3, 90, 90, _speed);
    servoNow(1, 3, 70, 110, _speed);
    servoNow(1, 3, 110, 70, _speed);
    servoNow(1, 3, 90, 90, _speed);
  }
  servoNow(1, 2, 3, 4, 90, 90, 90, 90, _speed);
}

void TeemoMove::danceLeft1(uint8_t number, uint8_t _speed) {
  servoNow(2, 120, _speed);
  servoNow(4, 60, _speed);
  for (uint8_t i = 0; i < number; i++) {
    servoNow(2, 40, _speed);
    servoNow(2, 140, _speed);
  }
  servoNow(1, 2, 3, 4, 90, 90, 90, 90, _speed);
}

void TeemoMove::danceRigh1(uint8_t number, uint8_t _speed) {
  servoNow(4, 120, _speed);
  servoNow(2, 60, _speed);
  for (uint8_t i = 0; i < number; i++) {
    servoNow(4, 40, _speed);
    servoNow(4, 140, _speed);
  }
  servoNow(1, 2, 3, 4, 90, 90, 90, 90, _speed);
}

void TeemoMove::danceLeft2(uint8_t number, uint8_t _speed) {
  for (uint8_t i = 0; i < number; i++) {
    servoNow(2, 50, _speed);
    servoNow(2, 90, _speed);
  }
  servoNow(1, 2, 3, 4, 90, 90, 90, 90, _speed);
}

void TeemoMove::danceRigh2(uint8_t number, uint8_t _speed) {
  for (uint8_t i = 0; i < number; i++) {
    servoNow(4, 50, _speed);
    servoNow(4, 90, _speed);
  }
  servoNow(1, 2, 3, 4, 90, 90, 90, 90, _speed);
}

void TeemoMove::danceLeft3(uint8_t number, uint8_t _speed) {
  servoNow(2, 110, _speed);
  servoNow(4, 70, _speed);
  for (uint8_t i = 0; i < number; i++) {
    servoNow(2, 100, _speed);
    servoNow(1, 3, 120, 120, _speed);
    servoNow(2, 130, _speed);
    servoNow(2, 100, _speed);
    servoNow(1, 3, 60, 60, _speed);
    servoNow(2, 130, _speed);
  }
  servoNow(1, 2, 3, 4, 90, 90, 90, 90, _speed);
}

void TeemoMove::danceRigh3(uint8_t number, uint8_t _speed) {
  servoNow(4, 110, _speed);
  servoNow(2, 70, _speed);
  for (uint8_t i = 0; i < number; i++) {
    servoNow(4, 100, _speed);
    servoNow(1, 3, 60, 60, _speed);
    servoNow(4, 130, _speed);
    servoNow(4, 100, _speed);
    servoNow(1, 3, 120, 120, _speed);
    servoNow(4, 130, _speed);
  }
  servoNow(1, 2, 3, 4, 90, 90, 90, 90, _speed);
}