#define DATA_LENGTH 1

#include "SerialPort.h"
#include <iostream>

#pragma pack(1)

const char* portName = "COM5";

struct DataPack {
	short int order;
	float gyro;
	float acc;
};

SerialPort *arduino;

char receivedString[DATA_LENGTH];

int main(void)
{
	DataPack x;

	arduino = new SerialPort(portName);
	if (arduino->isConnected()) {
		while (1) {

			char s[10];

			int hasRead = arduino->readSerialPort(receivedString, DATA_LENGTH);
			if (hasRead) {
				s[0] = receivedString[0];
				for (int i = 1; i < 10; i++) {
					int hasRead = arduino->readSerialPort(receivedString, DATA_LENGTH);
					if (hasRead) {
						s[i] = receivedString[0];
						//printf(" %02x", s[i]);
					}
				}
				memcpy(&x, s, 10);
				printf("%d %f %f\n", x.order, x.gyro, x.acc);
			}

			

		}
	}
}