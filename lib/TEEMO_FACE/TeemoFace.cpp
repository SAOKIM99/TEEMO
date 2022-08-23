#include <TeemoFace.h>

TeemoFace::TeemoFace() {

}

void TeemoFace::begin() {
  tft.begin();
  tft.setRotation(1);
  tft.clearScreen(TFT_BLACK);

}

void TeemoFace::point(uint8_t x, uint8_t y, uint8_t size, uint16_t color) {
  tft.fillRect(x, y, size * 2, size * 6, color);
  tft.fillCircle(x + size, y + size * 6 + size*2, size, color);
}

void TeemoFace::drawLineSize(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t size, uint16_t color) {
  if (x1 > x2) {
    _swap_int16_t(x1, x2);
    _swap_int16_t(y1, y2);
  }
  bool a = y1 < y2;
  tft.drawLine(x1, y1, x2, y2, color);
  
  for (uint8_t i = 1; i < size; i++) {
    if (i % 2 == 0) {
      if (a) {
        x1--;
        y2++;
      }
      else {
        y1++;
        x2++;
      }
    }
    else {
      if (a) {
        y1++;
        x2--;
      }
      else {
        x1++;
        y2++;
      }
    }
    // Serial.printf("%d %d %d %d\n", x1, y1, x2, y2);
    tft.drawPixel(x1, y1, color);
    tft.drawPixel(x2, y2, color);
  }
  if (size > 1)  tft.drawLine(x1, y1, x2, y2, color);
}

void TeemoFace::fillLineSize(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t size, uint16_t color) {
  if (x1 > x2) {
    _swap_int16_t(x1, x2);
    _swap_int16_t(y1, y2);
  }

  bool a = y1 < y2;

  for (uint8_t i = 0; i < size; i++) {
    if (i % 2 == 0) {
      if (a) {
        x1--;
        y2++;
      }
      else {
        y1++;
        x2++;
      }
    }
    else {
      if (a) {
        y1++;
        x2--;
      }
      else {
        x1++;
        y2++;
      }
    }
    // Serial.printf("%d %d %d %d\n", x1, y1, x2, y2);
    tft.drawLine(x1, y1, x2, y2, color);
  }
  // a = -1;
  // TeemoFace.tft.drawLine(40, 40, 80, 80, TFT_GREEN);
  // TeemoFace.tft.drawLine(40, 41, 79, 80, TFT_GREEN);
  // TeemoFace.tft.drawLine(39, 41, 79, 81, TFT_GREEN);
  // TeemoFace.tft.drawLine(39, 42, 78, 81, TFT_GREEN);
  // TeemoFace.tft.drawLine(38, 42, 78, 82, TFT_GREEN);

  // a = 1;                 x1, y1, x2, y2
  // TeemoFace.tft.drawLine(40, 80, 80, 40, TFT_GREEN);
  // TeemoFace.tft.drawLine(41, 80, 80, 41, TFT_GREEN);
  // TeemoFace.tft.drawLine(41, 81, 81, 41, TFT_GREEN);
  // TeemoFace.tft.drawLine(42, 81, 81, 42, TFT_GREEN);
  // TeemoFace.tft.drawLine(42, 82, 82, 42, TFT_GREEN);
}

void TeemoFace::drawXSize(uint8_t x, uint8_t y, uint8_t size, uint8_t h, uint8_t w, uint16_t color) {
  x -= w / 2;
  y -= h / 2;
  drawLineSize(x+size/2, y, x+w, y+h-size/2, size, color);
  drawLineSize(x, y+h-size/2, x+w-size/2, y, size, color);
}

void TeemoFace::fillXSize(uint8_t x, uint8_t y, uint8_t size, uint8_t h, uint8_t w, uint16_t color) {
  x -= w / 2;
  y -= h / 2;
  fillLineSize(x+size/2, y, x+w, y+h-size/2, size, color);
  fillLineSize(x, y+h-size/2, x+w-size/2, y, size, color);
}

void TeemoFace::fillSquare(uint8_t x, uint8_t y, uint8_t h, uint8_t w, 
                          uint8_t r, uint16_t color) {
  x -= w / 2;
  y -= h / 2;
  // tft.fillRoundRect(8,32, 64, 64, 22, TFT_BROWN);
  // tft.fillRoundRect(10, 34, 60, 60, 20, TFT_GREEN);
  // tft.fillRoundRect(x-EYE_THICKMESS, y-EYE_THICKMESS, 
  //                   w+EYE_THICKMESS*2, h+EYE_THICKMESS*2, 
  //                   r+EYE_THICKMESS, borderColor);
  tft.fillRoundRect(x, y, w, h, r, color);
}

void TeemoFace::fillHey(uint8_t x, uint8_t y, uint8_t r, uint16_t color) {
  tft.fillCircle(x, y, r, color);
  tft.fillCircle(x, y+10, r, TFT_BLACK);
  // eyeSquare(x, y);
  // eyeSquare(x, y + 10, EYE_HEIGHT - 20, EYE_WIDE, EYE_RADIUS - 5, TFT_BLACK);
}

