// SPDX-License-Identifier: MIT
// Copyright (c) 2026 RealRangerC

#pragma once

#include "core/rocket_config_file.hpp"
#include "json.hpp"

#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>

namespace core {

using json = nlohmann::json;

RocketConfigFile::RocketConfigFile(std::string config_file_path) {
    std::ifstream file(config_file_path);
    if (!file.is_open()) {
        std::cerr << "Opening file '" 
                    << config_file_path 
                    << "' failed" 
                    << std::endl;
        return;
    }

    try {
        json config;
        file >> config;

        m_config = Config();
        m_config.path = config_file_path;
        
        m_config.name = config["config"]["rocket"]["name"].get<std::string>();

        m_config.length_m = config["config"]["rocket"]["geometry"]["length_m"].get<float>();
        m_config.diameter_m = config["config"]["rocket"]["geometry"]["diameter_m"].get<float>();
        m_config.fin_count = config["config"]["rocket"]["geometry"]["fin_count"].get<int>();

        m_config.dry_mass_kg = config["config"]["rocket"]["mass"]["dry_mass_kg"].get<float>();
        m_config.payload_mass_kg = config["config"]["rocket"]["mass"]["payload_mass_kg"].get<float>();
        m_config.propellant_mass_kg = config["config"]["rocket"]["mass"]["propellant_mass_kg"].get<float>();

        m_config.max_thrust_n = config["config"]["rocket"]["propulsion"]["max_thrust_n"].get<float>();
        m_config.average_thrust_n = config["config"]["rocket"]["propulsion"]["average_thrust_n"].get<float>();
        m_config.burn_time_s = config["config"]["rocket"]["propulsion"]["burn_time_s"].get<float>();
        m_config.isp_s = config["config"]["rocket"]["propulsion"]["isp_s"].get<float>();

        m_config.thrust_vectoring = config["config"]["rocket"]["control"]["thrust_vectoring"].get<bool>();
        m_config.max_gimbal_angle_deg = config["config"]["rocket"]["control"]["max_gimbal_angle_deg"].get<float>();

        m_is_valid = true;
    } catch (const nlohmann::json::exception& e) {
        std::cerr << "Rocket config parse error in '" << config_file_path << "': " << e.what() << '\n';
        return;
    }

    #ifdef DEBUG
        std::cout << "[ROCKET_CONFIG_FILE]: Created config file object with values:\n"
        << "  path: " << m_config.path << "\n"
        << "  name: " << m_config.name << "\n"
        << "  length_m: " << m_config.length_m << "\n"
        << "  diameter_m: " << m_config.diameter_m << "\n"
        << "  fin_count: " << m_config.fin_count << "\n"
        << "  dry_mass_kg: " << m_config.dry_mass_kg << "\n"
        << "  payload_mass_kg: " << m_config.payload_mass_kg << "\n"
        << "  propellant_mass_kg: " << m_config.propellant_mass_kg << "\n"
        << "  max_thrust_n: " << m_config.max_thrust_n << "\n"
        << "  average_thrust_n: " << m_config.average_thrust_n << "\n"
        << "  burn_time_s: " << m_config.burn_time_s << "\n"
        << "  isp_s: " << m_config.isp_s << "\n"
        << "  thrust_vectoring: " << (m_config.thrust_vectoring ? "true" : "false") << "\n"
        << "  max_gimbal_angle_deg: " << m_config.max_gimbal_angle_deg << "\n"
        << std::endl;
    #endif
}

RocketConfigFile::~RocketConfigFile() {}

const RocketConfigFile::Config& RocketConfigFile::get_config() const {
    return m_config;
}

bool RocketConfigFile::is_valid() const {
    return m_is_valid;
}

} // namespace core