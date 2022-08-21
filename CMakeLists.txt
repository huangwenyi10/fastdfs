cmake_minimum_required(VERSION 3.15)

project(fastdfs C)

set(CMAKE_CXX_STANDARD 11)

include_directories(common)
include_directories(storage)
include_directories(tracker)
include_directories(test)
include_directories(client)
include_directories(/usr/local/include)

add_executable(fastdfs
        tracker/tracker_status.c
        tracker/fdfs_trackerd.c
        common/fdfs_global.c
        )