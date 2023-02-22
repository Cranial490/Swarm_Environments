#ifndef DRONE_STRAIGHT_H
#define DRONE_STRAIGHT_H

#include <argos3/core/control_interface/ci_controller.h>
#include <argos3/plugins/robots/drone/simulator/drone_flight_system_entity.h>
#include <argos3/plugins/robots/drone/control_interface/ci_drone_rangefinders_sensor.h>

using namespace argos;

class CDroneStraight : public CCI_Controller {

public:

    /* Class constructor. */
    CDroneStraight();

    /* Class destructor. */
    virtual ~CDroneStraight() {}

    /*
    * This function initializes the controller.
    * The 't_node' variable points to the <parameters> section in the XML
    * file in the <controllers><footbot_diffusion_controller> section.
    */
    virtual void Init(TConfigurationNode& t_node);

   /*
    * This function is called once every time step.
    * The length of the time step is set in the XML file.
    */
    virtual void ControlStep();

   /*
    * This function resets the controller to its state right after the
    * Init().
    * It is called when you press the reset button in the GUI.
    * In this example controller there is no need for resetting anything,
    * so the function could have been omitted. It's here just for
    * completeness.
    */
    virtual void Reset() {}

   /*
    * Called to cleanup what done by Init() when the experiment finishes.
    * In this example controller there is no need for clean anything up,
    * so the function could have been omitted. It's here just for
    * completeness.
    */
    virtual void Destroy() {}

private:

   /* Pointer to the differential steering actuator */
   CCI_DroneFlightSystemActuator* m_droneVal;
   /* Pointer to the foot-bot proximity sensor */
   CCI_DroneRangefindersSensor* m_pcProximity;

//    CRange<CRadians> m_cGoStraightAngleRange;

};

#endif