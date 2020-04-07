#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
#include <assignment3/joy2twist.hpp>


void joy2twist::joycallback(const sensor_msgs::Joy::ConstPtr& joy){
geometry_msgs::Twist twist;
twist.angular.z=joy->axes[2];
twist.linear.x=joy->axes[1];
z=twist.angular.z;
x=twist.linear.x;
vel_pub.publish(twist);
}


joy2twist::joy2twist(ros::NodeHandle& nh):
nh(nh){
vel_pub=nh.advertise<geometry_msgs::Twist>("cmd_vel",10);
joy_sub=nh.subscribe<sensor_msgs::Joy>("joy",10,&joy2twist::joycallback,this);

}



