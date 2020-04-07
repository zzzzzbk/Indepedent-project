#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>
class joy2twist
{
public:
joy2twist(ros::NodeHandle& nh);
void joycallback(const sensor_msgs::Joy::ConstPtr& joy);
void timercallback(const ros::TimerEvent&);
ros::Publisher vel_pub;
private:
ros::NodeHandle nh;
ros::Subscriber joy_sub;
double x,z;
};

