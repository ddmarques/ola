#include "ros/ros.h" //include headers ofthe ROS system 
#include "std_msgs/Int32.h" //include std_msgs

void number_outCallback(const std_msgs::Int32::ConstPtr& msg) //function that is called when a message has arrived on the number_out topic
{
    ROS_INFO("I heard: %d", msg->data);
}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "Node2"); //initialize ROS
    ros::NodeHandle nh; //initialize node
    ros::Subscriber sub = nh.subscribe("number_out", 1000, number_outCallback); //subscribes to the number_out topic
    ros::spin(); //loop that calls message calbacks as fast as possible

}