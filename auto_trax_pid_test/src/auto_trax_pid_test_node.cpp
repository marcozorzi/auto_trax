//
// Created by marius on 16.04.16.
//

#include "auto_trax_pid_test/parameter/parameter_bag.h"
#include "auto_trax_pid_test/auto_trax_pid_test_processor.h"

void InitializeParameters(const ros::NodeHandle& nh, ParameterBag* parameter) {
  // Retrieve all parameters or set to default
  nh.param("subscribed_rostopic_img", parameter->subscribed_rostopic_img, kDefaultImageSubTopic);
  nh.param("queue_size_subscriber_img", parameter->queue_size_subscriber_img, kDefaultImageSubQueueSize);
  nh.param("subscribed_rostopic_scan", parameter->subscribed_rostopic_scan, kDefaultScanSubTopic);
  nh.param("queue_subscribed_rostopic_scan", parameter->queue_size_subscriber_scan, kDefaultScanSubQueueSize);
  nh.param("pub_rostopic_dist", parameter->pub_rostopic_dist, kDefaultDistPubTopic);
  nh.param("queue_size_pub_dist", parameter->queue_size_pub_dist, kDefaultDistPubQueueSize);
}

int main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "auto_trax_pid_test_node");
  ros::NodeHandle nh;

  // Initialize parameter structure
  ParameterBag parameter;
  InitializeParameters(nh, &parameter);

  // Construct class detection_processor with ros::NodeHandle and parameter structure
  AutoTraxPidTest pid_test(nh, parameter);

  // Relative path to package
  std::string string = ros::package::getPath("auto_trax_pid_test");

  // Spin
  ros::spin ();
}