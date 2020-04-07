#include <ros/ros.h>
#include <assignment3/joy2twist.hpp>
void joy2twist::timercallback(const ros::TimerEvent&){
geometry_msgs::Twist twist;
twist.angular.z=z;
twist.linear.x=x;
vel_pub.publish(twist);
}


int main (int argc,char** argv)
{
ros::init(argc,argv,"joy2twist_node");
ros::NodeHandle nh;
joy2twist joy2twist(nh);
ros::Timer timer=nh.createTimer(ros::Duration(0.1),&joy2twist::timercallback,&joy2twist);
ros::spin();
}
