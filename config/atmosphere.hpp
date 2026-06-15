#pragma once

namespace config::atmosphere {

// Basic parameters
inline constexpr float temperature_c = 15.0f;        // Surface temp
inline constexpr float pressure_pa = 101325.0f;      // Sea-level pressure
inline constexpr float humidity_percent = 50.0f;     // Relative humidity

inline constexpr float wind_speed_ms = 2.0f;         // Ground wind
inline constexpr float wind_direction_deg = 0.0f;    // 0 = north
inline constexpr float turbulence_intensity = 5.0f;  // %

//
// Advanced parameters
//
inline constexpr float lapse_rate_kpm = -0.0065f;    // Standard atmosphere
inline constexpr float tropopause_alt_m = 11000.0f;
inline constexpr float stratosphere_temp_k = 216.65f;

inline constexpr float nitrogen_fraction = 0.78084f;
inline constexpr float oxygen_fraction = 0.20946f;
inline constexpr float argon_fraction = 0.00934f;
inline constexpr float co2_fraction = 0.00036f;

inline constexpr float gravity_ms2 = 9.80665f;
inline constexpr float planet_radius_m = 6371000.0f;

} // namespace config::atmosphere
