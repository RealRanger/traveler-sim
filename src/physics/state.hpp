// SPDX-License-Identifier: MIT
// Copyright (c) 2026 RealRangerC

#pragma once

#include "core/vector3.hpp"

namespace physics {

struct State {
    using Vec3 = core::Vec3;

    Vec3 position;
    Vec3 velocity;
    Vec3 acceleration;
};

} // namespace physics