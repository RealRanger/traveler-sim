// SPDX-License-Identifier: MIT
// Copyright (c) 2026 RealRangerC

#pragma once

#include "simulation/simulation.hpp"

namespace traveler {

class Traveler {
public:
    Traveler();
    ~Traveler();

    void terminate();
    // TODO: dev mode
    void enable_dev_env();
    void disable_dev_env();

private:
    simulation::Simulation sim;

    bool is_dev_env_enabled;
};

} // namespace traveler