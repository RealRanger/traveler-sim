// SPDX-License-Identifier: MIT
// Copyright (c) 2026 RealRangerC

#include "vehicle/rocket.hpp"

#include <string>
#include <iostream>

namespace vehicle {

Rocket::Rocket(
    const std::string& file_path,
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
)
: file_path(file_path),
  length_m(length_m),
  diameter_m(diameter_m),
  fin_count(fin_count),
  dry_mass_kg(dry_mass_kg),
  payload_mass_kg(payload_mass_kg),
  propellant_mass_kg(propellant_mass_kg),
  max_thrust_n(max_thrust_n),
  average_thrust_n(average_thrust_n),
  burn_time_s(burn_time_s),
  isp_s(isp_s),
  thrust_vectoring(thrust_vectoring),
  max_gimbal_angle_deg(max_gimbal_angle_deg)
{
    #ifdef DEBUG
        std::cout << "[ROCKET]: Created rocket object with values:\n"
          << "  filename: " << file_path << "\n"
          << "  length_m: " << length_m << "\n"
          << "  diameter_m: " << diameter_m << "\n"
          << "  fin_count: " << fin_count << "\n"
          << "  dry_mass_kg: " << dry_mass_kg << "\n"
          << "  payload_mass_kg: " << payload_mass_kg << "\n"
          << "  propellant_mass_kg: " << propellant_mass_kg << "\n"
          << "  max_thrust_n: " << max_thrust_n << "\n"
          << "  average_thrust_n: " << average_thrust_n << "\n"
          << "  burn_time_s: " << burn_time_s << "\n"
          << "  isp_s: " << isp_s << "\n"
          << "  thrust_vectoring: " << (thrust_vectoring ? "true" : "false") << "\n"
          << "  max_gimbal_angle_deg: " << max_gimbal_angle_deg << "\n"
          << std::endl;
    #endif
}

Rocket::~Rocket() {}

const std::string& Rocket::get_file_path() const {
    return file_path;
}

} // namespace vehicle