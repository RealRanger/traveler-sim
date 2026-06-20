// SPDX-License-Identifier: MIT
// Copyright (c) 2026 RealRangerC

#pragma once

#include <string>

namespace core {

class RocketConfigFile {
public:
    struct Config {
        std::string path;
        std::string name;

        float length_m;
        float diameter_m;
        int fin_count;

        float dry_mass_kg;
        float payload_mass_kg;
        float propellant_mass_kg;

        float max_thrust_n;
        float average_thrust_n;
        float burn_time_s;
        float isp_s;

        bool thrust_vectoring;
        float max_gimbal_angle_deg;
    };

    RocketConfigFile(std::string config_file_path);
    ~RocketConfigFile();

    const Config& get_config() const;
    bool is_valid() const;

private:
    Config m_config;
    bool m_is_valid{false};
};

} // namespace core