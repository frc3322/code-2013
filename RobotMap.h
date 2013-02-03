// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"
/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
class RobotMap {
public:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static CANJaguar* drivetrainLeftMotorA;
	static CANJaguar* drivetrainLeftMotorB;
	static CANJaguar* drivetrainRightMotorA;
	static CANJaguar* drivetrainRightMotorB;
	static RobotDrive* drivetrainDrive;
	static DoubleSolenoid* drivetrainShiftGear;
	static Encoder* drivetrainLeftEncoder;
	static Encoder* drivetrainRightEncoder;
	static Servo* climberSafetyMotor;
	static DoubleSolenoid* climberEngageClaw;
	static CANJaguar* shooterMainMotor;
	static CANJaguar* shooterFeedMotor;
	static AnalogChannel* shooterFrisbeeDirection;
	static DoubleSolenoid* shooterDeploy;
	static CANJaguar* gathererMotor;
	static DoubleSolenoid* gathererDeploy;
	static Servo* cameraElevation;
	static Servo* cameraDirection;
	static DigitalOutput* supportPerfTimer;
	static Accelerometer* supportAccel;
	static Gyro* supportGyro;
	static Compressor* supportCompressor;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	static void init();
};
#endif
