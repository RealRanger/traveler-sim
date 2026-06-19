// SPDX-License-Identifier: MIT
// Copyright (c) 2026 RealRangerC

#include "simulation.hpp"
#include "vehicle/rocket.hpp"
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
            // TODO: make this its own system so simulation does not have to handle file parsing
            std::string filename = entry.path().filename().string();
            if (filename.rfind(m_FILE_PREFIX, 0) == 0) {
                std::string file_path = entry.path().string();

                std::ifstream file(file_path);
                if (!file.is_open()) {
                    std::cerr << "Opening file '" 
                              << filename 
                              << "' failed" 
                              << std::endl;
                    continue;
                }

                json config;
                file >> config;

                float length_m = config["config"]["rocket"]["geometry"]["length_m"];
                float diameter_m = config["config"]["rocket"]["geometry"]["diameter_m"];
                int fin_count = config["config"]["rocket"]["geometry"]["fin_count"];

                float dry_mass_kg = config["config"]["rocket"]["mass"]["dry_mass_kg"];
                float payload_mass_kg = config["config"]["rocket"]["mass"]["payload_mass_kg"];
                float propellant_mass_kg = config["config"]["rocket"]["mass"]["propellant_mass_kg"];

                float max_thrust_n = config["config"]["rocket"]["propulsion"]["max_thrust_n"];
                float average_thrust_n = config["config"]["rocket"]["propulsion"]["average_thrust_n"];
                float burn_time_s = config["config"]["rocket"]["propulsion"]["burn_time_s"];
                float isp_s = config["config"]["rocket"]["propulsion"]["isp_s"];

                bool thrust_vectoring = config["config"]["rocket"]["control"]["thrust_vectoring"];
                float max_gimbal_angle_deg = config["config"]["rocket"]["control"]["max_gimbal_angle_deg"];

                // Treat each rocket config file as a new Rocket instance
                rocket_vector.push_back(std::make_unique<vehicle::Rocket>(
                    file_path,
                    length_m,
                    diameter_m,
                    fin_count,
                    dry_mass_kg,
                    payload_mass_kg,
                    propellant_mass_kg,
                    max_thrust_n,
                    average_thrust_n,
                    burn_time_s,
                    isp_s,
                    thrust_vectoring,
                    max_gimbal_angle_deg
                ));
            }
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