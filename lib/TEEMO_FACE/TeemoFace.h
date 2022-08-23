#ifndef TEEMO_FACE_H
#define TEEMO_FACE_H

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

#define TFT_RST 16
#define TFT_CS  5// CS
#define TFT_RS  17

#define EYE_HEIGHT      60
#define EYE_WIDE        60
#define EYE_THICKMESS   2
#define EYE_RADIUS      15

class TeemoFace
{
private:
  uint16_t samples = 64;
  uint16_t fs = 1000;
  uint8_t lastValueFFT[512];

public:
  TeemoFace(/* args */);
  void begin();
  void point(uint8_t x, uint8_t y, uint8_t size, uint16_t color); //!

  void drawLineSize(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t size, uint16_t color);
  void fillLineSize(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t size, uint16_t color);
  void drawXSize(uint8_t x, uint8_t y, uint8_t size, 
                uint8_t h = EYE_HEIGHT, uint8_t w = EYE_WIDE, uint16_t color = TFT_GREEN);
  void fillXSize(uint8_t x, uint8_t y, uint8_t size, 
                uint8_t h = EYE_HEIGHT, uint8_t w = EYE_WIDE, uint16_t color = TFT_GREEN);
  void fillSquare(uint8_t x, uint8_t y, uint8_t h = EYE_HEIGHT, uint8_t w = EYE_WIDE,
                  uint8_t r = EYE_RADIUS ,uint16_t color = TFT_GREEN);
  void fillHey(uint8_t x, uint8_t y, uint8_t r = EYE_HEIGHT/2 ,uint16_t color = TFT_GREEN);
  void fillTriangleL(uint8_t x, uint8_t y, uint8_t h = EYE_HEIGHT, uint8_t w = EYE_WIDE,
                    uint16_t color = TFT_GREEN);
  void fillTriangleR(uint8_t x, uint8_t y, uint8_t h = EYE_HEIGHT, uint8_t w = EYE_WIDE,
                    uint16_t color = TFT_GREEN);
  void fillDoubt(uint8_t x, uint8_t y, int8_t vector = 0 , uint16_t color = TFT_GREEN);

  void eyesNormal(int8_t size, uint16_t color = TFT_GREEN);

  void eyesHappy(uint8_t r = EYE_HEIGHT/2 ,uint16_t color = TFT_GREEN);
  void eyesTriangle(int8_t size = 0, uint16_t color = TFT_GREEN);

  void eyesFuck(uint16_t color = TFT_GREEN);
  void eyesNothing(uint16_t color = TFT_GREEN);
  void eyesSurprise(uint16_t color = TFT_GREEN);
  void eyesDoubt(int8_t vectorL = 0, int8_t vectorR = 0, uint16_t color = TFT_GREEN);
  void eyesStress(int8_t size = 0, uint16_t color = TFT_GREEN, boolean onFill = true);
  void eyesYesNo(int8_t size = 15, uint16_t color = TFT_GREEN);

  void fftSound(double pfft[]);


  void setSample(uint8_t _sample);
  void setFS(uint16_t _fs);
  TFT_ILI9163C tft = TFT_ILI9163C(TFT_CS, TFT_RS,TFT_RST);
};


#endif