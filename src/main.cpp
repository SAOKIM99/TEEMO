#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "TeemoMove.h"
#include "HighBeam.h"
#include "TeemoFace.h"
#include "TeemoFFT.h"

#define TOUCH_R   35
#define TOUCH_L   36
#define MIC       34
#define NEAR_SENSOR 39

TeemoMove teemoMove;
TeemoFace teemoFace;
TeemoFFT teemoFFT(MIC);

TaskHandle_t task_handle_pace;
TaskHandle_t task_handle_fft;
TaskHandle_t task_handle_walk;
TaskHandle_t task_handle_main;

void FaceOP(void* pParamter) {
  vTaskSuspend(NULL);
  for(;;) {

    vTaskDelay(1);
  }
}

void FFTOP (void* pParamater) {
  vTaskSuspend(NULL);
  for(;;) {

    vTaskDelay(1);
  }
}

void walkOP(void* pParamter) {
  vTaskSuspend(NULL);
  for(;;) {

    vTaskDelay(1);
  }
}

void mainOP(void* pParamter) {
  for(;;) {

    vTaskDelay(1);
  }
}

void setup() {
  Serial.begin(115200);
  teemoMove.begin();
  teemoFace.begin();

  xTaskCreatePinnedToCore(FaceOP, "FaceOP", 1000, NULL, 1, &task_handle_pace, 0);
  xTaskCreatePinnedToCore(FFTOP, "FFTOP", 1000, NULL, 1, &task_handle_fft, 0);
  xTaskCreatePinnedToCore(walkOP, "walkOP", 1000, NULL, 1, &task_handle_walk, 0);
  xTaskCreatePinnedToCore(mainOP, "mainOP", 1000, NULL, 1, &task_handle_main, 1);
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

}