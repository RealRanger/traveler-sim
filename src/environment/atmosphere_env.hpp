// SPDX-License-Identifier: MIT
// Copyright (c) 2026 RealRangerC

#pragma once

namespace environment {

float get_drag(
    float air_density,
    float velocity,
    float drag_coefficient,
    float reference_area
);

float get_lift(
    float air_density,
    float velocity,
    float lift_coefficient,
    float reference_area
);

float get_thrust(
    float mass_flow_rate,
    float exhaust_velocity
);

float get_thrust_with_pressure(
    float mass_flow_rate,
    float exhaust_velocity,
    float exit_pressure,
    float ambient_pressure,
    float exit_area
);

float get_dynamic_pressure(
    float air_density,
    float velocity
);

float get_mach_number(
    float velocity,
    float speed_of_sound
);

float get_gravity_force(
    float mass,
    float gravity_acceleration
);

} // namespace environment
