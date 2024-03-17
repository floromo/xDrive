#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	pros::lcd::set_text(1, "Hello PROS User!");

	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	// Setting up hardware for robo

	// // Instantiating (making an instance (object) of) Motor
	// pros::Motor m_TopLeftMotor = pros::Motor (11);
	// pros::Motor m_TopRightMotor = pros::Motor (1);
	// pros::Motor m_BottomLeftMotor = pros::Motor (20);
	// pros::Motor m_BottomRightMotor = pros::Motor (10);

	Drivetrain m_drive = Drivetrain(11, 1, 20, 10);

	// Instantiating controller
	pros::Controller m_Controller = pros::Controller(pros::E_CONTROLLER_MASTER);

	while (true) { // Forced to run forever
		// Setting up the joysticks  on da controller
		int y_direction = m_Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int x_direction = m_Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
		int rotation = m_Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

		// // Setting the velocities using maths
		// m_TopLeftMotor.move_velocity(y_direction + x_direction + rotation);
		// m_TopRightMotor.move_velocity(-y_direction + x_direction + rotation);
		// m_BottomLeftMotor.move_velocity(y_direction - x_direction + rotation);
		// m_BottomRightMotor.move_velocity(-y_direction - x_direction + rotation);

		m_drive.XDrive(y_direction, x_direction, rotation);

		pros::delay(20); // Computer faster than robot, so gotta wait like 20 ms before updating so that the robo don't go kaboom
	}
}