// SPDX-License-Identifier: MIT
// Copyright (c) 2026 RealRangerC

#include "traveler/traveler.hpp"
#include "simulation/simulation.hpp"

namespace traveler {

Traveler::Traveler()
    : sim(simulation::Simulation()),
      is_dev_env_enabled(false) {}

Traveler::~Traveler() {}

void Traveler::terminate() {
    sim.cancel_active_rockets();
}

void Traveler::enable_dev_env() {
    // setting it to the same value doesn't pose any risks.
    // this is in case we evolve this to do more when enabled/disabled.
    if (is_dev_env_enabled) {
        return;
    }

    is_dev_env_enabled = true;
}

void Traveler::disable_dev_env() {
    if (!is_dev_env_enabled) {
        return;
    }

    is_dev_env_enabled = false;
}


} // namespace traveler