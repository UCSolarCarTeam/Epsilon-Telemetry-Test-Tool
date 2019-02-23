#pragma once

namespace MessageStates {

    enum MESSAGE_SENDING {DONT_SEND = -1,
                           KEY_MOTOR = 0,
                           MOTOR_0_DETAILS = 1,
                           MOTOR_1_DETAILS = 2,
                           DRIVER_CONTROLS = 3,
                           MOTOR_FAULTS = 4,
                           BATTERY_FAULTS = 5,
                           BATTERY = 6,
                           MPPTS = 7,
                           LIGHTS = 8,
                           AUX_BMS = 9,
                           ALL = 10,
                         };
}
