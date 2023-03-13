#include "ros/ros.h" //include headers ofthe ROS system 
#include "task1/Num.h" //include std_msgs
#include "std_msgs/Int32.h" //include std_msg

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Node1"); //initialize ROS
    ros::NodeHandle nh; //initialize node
    ros::Publisher number_pub = nh.advertise<task1::Num>("number_out", 1000); //indicates that will published messages on the topic number_out
    ros::Rate loop_rate(10); //specifies the frequency of the loop (10Hz)
    std_msgs::Int32 value_out;
    std::cout << "Enter a number: ";
    std::cin >> value_out.data; //asks for the input from the user as an Int32
    task1::Num valeu_out;
    while (ros::ok())
    {
        ROS_INFO("Number: %d", value_out); //prints the info on the console

        number_pub.publish(value_out); //broadcasts the message

        ros::spinOnce();

        loop_rate.sleep(); //allows the program to hit 10Hz
    }

    return 0;

}