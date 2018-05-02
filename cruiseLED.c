#pragma config(Sensor, in1,    pwrExp,         sensorAnalog)
#pragma config(Sensor, in4,    pot,            sensorPotentiometer)
#pragma config(Sensor, dgtl1,  quad,           sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  limit,          sensorTouch)
#pragma config(Sensor, dgtl4,  bump,           sensorTouch)
#pragma config(Sensor, dgtl5,  ledGreen,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl6,  ledYellow,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl7,  ledRed,         sensorLEDtoVCC)
#pragma config(Sensor, dgtl8,  jumper,         sensorTouch)
#pragma config(Sensor, dgtl11, ultrasonic,     sensorSONAR_inch)
#pragma config(Motor,  port2,           drive,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           drive1,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           drive2,        tmotorVex393_MC29, openLoop, reversed)

task main()
{
	float ratio = 127.0 / 4095.0;
	while (true)
	{
		float m = 127 * SensorValue[pot] / 4095;
		motor[drive] = m;
		if (m > 90)
		{
			SensorValue[ledGreen] = 1;
			SensorValue[ledYellow] = 0;
			SensorValue[ledRed] = 0;
		}
		else if (m <= 90 && m >= 45)
		{
			SensorValue[ledGreen] = 0;
			SensorValue[ledYellow] = 1;
			SensorValue[ledRed] = 0;
		}
		else
		{
			SensorValue[ledGreen] = 0;
			SensorValue[ledYellow] = 0;
			SensorValue[ledRed] = 1;
		}
	}
}
