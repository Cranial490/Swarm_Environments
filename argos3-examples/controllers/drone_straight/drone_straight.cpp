/* Include the controller definition */
#include "drone_straight.h"
/* Function definitions for XML parsing */
#include <argos3/core/utility/configuration/argos_configuration.h>
/* 2D vector definition */
#include <argos3/core/utility/math/vector3.h>

/****************************************/
/****************************************/

CDroneStraight::CDroneStraight() :
   m_droneVal(NULL),
   m_pcProximity(NULL) {}

/****************************************/
/****************************************/

void CDroneStraight::Init(TConfigurationNode& t_node) {
   /*
    * Get sensor/actuator handles
    *
    * The passed string (ex. "differential_steering") corresponds to the
    * XML tag of the device whose handle we want to have. For a list of
    * allowed values, type at the command prompt:
    *
    * $ argos3 -q actuators
    *
    * to have a list of all the possible actuators, or
    *
    * $ argos3 -q sensors
    *
    * to have a list of all the possible sensors.
    *
    * NOTE: ARGoS creates and initializes actuators and sensors
    * internally, on the basis of the lists provided the configuration
    * file at the <controllers><footbot_diffusion><actuators> and
    * <controllers><footbot_diffusion><sensors> sections. If you forgot to
    * list a device in the XML and then you request it here, an error
    * occurs.
    */
   m_droneVal    = GetActuator<CCI_DroneFlightSystemActuator>("drone_flight_system");
   m_pcProximity = GetSensor  <CCI_DroneRangefindersSensor>("drone_rangefinders");
   /*
    * Parse the configuration file
    *
    * The user defines this part. Here, the algorithm accepts three
    * parameters and it's nice to put them in the config file so we don't
    * have to recompile if we want to try other settings.
    */
//    GetNodeAttributeOrDefault(t_node, "alpha", m_cAlpha, m_cAlpha);
//    m_cGoStraightAngleRange.Set(-ToRadians(m_cAlpha), ToRadians(m_cAlpha));
//    GetNodeAttributeOrDefault(t_node, "delta", m_fDelta, m_fDelta);
//    GetNodeAttributeOrDefault(t_node, "velocity", m_fWheelVelocity, m_fWheelVelocity);
}

/****************************************/
/****************************************/

void CDroneStraight::ControlStep() {
   /* Get readings from proximity sensor */
   const CCI_DroneRangefindersSensor::TReadings& tProxReads = m_pcProximity->GetReadings();
}

/****************************************/
/****************************************/

/*
 * This statement notifies ARGoS of the existence of the controller.
 * It binds the class passed as first argument to the string passed as
 * second argument.
 * The string is then usable in the configuration file to refer to this
 * controller.
 * When ARGoS reads that string in the configuration file, it knows which
 * controller class to instantiate.
 * See also the configuration files for an example of how this is used.
 */
REGISTER_CONTROLLER(CDroneStraight, "drone_controller")
