#pragma once

namespace config::environment {

// Launch site
inline constexpr float launch_latitude_deg  = 28.6084f;   // Kennedy Space Center (LC-39A)
inline constexpr float launch_longitude_deg = -80.6043f;  // Kennedy Space Center (LC-39A)
inline constexpr float launch_altitude_m    = 3.0f;       // Approx.



// These values do not have to be manipulated under normal circumstances
// Earth model
inline constexpr float earth_rotation_rad_s = 7.2921159e-5f;
inline constexpr float earth_mu_m3_s2 = 3.986004418e14f;
inline constexpr bool gravity_varies_with_altitude = true;

// Simulation settings
inline constexpr float time_step_s = 0.01f;
inline constexpr int integrator_order = 4; // RK4
inline constexpr bool enable_turbulence = true;
inline constexpr bool enable_failures = false;

// Terrain
inline constexpr float ground_elevation_m = 0.0f;

} // namespace config::environment
