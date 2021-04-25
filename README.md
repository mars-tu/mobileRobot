# mobileRobot
Repository for Mobile Robot made by MARS

### Packages:-
* [Robot package](#robot)
* [Line Follower package](#line_follower)

## robot

## line_follower
* Contains node `line_follower` to follow a black line on a white background by using camera stream via `sensor_msgs` messages (No openCV).
* `line_follower.launch` file launches the code for line following, but does not contain the LFR arena itself.
##### Steps to add arena given in repository or any other arena made by someone else.
-> Add the `models` folder to your gazebo path (one of the possible pre-set path is `/home/user/.gazebo/models`).
-> After gazebo environment is launched, add your arena from `insert` option and delete the existing ground plane.
