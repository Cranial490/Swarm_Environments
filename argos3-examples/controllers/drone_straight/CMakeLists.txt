add_library(drone_straight MODULE drone_straight.h drone_straight.cpp)
target_link_libraries(footbot_diffusion
  argos3core_simulator
  argos3plugin_simulator_drone
  argos3plugin_simulator_genericrobot)
