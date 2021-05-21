# < Name of robot >
Repository for Mobile Robot by MARS, capable of autonomous navigation and transfer of goods in a high medical-risk environment, thus minimizing human to human interaction.

## Key Feature:-
*
*
*

## Project Structure:-
### Electro-mechanical design:
------------------------

### ROS Packages:
------------------------
* [Robot package](#robot)
* [Line Follower package](#line_follower)

  ## robot
* This package contains all the files related to robot and its configuration 

### Setup and launching the simulation environment:-

* Clone the repo, build in your preferred system and source (`source devel/setup.bash`) the workspace

* Command `roslaunch robot robot.launch` will launch the world with robot in an empty gazebo world and planning scene in RViz with TF, camera, robotmodel
already set in it

  ## line_follower
* Contains node `line_follower` to follow a black line on a white background by using camera stream via `sensor_msgs` messages (No openCV).
* `line_follower.launch` file launches the code for line following, but does not contain the LFR arena itself.
##### Steps to add arena given in repository or any other arena made by someone else.
* Add the `models` folder to your gazebo path (one of the possible pre-set path is `/home/user/.gazebo/models`).
* After gazebo environment is launched, add your arena from `insert` option and delete the existing ground plane.
