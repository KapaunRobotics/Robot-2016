#pragma config(Motor,  port2,           LeftMotor,     tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port3,           RightMotor,    tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port5,           ArmMotor,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           Hand,          tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,           Hopper,        tmotorServoStandard, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int hand_rotation;

	void update_drive_motors()
	{
		motor[LeftMotor]  = vexRT[Ch3];
		motor[RightMotor] = vexRT[Ch2];
	}
//^Wheel controls^: Left and right wheels controlled with left and right joysticks.^
	void update_arm_motor()
	{
			if (vexRT[Btn8U]       == 1)
			{
				motor[ArmMotor]       = 100;
			}
			else if (vexRT[Btn8D]  == 1)
			{
				motor[ArmMotor]       = -100;
			}
			else
			{
				motor[ArmMotor]       = 0;
			}
	}
//^Arm controls^: Arm movement up and down with right button pad.^
	void update_hand()
	{
			if ((vexRT[Btn6U]      == 1) && (hand_rotation <= 70))
			{
				hand_rotation       = hand_rotation + 1;
				wait1Msec(5);
			}
			else if ((vexRT[Btn5U] == 1) && (hand_rotation >= -127))
			{
				hand_rotation       = hand_rotation - 1;
				wait1Msec(5);
			}
		motor[Hand]             = hand_rotation;
	}
//^Hand controls^: Open and close hand with right button pad.^
	void update_hopper()
	{
		if (vexRT[Btn7R]       == 1)
		{
			motor[Hopper]         = 127;
		}
		else if (vexRT[Btn7L]  == 1)
		{
		motor[Hopper]           = -127;
		}
	}
//^Seed hopper controls^: Open and close gate with left button pad.^

	task main()
	{
		hand_rotation = 0;
		while (true)
		{
			//update_drive_motors();
			//update_arm_motor();
			//update_hand();
			//update_hopper();

		motor[LeftMotor] = -70;
		motor[RightMotor] = -100;




			writeDebugStreamLine("LeftMotor : %d",motor[LeftMotor]);
			writeDebugStreamLine("RightMotor : %d",motor[RightMotor]);
			writeDebugStreamLine("ArmMotor : %d",motor[ArmMotor]);
			writeDebugStreamLine("Hand : %d",motor[Hand]);
			writeDebugStreamLine("Hopper : %d",motor[Hopper]);
		}
	}
