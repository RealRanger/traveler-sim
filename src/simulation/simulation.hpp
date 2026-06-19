// SPDX-License-Identifier: MIT
// Copyright (c) 2026 RealRangerC

#pragma once

#include "vehicle/rocket.hpp"

#include <memory>
#include <vector>

namespace simulation {

class Simulation {
public:
    Simulation();
    ~Simulation();

    void start();
    void cancel_active_rockets();

private:
    const std::string m_FOLDER;
    const std::string m_FILE_PREFIX;


    std::vector<std::unique_ptr<vehicle::Rocket>> rocket_vector;
};

} // namespace simulation