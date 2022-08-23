#include <Arduino.h>
#include "TeemoMove.h"
#include "HighBeam.h"
#include "TeemoFace.h"
#include "freertos/FreeRTOS.h"
#include "TeemoFFT.h"

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

// Color definitions It is BRG order but not RGB order in the memory of the 1.8inch TFT LCD
// #define	BLACK   0x0000
// #define	BLUE    0xF800
// #define	RED     0x001F
// #define	GREEN   0x07E0
// #define CYAN    0xFFE0
// #define MAGENTA 0xF81F
// #define YELLOW  0x07FF
// #define WHITE   0xFFFF

#define TFT_RST 16
#define TFT_CS  5// CS
#define TFT_RS  17

#define TOUCH_R   35
#define TOUCH_L   36
#define MIC       34
#define NEAR_SENSOR 39

TeemoMove teemoMove;
TeemoFace teemoFace;
TeemoFFT teemoFFT(MIC);
uint8_t RGB[3] = {0, 255, 0};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  teemoMove.begin();
  teemoFace.begin();
 
  // teemoFace.tft.fillRect(0, 0, 5, 10, TFT_BLUE);  // tft.begin();
  //delay(2000);
  // tft.setRotation(1);
  // tft.fillRect(0,0,160,128, TFT_WHITE);
  // tft.drawRGBBitmap(20, 0, vulcan, 121, 128);

  // teemoFace.eyesNormal(0);
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesHappy();
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesTriangle(-10, TFT_GREEN);
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesDoubt(0, 0);
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesFuck();
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesNothing();
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesSurprise();
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesStress(20, TFT_GREEN, false);
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesYesNo();
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);




  // teemoMove.forward(5, 10);
  // delay(500);
  // teemoMove.backward(5, 10);
  // delay(500);
  // teemoMove.turnRigh(5, 10);
  // delay(500);
  // teemoMove.turnLeft(5, 10);
  // delay(500);
  // teemoMove.dance1(3, 10);
  // delay(500);
  // teemoMove.dance2(3, 10);
  // delay(500);
  // teemoMove.danceLeft1(5,10);
  // delay(500);
  // teemoMove.danceRigh1(5,10);
  // delay(500);
  // teemoMove.dance3(5, 10);
  // delay(500);
  // teemoMove.danceLeft2(5, 10);
  // delay(500);
  // teemoMove.danceRigh2(5,10);
  // delay(500);
  // teemoMove.danceRigh3(5, 10);
  // delay(500);
  // teemoMove.danceLeft3(5, 10);
  // delay(500);
  // teemoMove.dance4(5, 10);
  //  teemoFace.eyesHappy();
}

void loop() {
  teemoFFT.sync();
  teemoFace.fftSound(teemoFFT.vReal);
  // delay(10);
  // teemoFace.eyesNormal(0);
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesHappy();
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesTriangle(-10, TFT_GREEN);
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesDoubt(0, 0);
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesFuck();
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesNothing();
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesSurprise();
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);


  // teemoFace.eyesYesNo();
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);

  // teemoFace.eyesStress(0);
  // delay(1000);
  // teemoFace.tft.clearScreen(TFT_BLACK);
  //  teemoMove.forward(5, 10);
  // delay(500);
  // teemoMove.backward(5, 10);
  // delay(500);
  // teemoMove.turnRigh(5, 10);
  // delay(500);
  // teemoMove.turnLeft(5, 10);
  // delay(500);
  // teemoMove.dance1(3, 10);
  // delay(500);
  // teemoMove.dance2(3, 10);
  // delay(500);
  // teemoMove.danceLeft1(5,10);
  // delay(500);
  // teemoMove.danceRigh1(5,10);
  // delay(500);
  // teemoMove.dance3(5, 10);
  // delay(500);
  // teemoMove.danceLeft2(5, 10);
  // delay(500);
  // teemoMove.danceRigh2(5,10);
  // delay(500);
  // teemoMove.danceRigh3(5, 10);
  // delay(500);
  // teemoMove.danceLeft3(5, 10);
  // delay(500);
  // teemoMove.dance4(5, 10);
  // delay(500);
}