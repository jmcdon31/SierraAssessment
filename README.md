# Spacecraft Attitude Control Software

My Approach to this problem was to try and showcase a variety of c++ and Flight Software Knowledge.
I created a Multi Threaded Application that utilizes a continuous control loop on the main thread 
to maintain attitude and ground command routing thread to receive commands.

I utilize a base CommandAcceptor class to let each object that wishes to process commands Register with a telemetry class for the command routing.

The AttitudeControl class utilizes generic Motor and Sensor interfaces to interact with the environment. I also Create a Mock environment class called MockSpaceAxis, that inherits the motor and sensor interface bases, which is intended to close the loop between writing out Motor commands and receiving Sensor data for the current Attitude.

## Building The Assessment
I utilized Ubuntu 22.04 to build this Assessment. It uses the CMake Build system. I created 2 simple scripts to configure and build the application. Assuming the User has at least CMake 3.20 and GCC 11 they should be able to build and run with the following commands

## Guidelines:

- There are a wide variety of solutions here, it's up to you how simple or complicated you would like to approach this.
- The solution should be written in C++ and buildable in GCC 11 or Clang 14.
- No OS-specific libraries should be used.
- Explicit build instructions should be provided.
- This task can take anywhere from 10 minutes to 60+ minutes; it's up to you how much time you spend. The approach will be weighted the most.
- Be prepared to discuss your solution.
- Please ask questions if any clarification is needed.

---

## Task Description

You have been recruited to create software for a spacecraft. Specifically, you will create software that will change the spacecraft’s attitude and determine which of the surrounding planets it is facing.

### Spacecraft Characteristics and Requirements:
1. The spacecraft has three Attitude Control Motors.
2. Each Attitude Control Motor corresponds to a Cartesian coordinate in a 3-dimensional plane (x, y, z).
3. When the Attitude Control Motors receive the request for an attitude change, the spacecraft will reorient itself and send back to ground control its new attitude as well as which planet it is currently pointing to.
4. When the spacecraft receives new coordinates, it starts from its current attitude when calculating a new attitude.
5. The spacecraft will always start its position at `(0, 0, 0)`. The Attitude Control Motors only change its orientation.
6. The solution should execute and wait for command-line input for a space-separated coordinate position.

---

### Coordinate Plane and Example

**Sensitive Planets in each quadrant:**
- **GRACE:** +x, +y, +z
- **BRAY:** +x, -y, +z
- **PRICE:** +x, +y, -z
- **MIG:** +x, -y, -z
- **WIEM:** -x, +y, +z
- **TURK:** -x, -y, +z
- **MROW:** -x, +y, -z
- **SEBAS:** -x, -y, -z

---

### Sample Input
- 3 4 5
- -4 0 -6
- 18 -5 3

### Sample Output
- Pointing Towards: GRACE at 3,4,5
- Pointing Towards: MROW at -1,4,-1
- Pointing Towards: BRAY at 17, -1, 2

### With a solution please provide:
- Version of C++ compiler used.
- OS used
- Build Instructions
