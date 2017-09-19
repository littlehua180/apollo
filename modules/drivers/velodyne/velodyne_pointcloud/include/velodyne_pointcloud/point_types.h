/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef MODULES_DRIVERS_VELODYNE_VELODYNE_POINTCLOUD_POINT_TYPES_H_
#define MODULES_DRIVERS_VELODYNE_VELODYNE_POINTCLOUD_POINT_TYPES_H_

#include <pcl/point_types.h>

namespace apollo {
namespace drivers {
namespace velodyne {

struct PointXYZIT {
  PCL_ADD_POINT4D
  uint8_t intensity;
  double timestamp;
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW  // make sure our new allocators are aligned
} EIGEN_ALIGN16;
// enforce SSE padding for correct memory alignment

}  // namespace velodyne
}  // namespace drivers
}  // namespace apollo

POINT_CLOUD_REGISTER_POINT_STRUCT(apollo::drivers::velodyne::PointXYZIT,
                                  (float, x, x)(float, y, y)(float, z, z)(
                                      uint8_t, intensity,
                                      intensity)(double, timestamp, timestamp))
#endif  // MODULES_DRIVERS_VELODYNE_VELODYNE_POINTCLOUD_POINT_TYPES_H_