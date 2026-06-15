// SPDX-License-Identifier: MIT
// Copyright (c) 2026 RealRangerC

#pragma once

#include "core/vector3.hpp"
#include "physics/state.hpp"

namespace vehicle {

class Rocket {
public:
    using Vec3 = core::Vec3

    enum class RocketHealth { Functional, Failed };
    enum class FlightPhase { Stationary, Ascending, Descending, Landed, Crashed };

    Rocket();
    ~Rocket();

    // Getters
    const physics::State& get_state() const;

    // Setters
    void set_state(Vec3 pos, Vec3 velocity, Vec3 acceleration);

    // Utility

private:
    physics::State state;
};

} // namespace vehicle