void TeemoFace::fillTriangleL(uint8_t x, uint8_t y, uint8_t h, uint8_t w, uint16_t color) {
  // TeemoFace.tft.fillTriangle(10, 44, 10, 94, 80, 94, TFT_BLUE);
  x -= w / 2;
  y -= h / 2;
  tft.fillTriangle(x, y , x, y + h, x + w, y + h, color);
}

void TeemoFace::fillTriangleR(uint8_t x, uint8_t y, uint8_t h, uint8_t w, uint16_t fillColor) {
  // TeemoFace.tft.fillTriangle(10, 44, 10, 94, 80, 94, TFT_BLUE);
  x += w / 2;
  y -= h / 2;
  tft.fillTriangle(x, y , x, y + h, x - w, y + h, fillColor);
}

void TeemoFace::fillDoubt(uint8_t x, uint8_t y, int8_t vector , uint16_t color) {
  uint8_t px = x - 12 / 2 + vector;
  uint8_t py = y - 30 / 2;
  x -= EYE_WIDE / 2;
  y -= EYE_HEIGHT / 2;
  tft.fillRect(x, y, EYE_WIDE, 6, color);
  tft.fillRect(x, y + EYE_WIDE - 6 , EYE_WIDE, 6, color);
  tft.setRotation(3);
  tft.fillRoundRect(px, py, 12, 30, 6, color);
  tft.setRotation(1);
  // tft.fillRect(px, py, 12, 30, color);
}

void TeemoFace::eyesNormal(int8_t size, uint16_t color) {
  fillSquare(40, 64, EYE_HEIGHT + size*2, EYE_WIDE + size*2, EYE_RADIUS, color);
  fillSquare(120, 64, EYE_HEIGHT + size*2, EYE_WIDE + size*2, EYE_RADIUS, color);
}

void TeemoFace::eyesHappy(uint8_t r, uint16_t color) {
  fillHey(40, 64, r, color);
  fillHey(120, 64, r, color);
}

void TeemoFace::eyesTriangle(int8_t size, uint16_t color) {
  fillTriangleL(40, 64, EYE_HEIGHT + size/2, EYE_WIDE + size/2, color);
  fillTriangleR(120, 64, EYE_HEIGHT + size/2, EYE_WIDE + size/2, color);
}


void TeemoFace::eyesFuck(uint16_t color) {
  tft.fillCircle(40, 50, 10, color);
  tft.fillCircle(120, 50, 10, color);
  tft.setRotation(2);
  tft.fillCircleHelper(80, 78, 40, 1, 5, color);
  tft.fillCircleHelper(70, 78, 40, 1, 5, TFT_BLACK);
  tft.setRotation(1);
}

void TeemoFace::eyesNothing(uint16_t color) {
  fillSquare(40, 50, 10, 50, 5, color);
  fillSquare(120, 50, 10, 50, 5, color);
  fillSquare(80, 100, 10, 80, 5, color);
}

void TeemoFace::eyesSurprise(uint16_t color) {
  tft.fillCircle(40, 64, 30, color);
  tft.fillCircle(120, 64, 30, color);
  point(145, 5, 3, color);
}

void TeemoFace::eyesDoubt(int8_t vectorL, int8_t vectorR, uint16_t color) {
  fillDoubt(40, 64, vectorL, color);
  fillDoubt(120, 64, vectorR, color);
}

void TeemoFace::eyesStress(int8_t size, uint16_t color, boolean onFill) {
  if (onFill) {
    fillXSize(40, 64, 15, EYE_HEIGHT + size, EYE_WIDE + size, color);
    fillXSize(120, 64, 15, EYE_HEIGHT + size, EYE_WIDE + size, color);
    return;
  }
  drawXSize(40, 64, 15, EYE_HEIGHT + size, EYE_WIDE + size, color);
  drawXSize(120, 64, 15, EYE_HEIGHT + size, EYE_WIDE + size, color);
}

void TeemoFace::eyesYesNo(int8_t size, uint16_t color) {
  tft.fillArc(40, 64, EYE_WIDE/2, EYE_WIDE/2 - size, 0, 360, color);
  fillXSize(120, 64, size*2, EYE_HEIGHT, EYE_WIDE, color);
}


void TeemoFace::fftSound(double pfft[]) {
  for (uint8_t i = 0; i < (samples/2); i++)
  {
    uint8_t valueNow = ((uint16_t)pfft[i] * 127) / 1000;
    valueNow = valueNow > 127 ? 127 : valueNow;
    
    int8_t buff = valueNow - lastValueFFT[i];
    uint8_t point;
    uint16_t _color;
    if (buff < 0) {
      _color = TFT_BLACK;
      point = lastValueFFT[i];
    }
    else {
      _color = TFT_BLUE;
      point = valueNow;
    }
    tft.writeFillRect(i*5, 127 - point, 5, abs(buff), _color);
    lastValueFFT[i] = valueNow;
  }
}

void TeemoFace::setSample(uint8_t _sample) {
  samples = _sample;
}

void TeemoFace::setFS(uint16_t _fs) {
  fs = _fs;
}