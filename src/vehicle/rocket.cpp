// SPDX-License-Identifier: MIT
// Copyright (c) 2026 RealRangerC

#include "vehicle/rocket.hpp"

#include <string>

namespace vehicle {

Rocket::Rocket(const std::string filename) : filename(filename) {}

Rocket::~Rocket() {}

} // namespace vehicle