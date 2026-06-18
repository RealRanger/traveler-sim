// SPDX-License-Identifier: MIT
// Copyright (c) 2026 RealRangerC

#include "simulation.hpp"
#include "vehicle/rocket.hpp"

#include <memory>
#include <filesystem>
#include <string>
#include <iostream>

namespace simulation {

Simulation::Simulation() 
    :  m_FOLDER("../../config"), // executable exists in traveler-sim/build/Debug
       m_FILE_PREFIX("rocket_config") 
{

    try {
        for (const auto& entry : std::filesystem::directory_iterator(m_FOLDER)) {
            if (!entry.is_regular_file()) {
                continue;
            }

            std::string filename = entry.path().filename().string();
            if (filename.rfind(m_FILE_PREFIX, 0) == 0) {
                // Treat each rocket config file as a new Rocket instance
                rocket_vector.push_back(std::make_unique<vehicle::Rocket>(filename));
            }
            
        }

        #ifdef DEBUG
            std::cout << "[SIMULATION]: Rocket vector initialised with " 
                    << rocket_vector.size() 
                    << " rockets." 
                    << std::endl;

            for (size_t i  = 0; i < rocket_vector.size(); i++) {
                std::cout << "[SIMULATION]: Loaded 'ROCKET " << i
                        << "' with file '" << rocket_vector[i]->get_filename() << "'." << std::endl;

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