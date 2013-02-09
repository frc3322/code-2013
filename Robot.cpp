#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
Drivetrain* Robot::drivetrain = 0;
Climber* Robot::climber = 0;
Shooter* Robot::shooter = 0;
Gatherer* Robot::gatherer = 0;
Camera* Robot::camera = 0;
Support* Robot::support = 0;
Cosmetic* Robot::cosmetic = 0;
OI* Robot::oi = 0;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	drivetrain = new Drivetrain();
	climber = new Climber();
	shooter = new Shooter();
	gatherer = new Gatherer();
	camera = new Camera();
	support = new Support();
	cosmetic = new Cosmetic();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

	oi = new OI();
	lw = LiveWindow::GetInstance();
	diag = new Diagnostics();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutonomousCommand();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
}

#define COLLECT_DIAGNOSTICS 1

void Robot::DisabledInit() {
	double startTime = Timer::GetPPCTimestamp();

	double endTime = Timer::GetPPCTimestamp();
	Robot::diag->Snapshot("DI", startTime, endTime);
}

void Robot::DisabledPeriodic() {
#if COLLECT_DIAGNOSTICS
	double startTime = Timer::GetPPCTimestamp();
#endif

#if COLLECT_DIAGNOSTICS
	double endTime = Timer::GetPPCTimestamp();
	Robot::diag->Snapshot("D", startTime, endTime);
#endif
}

void Robot::AutonomousInit() {
	double startTime = Timer::GetPPCTimestamp();

	autonomousCommand->Start();

	double endTime = Timer::GetPPCTimestamp();
	Robot::diag->Snapshot("AI", startTime, endTime);
}

void Robot::AutonomousPeriodic() {
#if COLLECT_DIAGNOSTICS
	double startTime = Timer::GetPPCTimestamp();
#endif

	Scheduler::GetInstance()->Run();

#if COLLECT_DIAGNOSTICS
	double endTime = Timer::GetPPCTimestamp();
	Robot::diag->Snapshot("A", startTime, endTime);
	Robot::drivetrain->Snapshot();
#endif
}

void Robot::TeleopInit() {
	double startTime = Timer::GetPPCTimestamp();

	autonomousCommand->Cancel();
	RobotMap::supportCompressor->Start();
	Robot::support->gyro->Reset();

	double endTime = Timer::GetPPCTimestamp();
	Robot::diag->Snapshot("TI", startTime, endTime);
}

void Robot::TeleopPeriodic() {
	Robot::support->perfTimer->Set(1);
#if COLLECT_DIAGNOSTICS
	double startTime = Timer::GetPPCTimestamp();
#endif

	double gyroAngle = Robot::support->gyro->GetAngle();
	SmartDashboard::PutNumber("gyro", gyroAngle);
	Scheduler::GetInstance()->Run();

	Robot::support->perfTimer->Set(0);
#if COLLECT_DIAGNOSTICS
	double endTime = Timer::GetPPCTimestamp();
	Robot::support->diagTimer->Set(1);
	Robot::diag->Snapshot("T", startTime, endTime, gyroAngle);
	Robot::drivetrain->Snapshot();
	Robot::support->diagTimer->Set(0);
#endif
}

void Robot::TestInit() {
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

// taskPrioritySet(tid, 0) ---> taskPrioritySet(tid, priority)
// taskLock() ---> taskUnlock()
#define RUN_TIMER_TEST(F) \
elapsed = last = Timer::GetPPCTimestamp(); \
for (j = 0; j < NumInnerIters; ++j) { \
	now = F(); \
	dt = now - last; \
	if (j > 0) { \
		if (dt > max_dt) max_dt = dt; \
		if (dt < min_dt) min_dt = dt; \
	} \
	else { \
		max_dt = 0.0; \
		min_dt = 1.0; \
	} \
	last = now; \
} \
elapsed = Timer::GetPPCTimestamp() - elapsed; \
avg_dt = elapsed / NumInnerIters;

void Robot::RunTests() {
	FILE *log = fopen("/3322-timing.txt", "w");
	if (log) {
		fprintf(log, "TIMING TEST\n");
		const int NumOuterIters = 10;
		const int NumInnerIters = 1000;
		int i, j;
		double elapsed, now, last, dt, min_dt, max_dt, avg_dt;
		int tid, priority;
		tid = taskIdSelf();
		taskPriorityGet(tid, &priority);
		for (i = 0; i < NumOuterIters; ++i) {
			RUN_TIMER_TEST(Timer::GetFPGATimestamp)
			fprintf(log, "FPGA,%.8f,%.8f,%.8f\n", avg_dt, min_dt, max_dt);
		}
		for (i = 0; i < NumOuterIters; ++i) {
			RUN_TIMER_TEST(::GetTime)
			fprintf(log, "GetTime,%.8f,%.8f,%.8f\n", avg_dt, min_dt, max_dt);
		}
		for (i = 0; i < NumOuterIters; ++i) {
			RUN_TIMER_TEST(Timer::GetPPCTimestamp)
			fprintf(log, "PPC,%.8f,%.8f,%.8f\n", avg_dt, min_dt, max_dt);
		}
		fclose(log);
	}
}
