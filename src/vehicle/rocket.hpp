// SPDX-License-Identifier: MIT
// Copyright (c) 2026 RealRangerC

#pragma once

#include "core/vector3.hpp"
#include "physics/state.hpp"

#include <string>

namespace vehicle {

class Rocket {
public:
    using Vec3 = core::Vec3;

    enum class RocketHealth { Functional, Failed };
    enum class FlightPhase { Stationary, Ascending, Descending, Landed, Crashed };

    
    Rocket(
        const std::string& file_path,
        std::string name,
        float length_m,
        float diameter_m,
        int fin_count,
        float dry_mass_kg,
        float payload_mass_kg,
        float propellant_mass_kg,
        float max_thrust_n,
        float average_thrust_n,
        float burn_time_s,
        float isp_s,
        bool thrust_vectoring,
        float max_gimbal_angle_deg
    );
    ~Rocket();

    // Getters
    const physics::State& get_state() const;
    const std::string& get_file_path() const;

    // Setters
    void set_state(Vec3 pos, Vec3 velocity, Vec3 acceleration);

    // Utility

private:
    std::string file_path;
    physics::State state;
    std::string name;

    float length_m;
    float diameter_m;
    int fin_count;

    float dry_mass_kg;
    float payload_mass_kg;
    float propellant_mass_kg;

    float max_thrust_n;
    float average_thrust_n;
    float burn_time_s;
    float isp_s;

    bool  thrust_vectoring;
    float max_gimbal_angle_deg;
};

} // namespace vehicle