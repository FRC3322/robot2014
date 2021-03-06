#include "AutoShiftDrive.h"

AutoShiftDrive::AutoShiftDrive(SpeedController &frontLeftMotor, SpeedController &rearLeftMotor,
				SpeedController &frontRightMotor, SpeedController &rearRightMotor,
				DoubleSolenoid &gearShifter)://,
				//Encoder &leftDriveEncoder, Encoder &rightDriveEncoder): 
				RobotDrive(frontLeftMotor,rearLeftMotor,frontRightMotor,rearRightMotor),
				shifter(gearShifter)
				//leftEncoder(leftDriveEncoder), rightEncoder(rightDriveEncoder)
{
}

bool AutoShiftDrive::isInForwardGear() {
	return shifter.Get() == DoubleSolenoid::kForward;
}
void AutoShiftDrive::toggleShiftGear() {
	shifter.Set(isInForwardGear() ? DoubleSolenoid::kReverse : DoubleSolenoid::kForward);
}
void AutoShiftDrive::shiftHighGear() {
	shifter.Set(DoubleSolenoid::kForward);
}
void AutoShiftDrive::shiftHighLow() {
	shifter.Set(DoubleSolenoid::kReverse);
}
DoubleSolenoid::Value AutoShiftDrive::getShifterValue() {
	return shifter.Get();
}
void AutoShiftDrive::setShifterValue(DoubleSolenoid::Value val) {
	shifter.Set(val);
}
