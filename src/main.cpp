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

#define TIME_SWICH_MODE   3000

#define TFT_RST   16
#define TFT_CS    5
#define TFT_RS    17

#define TOUCH_R   35
#define TOUCH_L   36
#define MIC       34
#define NEAR_SENSOR 39

TeemoMove teemoMove;
TeemoFace teemoFace;
TeemoFFT teemoFFT(MIC);

uint8_t mode = 0;

TaskHandle_t p_handle_face;
TaskHandle_t p_handle_dance;
TaskHandle_t p_handle_music;

int8_t getSwitch() {
  if (digitalRead(TOUCH_L)) return -1;
  if (digitalRead(TOUCH_R)) return 1;
  return 0;
}

void ControlOp(void* pParamter) {
  uint32_t lastTime = millis();
  while(true) {
    if(digitalRead(TOUCH_L) && digitalRead(TOUCH_R)) {
      lastTime = millis();
      while (digitalRead(TOUCH_L) && digitalRead(TOUCH_R))
      {
        if (millis() - lastTime > TIME_SWICH_MODE) {
          mode++;
          if (mode > 2) mode = 0;
          Serial.printf("mode: %d\n",mode);
          while (digitalRead(TOUCH_L) && digitalRead(TOUCH_R));
        }
      }
    }
    vTaskDelay(100);
  }
}

void DanceOp(void* pParamter) {
  int8_t typeMove = 0;
  uint8_t numberLoop;
  uint8_t speed;
  bool isModeRandom = true;
  while(true) {
    int8_t _swtich = getSwitch();
    if (_swtich != 0) {
      isModeRandom = false;
      teemoFace.tft.clearScreen(TFT_BLACK);
      teemoFace.eyesNormal(0);

      typeMove +=_swtich;
      if ((typeMove > 14) || (typeMove < 0)) isModeRandom = true;
    }

    if (isModeRandom) {
      typeMove = random(14);
      numberLoop = random(2, 5);
      speed = random(8, 12);
    }
    else 
    {
      numberLoop = 3;
      speed = 10;
    }
    Serial.printf("swtich: %d, typeMove: %d, numberLoop: %d, speed: %d\n",_swtich, typeMove, numberLoop, speed);

    switch (typeMove)
    {
      case 0: teemoMove.forward(numberLoop, speed);   break;
      case 1: teemoMove.backward(numberLoop, speed);  break;
      case 2: teemoMove.turnRigh(numberLoop, speed);  break;
      case 3: teemoMove.turnLeft(numberLoop, speed);  break;
      case 4: teemoMove.dance1(numberLoop, speed);   break;
      case 5: teemoMove.dance2(numberLoop, speed);  break;
      case 6: teemoMove.dance3(numberLoop, speed);  break;
      case 7: teemoMove.dance4(numberLoop, speed);  break;
      case 8: teemoMove.danceLeft1(numberLoop, speed);   break;
      case 9: teemoMove.danceRigh1(numberLoop, speed);  break;
      case 10: teemoMove.danceLeft2(numberLoop, speed);  break;
      case 11: teemoMove.danceRigh2(numberLoop, speed);  break;
      case 12: teemoMove.danceLeft3(numberLoop, speed);  break;
      case 13: teemoMove.danceRigh3(numberLoop, speed);  break;
      default:  break;
    }
    vTaskDelay(200);
  }
}

void FaceOp(void* pParamter) {
  bool isFirstSwitch = true;
  int8_t count = 0;
  while(true) {
    int8_t _swtich = getSwitch();
    if (_swtich != 0) {
      isFirstSwitch = true;
      teemoFace.tft.clearScreen(TFT_BLACK);
      count +=_swtich;
      if (count > 8) count = 0;
      if (count < 0) count = 8;
    }

    if (isFirstSwitch) {
      switch (count)
      {
      case 0:
        teemoFace.eyesNormal(0);
        break;

      case 1:
        teemoFace.eyesHappy();
        break;
      
      case 2:
        teemoFace.eyesTriangle(-10, TFT_GREEN);
        break;
      
      case 3:
        teemoFace.eyesFuck();
        break;

      case 4:
        teemoFace.eyesNothing();
        break;

      case 5:
        teemoFace.eyesSurprise();
        break;
      
      case 6:
        teemoFace.eyesDoubt(0, 0);
        break;

      case 7:
        teemoFace.eyesStress(10);
        break;

      case 8:
        teemoFace.eyesYesNo();
        break;

      default:
        break;
      }
      isFirstSwitch = false;
    }
    vTaskDelay(1);
  }
}

void MusicOp(void* pParamter) {
  while(true) {
    teemoFFT.sync();
    teemoFace.fftSound(teemoFFT.vReal);
    vTaskDelay(1);
  }
}

uint8_t RGB[3] = {0, 255, 0};

void setup() {
  Serial.begin(115200);

  pinMode(TOUCH_L, INPUT);
  pinMode(TOUCH_R, INPUT);

  teemoMove.begin();
  teemoFace.begin();

  xTaskCreatePinnedToCore(ControlOp, "ControlOp", 5000, NULL, 1, NULL, 0);
  xTaskCreatePinnedToCore(FaceOp, "FaceOp", 5000, NULL, 1, &p_handle_face, 1);
  xTaskCreatePinnedToCore(DanceOp, "DanceOp", 5000, NULL, 1, &p_handle_dance, 1);
  xTaskCreatePinnedToCore(MusicOp, "MusicOp", 5000, NULL, 1, &p_handle_music, 1);
 
  // teemoFace.tft.fillRect(0, 0, 5, 10, TFT_BLUE);  // tft.begin();
  // delay(2000);
  // tft.setRotation(1);
  // tft.fillRect(0,0,160,128, TFT_WHITE);
  // tft.drawRGBBitmap(20, 0, vulcan, 121, 128);

}

void loop() {
  switch (mode)
  {
  case 0:
    vTaskSuspend(p_handle_face);
    vTaskSuspend(p_handle_music);
    vTaskResume(p_handle_dance);
    break;

  case 1:
    teemoMove.defaul();
    vTaskSuspend(p_handle_dance);
    vTaskSuspend(p_handle_music);
    vTaskResume(p_handle_face);
    break;

  case 2:
    vTaskSuspend(p_handle_dance);
    vTaskSuspend(p_handle_face);
    vTaskResume(p_handle_music);
    break;
  
  default:
    break;
  }
  vTaskDelay(100);
}