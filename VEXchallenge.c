#pragma config(Motor,  port2,           rightWheel,    tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port3,           leftWheel,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port4,           rightElevator, tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port5,           leftElevator,  tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port6,           cageMotor,     tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port7,           closeSideways,  tmotorServoContinuousRotation, openLoop)
#pragma config(Motor,  port8,           farSideways,   tmotorServoContinuousRotation, openLoop)

/* Tamir Arnesty, Alex Barkin, Jacob Sykora, Cameron Quan Yin, Justin Verrall, Noam Zeldin
	 Mr. Wong
	 VEX Robot ISP Challenge
	 June 15, 2017
*/
task main()
{
	while (true) {
		// robot moves in all directions
		if (vexRT[Btn5D] == 1 || vexRT[Btn5U] == 1) { // slow
			motor[rightWheel] = (vexRT[Ch4] - vexRT[Ch3])/3;
			motor[leftWheel] = (vexRT[Ch4] + vexRT[Ch3])/3;
			} else { // fast
			motor[rightWheel] = (vexRT[Ch1] - vexRT[Ch2]);
			motor[leftWheel] = (vexRT[Ch1] + vexRT[Ch2]);
		}

		motor[cageMotor] = 80; // ball raising machine always running

		// sideways movement
		if (vexRT[Btn7R] == 1 || vexRT[Btn8R] == 1) { // right
			motor[closeSideways] = 100;
			motor[farSideways] = 100;
			} else if (vexRT[Btn7L] == 1 || vexRT[Btn8L] == 1) { // left
			motor[closeSideways] = -100;
			motor[farSideways] = -100;
			} else {
			if (vexRT[Btn7R] == 0 || vexRT[Btn8R] == 0 || vexRT[Btn7L] == 0 || vexRT[Btn8L] == 0) {
				motor[closeSideways] = 0;
				motor[farSideways] = 0;
			}
		}

		// cage raising and lowering
		if (vexRT[Btn8U] == 1 || vexRT[Btn7U] == 1) {
			motor[rightElevator] = 100;
			motor[leftElevator] = -100;
			} else if (vexRT[Btn8D] == 1 || vexRT[Btn7D] == 1) {
			motor[rightElevator] = -100;
			motor[leftElevator] = 100;
			} else {
			if (vexRT[Btn8U] == 0 || vexRT[Btn8D] == 0 || vexRT[Btn7U] == 0 || vexRT[Btn7D] == 0) {
				motor[rightElevator] = 0;
				motor[leftElevator] = 0;
			}
		}
	}
}
