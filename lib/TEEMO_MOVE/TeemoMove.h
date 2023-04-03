#ifndef TEEMO_MOVE_H
#define TEEMO_MOVE_H

#include <ESP32Servo.h>

#define L1  25
#define L2  27
#define R1  12
#define R2  32

#define ERROR_L1  10
#define ERROR_L2  10
#define ERROR_R1  0
#define ERROR_R2  0

#define MIN_L1  60
#define MAX_L1  120
#define MIN_L2  5
#define MAX_L2  180
#define MIN_R1  60
#define MAX_R1  120
#define MIN_R2  10
#define MAX_R2  180


class TeemoMove
{
	public:
		TeemoMove();
		void begin();
		void servoNow(uint8_t pSevor, uint8_t _angle, uint16_t _speed);
		void servoNow(uint8_t pSevor1, uint8_t pSevor2, uint8_t _angle1, uint8_t _angle2, uint16_t _speed);
		void servoNow(uint8_t pSevor1, uint8_t pSevor2, uint8_t pSevor3, uint8_t _angle1, uint8_t _angle2, uint8_t _angle3, uint16_t _speed);
		void servoNow(uint8_t pSevor1, uint8_t pSevor2, uint8_t pSevor3, uint8_t pSevor4, uint8_t _angle1, uint8_t _angle2, uint8_t _angle3, uint8_t _angle4, uint16_t _speed);
		void defaul();
		void forward(uint8_t number, uint8_t _speed);
		void backward(uint8_t number, uint8_t _speed);
		void turnRigh(uint8_t number, uint8_t _speed);
		void turnLeft(uint8_t number, uint8_t _speed);
		void dance1(uint8_t number, uint8_t _speed);
		void dance2(uint8_t number, uint8_t _speed);
		void dance3(uint8_t number, uint8_t _speed);
		void dance4(uint8_t number, uint8_t _speed);
		void danceLeft1(uint8_t number, uint8_t _speed);
		void danceRigh1(uint8_t number, uint8_t _speed);
		void danceLeft2(uint8_t number, uint8_t _speed);
		void danceRigh2(uint8_t number, uint8_t _speed);
		void danceLeft3(uint8_t number, uint8_t _speed);
		void danceRigh3(uint8_t number, uint8_t _speed);

	private:
		Servo ServoL1;
		Servo ServoL2;
		Servo ServoR1;
		Servo ServoR2;

		uint8_t angleNow[5] = {90, 90, 90, 90, 90};

		void setServo(uint8_t pSevor, uint8_t _angle);

};


#endif
