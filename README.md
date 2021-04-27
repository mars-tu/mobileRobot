# mobileRobot
Repository for Mobile Robot made by MARS

## Packages:-
* [Robot package](#robot)
* [Line Follower package](#line_follower)

## robot
* This package contains all the files related to robot and its configuration 

### For launching the robot in gazebo follow the following steps

#### First create a workspace and src folder inside it

* `mkdir catkin_ws`
* `cd catkin_ws`
* `mkdir src`

#### Then clone the package inside the src folder

* `cd ~/catkin_ws/src`
* `git clone https://github.com/mars-tu/mobileRobot.git`

#### Then build the package 

* `cd ~/catkin_ws`
* `catkin_make`

#### Source the environment inside the workspace only

* `source devel/setup.bash`

#### Then open the world with robot in gazebo and planning scene in RViz

* `roslaunch robot robot.launch`

   This will open Rviz window with all the configurations already set like TF, camera, robotmodel etc and gazebo with robot spawned in the empty world.


## line_follower
* Contains node `line_follower` to follow a black line on a white background by using camera stream via `sensor_msgs` messages (No openCV).
* `line_follower.launch` file launches the code for line following, but does not contain the LFR arena itself.
##### Steps to add arena given in repository or any other arena made by someone else.
* Add the `models` folder to your gazebo path (one of the possible pre-set path is `/home/user/.gazebo/models`).
* After gazebo environment is launched, add your arena from `insert` option and delete the existing ground plane.
