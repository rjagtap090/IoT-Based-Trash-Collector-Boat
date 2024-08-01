This project focuses on developing an IoT-based trash collector boat designed to clean debris from water bodies like lakes, ponds, and rivers. The boat uses a conveyor belt mechanism to collect surface trash and deposit it into a container. The boat can be controlled remotely, providing a practical solution for reducing water pollution with minimal human intervention.

Features
Remote Control: Operated via an HTML web page with live video streaming.
Trash Collection: Conveyor belt mechanism collects floating debris.
Real-time Monitoring: ESP32-CAM provides live video feed for precise control.
IoT Integration: Uses NodeMCU and ESP8266 for connectivity and control.
Hardware Components
NodeMCU (ESP8266)
ESP32-CAM
DC Motors
L298N Motor Driver
Conveyor Belt
Lithium-Ion Battery (5000 mAh)
Boat Structure
Software Requirements
Arduino IDE
TinkerCAD (for prototyping)
Proteus (for simulation)
Circuit Diagram

Block Diagram

Working
Initialization: The boat is powered on, and the system initializes.
Remote Control: The boat is controlled using an HTML web page that sends commands to the NodeMCU.
Trash Collection: The conveyor belt collects trash from the water surface and deposits it into a container.
Monitoring: Live video feed from the ESP32-CAM helps in navigating and controlling the boat.
Methodology
Controlling the Boat:

The boat is equipped with an ESP32-CAM for live video streaming.
Controlled via an HTML web page with "Forward", "Backward", "Left", "Right", and "Stop" commands.
Trash Collection:

A conveyor belt at the front collects floating debris and deposits it into a trash container.

Results
Simulation: Successfully tested the boat’s movement and trash collection in Proteus.
Prototype: Demonstrated effective trash collection from the water surface in real-time conditions.
Limitations
Load Capacity: Can collect up to 5 kg of trash.
Depth Limitation: Operates at a depth of 100 mm.
Battery Life: Limited by the battery capacity.
Conclusion
The IoT-based trash collector boat effectively reduces surface water pollution. The prototype demonstrates a practical solution for waste collection in narrow water bodies, improving environmental cleanliness with minimal human intervention.
