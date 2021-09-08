# Medi Bot
Repository for Mobile Robot by MARS, capable of autonomous navigation and transfer of goods in a high medical-risk environment, thus minimizing human to human interaction.

## Key Feature:-
*
*
*

## Electro-mechanical design:

* MediBot Chassis.
![Image alt text](media/MediBot.jpg?raw=true "MediBot Chassis")


## ROS Packages:
* [Robot package](#robot)
* [Line Follower package](#line_follower)
* [Navigation Stack package](#nav_stack)

### robot
------------------
* This package contains all the files related to robot and its configuration 

### Setup and launching the simulation environment:-

* Clone the repo, build in your preferred system and source (`source devel/setup.bash`) the workspace

* Command `roslaunch robot robot.launch` will launch the world with robot in a gazebo world (suitable for easier time with SLAM and navigation) and planning scene in RViz with TF, camera, robotmodel already set in it.

### line_follower
-----------------
* Contains node `line_follower` to follow a black line on a white background by using camera stream via `sensor_msgs` messages (No openCV).
* `line_follower.launch` file launches the code for line following, but does not contain the LFR arena itself.
##### Steps to add arena given in repository or any other arena made by someone else.
* Add the `models` folder to your gazebo path (one of the possible pre-set path is `/home/user/.gazebo/models`).
* After gazebo environment is launched, add your arena from `insert` option and delete the existing ground plane.

### nav_stack
------------------
* This package contains all the files related to ros naviagtion stack used for our robot. 
* Contains all costmaps and AMCL parameters.

## Prerequisites
* C++14
* python 2.x
* Raspberry pi 3B (setup given below)
#### Note: Hardware prerequisites mentioned in xyz section.

## Setup
* [Raspi + OS setup](#setting-up-cpu)
2)

### Setting Up CPU
------------------
#### Installing Ubuntu and ROS on Raspberry pi
1) [Download](https://cdimage.ubuntu.com/releases/18.04/release/) the Ubuntu image for raspberry pi 3.
2) Flash the image with preferable software.
3) Follow the standard ARM installation instructions from [ROS Wiki](https://wiki.ros.org/melodic/Installation/Ubuntu) to install ROS Melodic.

#### Installing basic tools and setting them up
```
sudo apt-get update
sudo apt-get upgrade
sudo apt autoremove
```
