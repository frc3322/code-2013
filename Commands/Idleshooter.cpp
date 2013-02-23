#include "Idleshooter.h"
Idleshooter::Idleshooter() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::shooter);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void Idleshooter::Initialize() {
}
// Called repeatedly when this Command is scheduled to run
void Idleshooter::Execute() {
	Robot::shooter->StopShooting();
}
// Make this return true when this Command no longer needs to run execute()
bool Idleshooter::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void Idleshooter::End() {
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Idleshooter::Interrupted() {
}
