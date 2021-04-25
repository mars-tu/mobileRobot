#include "ros/ros.h"
#include "line_follower/Drive.h"
#include <sensor_msgs/Image.h>

ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction

void drive_robot(float lin_x, float ang_z)
{
    line_follower::Drive srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;
    if(client.call(srv))
    {
        ROS_INFO("Service /line_follower/command_robot Called L:%f A:%f",lin_x,ang_z); //---Check why srv.response.msg_feedback not working
//        ROS_INFO(srv.response.msg_feedback);
    }
    else ROS_ERROR("Failed to call /line_follower/command_robot service");
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
    int desired_pixel = 200; //taking a value lesser than pure white
    int spotted_counter = 0;
    int i = 650, l_value = 0, r_value = 0, mid;
	for(int j=0;j<img.step;j++)
        {
            if(img.data[(i*img.step)+j]<desired_pixel) //to find a pixle with one of rgb less than white
            {
                if(img.data[(i*img.step)+j+1] < desired_pixel && img.data[(i*img.step)+j+2] < desired_pixel) //to check if value of it's successive ones are less than 200 too.
                {
                    l_value = j;
                    if(j==0)
                    {
                        drive_robot(0.0,1.0); //left turn 90 degree
                        ros::Duration(2).sleep();
                        goto TIME_TO_UPATE;
                   }

                    while(img.data[(i*img.step)+j] < desired_pixel && img.data[(i*img.step)+j+1] < desired_pixel && img.data[(i*img.step)+j+2] < desired_pixel)
                    {
                        if(j==(img.step -1))
                        {
                            drive_robot(0.0,-1.0); //right turn for 90 degree
                            ros::Duration(2).sleep();
                            goto TIME_TO_UPATE;
                    }

                        j++;
                    }
                    r_value = j;
                    mid = (l_value + r_value)/2;

                    if(mid<=(img.step/3))
                    {
                        drive_robot(0.0,1.0); //left turn
                        ROS_INFO("left muda at %d",mid);
                        goto TIME_TO_UPATE;
		    }
                    if(mid>(img.step/3) && mid<(2*img.step/3))
                    {
                        drive_robot(1.0,0.0); //forward move
                        ROS_INFO("nahi muda");
		        goto TIME_TO_UPATE;
                    }
                    if(mid>=(2*img.step/3))
                    {
                        drive_robot(0.0,-1.0); //right turn
                        ROS_INFO("right muda at %d",mid);
                        goto TIME_TO_UPATE;
                    }
                }
            }
        }
    TIME_TO_UPATE: ; //updates the image by breaking the loop as soon as center of line is found
//    ROS_INFO("============IMAGE UPDATED===========");
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "line_follower");
    ros::NodeHandle n;

    // Define a client service to request from command_robot
    client = n.serviceClient<line_follower::Drive>("/line_follower/command_robot");

    // Subscribe to /camera/rgb/image_raw topic n
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    ros::spin();

    return 0;
}
