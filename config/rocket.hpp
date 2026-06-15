#pragma once

namespace config::rocket {

// Geometry
inline constexpr float length_m = 1.8f;
inline constexpr float diameter_m = 0.1f;
inline constexpr int fin_count = 3;

// Mass
inline constexpr float dry_mass_kg = 2.0f;
inline constexpr float payload_mass_kg = 0.2f;
inline constexpr float propellant_mass_kg = 1.2f;

// Propulsion
inline constexpr float max_thrust_n = 300.0f;
inline constexpr float average_thrust_n = 180.0f;
inline constexpr float burn_time_s = 2.0f;
inline constexpr float isp_s = 210.0f;

// Control
inline constexpr bool thrust_vectoring = false;
inline constexpr float max_gimbal_angle_deg = 0.0f;


} // namespace config::rocket
