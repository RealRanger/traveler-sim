// SPDX-License-Identifier: MIT
// Copyright (c) 2026 RealRangerC

#include "simulation.hpp"
#include "vehicle/rocket.hpp"
#include "core/rocket_config_file.hpp"
#include "json.hpp"

#include <memory>
#include <filesystem>
#include <string>
#include <iostream>
#include <fstream>

namespace simulation {

using json = nlohmann::json;

Simulation::Simulation() 
    :  m_FOLDER("../../config"), // executable exists in traveler-sim/build/Debug
       m_FILE_PREFIX("rocket_config") 
{

    try {
        for (const auto& entry : std::filesystem::directory_iterator(m_FOLDER)) {
            if (!entry.is_regular_file()) {
                continue;
            }

            const auto filename = entry.path().filename().string();
            if (filename.rfind(m_FILE_PREFIX, 0) != 0 || entry.path().extension() != ".json") {
                continue;
            }

            core::RocketConfigFile rocket_config_file(entry.path().string());
            if (!rocket_config_file.is_valid()) {
                continue;
            }

            auto config = rocket_config_file.get_config();
            // Treat each rocket config file as a new Rocket instance
            rocket_vector.push_back(std::make_unique<vehicle::Rocket>(
                config.path,
                config.name,
                config.length_m,
                config.diameter_m,
                config.fin_count,
                config.dry_mass_kg,
                config.payload_mass_kg,
                config.propellant_mass_kg,
                config.max_thrust_n,
                config.average_thrust_n,
                config.burn_time_s,
                config.isp_s,
                config.thrust_vectoring,
                config.max_gimbal_angle_deg
            ));
        }

        #ifdef DEBUG
            std::cout << "[SIMULATION]: Rocket vector initialised with " 
                    << rocket_vector.size() 
                    << " rockets." 
                    << std::endl;

            for (size_t i  = 0; i < rocket_vector.size(); i++) {
                std::cout << "[SIMULATION]: Loaded 'ROCKET " << i
                        << "' with file '" << rocket_vector[i]->get_file_path() << "'." << std::endl;
            }
        #endif
    } catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Filesystem error: " << e.what() << '\n';
    }
}

Simulation::~Simulation() {
    cancel_active_rockets();
}

void Simulation::start() {

}

void Simulation::cancel_active_rockets() {

}

} // namespace simulation