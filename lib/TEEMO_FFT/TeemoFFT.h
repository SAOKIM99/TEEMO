#ifndef TEEMO_FFT_H
#define TEEMO_FFT_H

#include <arduinoFFT.h>

#define SAMPLES             64             //Must be a power of 2
#define SAMPLING_FREQUENCY  1000 //Hz, must be less than 10000 due to ADC

class TeemoFFT
{
private:
  uint8_t adcPin;
  arduinoFFT FFT = arduinoFFT();
  unsigned int sampling_period_us = round(1000000*(1.0/SAMPLING_FREQUENCY));
  unsigned long microseconds;

public:
  TeemoFFT(uint8_t _adcPin);
  void sync();
  
  double vReal[SAMPLES];
  double vImag[SAMPLES];
};

#endif