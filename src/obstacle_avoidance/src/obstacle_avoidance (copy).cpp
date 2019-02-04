/************************************************************
 * Name: obstacle_avoidance.cpp
 * Author: Alyssa Kubota, Sanmi Adeleye
 * Date: 02/18/2018
 *
 * Description: This program will subscribe to the /blobs topic,
 *        and use the blob information to find and go towards
 *        the blobs in a user-set order.
 ***********************************************************/

#include <kobuki_msgs/BumperEvent.h> 
#include <cmvision/Blob.h>
#include <cmvision/Blobs.h>
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <cmvision/Blobs.h>
#include <stdio.h>
#include <vector>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <time.h>
#include <math.h>

ros::Publisher pub;

typedef pcl::PointCloud<pcl::PointXYZ> PointCloud;

uint16_t state;
double Center = 320;
std::vector<uint16_t> goal_xs;

double blob_x;






/************************************************************
 * Function Name: blobsCallBack
 * Parameters: const cmvision::Blobs
 * Returns: void
 *
 * Description: This is the callback function of the /blobs topic
 ***********************************************************/

void blobsCallBack (const cmvision::Blobs& blobsIn) //this gets the centroid of the color blob corresponding to the goal.
{
if (blobsIn.blob_count > 0){

state=1;    
int n=blobsIn.blob_count;
std::cout << "Blobs!!" << std::endl;
std::cout << n  << std::endl;

double goal_sum_x=0;
double goal_sum_y=0;


for (int i = 0; i < blobsIn.blob_count; i++){
	goal_sum_x += blobsIn.blobs[i].x;
	goal_sum_y += blobsIn.blobs[i].y;
}
goal_sum_x/=n;
goal_sum_y/=n;

std::cout << "Blob centroid x" << std::endl;
std::cout << goal_sum_x << std::endl;

std::cout << "Blob centroid y" << std::endl;
std::cout << goal_sum_y << std::endl;

    
blob_x=goal_sum_x;




}
}
/*
if (blobsIn.blob_count > 0){
		uint16_t blob_sum, blob_centroid_sum, num_blobs;
		int x_sum = 0;
		double z_sum = 0;
		uint16_t num_goal_blobs = 0;

		/************************************************************
		* These blobsIn.blobs[i].red, blobsIn.blobs[i].green, and blobsIn.blobs[i].blue values depend on the
		* values those are provided in the colors.txt file.
		* For example, the color file is like:
		* 
		* [Colors]
		* (255, 0, 0) 0.000000 10 RED 
		* (255, 255, 0) 0.000000 10 YELLOW 
		* [Thresholds]
		* ( 127:187, 142:161, 175:197 )
		* ( 47:99, 96:118, 162:175 )
		* 
		* Now, if a red blob is found, then the blobsIn.blobs[i].red will be 255, and the others will be 0.
		* Similarly, for yellow blob, blobsIn.blobs[i].red and blobsIn.blobs[i].green will be 255, and blobsIn.blobs[i].blue will be 0.
		************************************************************/
		
		/*std::vector<int> blobs_centroid_vector;

		blobs_centroid_vector.clear();

		for (int i = 0; i < blobsIn.blob_count; i++){
			ROS_INFO("Blob found");
			goal_sum_x += blobsIn.blobs[i].x;
		  goal_sum_y += blobsIn.blobs[i].y;
		}
    
    if (blobsIn.blobs[i].red == 0 && blobsIn.blobs[i].green == 255 && blobsIn.blobs[i].blue == 0){
      //goal_sum_x += blobsIn.blobs[i].x; //stores the average x-coordinate of the goal blobs
      //goal_sum_y += blobsIn.blobs[i].y; //stores the average y-coordinate of the goal blobs
      //num_goal_blobs++;
      ROS_INFO("We got blobs");
    }*/


/************************************************************
 * Function Name: PointCloud_Callback
 * Parameters: const PointCloud::ConstPtr
 * Returns: void
 *
 * Description: This is the callback function of the PointCloud
 * 				topic, flags when an object is below the threshhold 
 ***********************************************************/

int main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "blob");
  ros::NodeHandle nh;
  //States variable 
  state = 0;
  
  ros::Publisher cmdpub_ = nh.advertise<geometry_msgs::Twist> ("cmd_vel_mux/input/teleop", 10);

  //subscribe to /blobs topic 
  ros::Subscriber blobsSubscriber = nh.subscribe("/blobs", 10, blobsCallBack);

  // publishing the geometry message twist message
 // ros::Publisher velocityPublisher = nh.advertise<geometry_msgs::Twist>("cmd_vel_mux/input/teleop", 1000);

  ros::Rate loop_rate(10);
  geometry_msgs::Twist t;

  while(ros::ok()){


    if (state == 0){

    } 
    else if (state == 1) {

	std::cout << "Statae!!" << std::endl;
	std::cout << blob_x << std::endl;
	
	geometry_msgs::TwistPtr cmd(new geometry_msgs::Twist());
        cmd->linear.x = 0.1;
        cmd->angular.z = -(blob_x-350.0)*0.005;
        cmdpub_.publish(cmd);
	state=0;

    }

    // Spin
    ros::spinOnce();
    loop_rate.sleep();
    //velocityPublisher.publish(t);
  }
}

