#pragma once
#ifndef _DRIVETRAIN_HPP_
#define _DRIVETRAIN_HPP_

#include "main.h"

class Drivetrain {
    public:
        Drivetrain(int TLPort, int TRPort, int BLPort, int BRPort) : 
            m_TopLeftMotor{TLPort}, 
            m_TopRightMotor{TRPort}, 
            m_BottomLeftMotor{BLPort}, 
            m_BottomRightMotor{BRPort} {
            // m_TopLeftMotor = pros::Motor (TLPort);
            // m_TopRightMotor = pros::Motor (TRPort);
            // m_BottomLeftMotor = pros::Motor (BLPort);
            // m_BottomRightMotor = pros::Motor (BRPort);
            // pros & C++ --> funny and dont allow dis
        }

        void XDrive(int y_direction, int x_direction, int rotation) {
            m_TopLeftMotor.move_velocity(y_direction + x_direction + rotation);
            m_TopRightMotor.move_velocity(-y_direction + x_direction + rotation);
            m_BottomLeftMotor.move_velocity(y_direction - x_direction + rotation);
            m_BottomRightMotor.move_velocity(-y_direction - x_direction + rotation);
        }


    private:
        pros::Motor m_TopLeftMotor;
        pros::Motor m_TopRightMotor;
        pros::Motor m_BottomLeftMotor;
        pros::Motor m_BottomRightMotor;
};

#endif
