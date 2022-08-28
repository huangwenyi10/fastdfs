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

        test/test_upload.c
        client/fdfs_client.h
        client/client_func.h
        client/client_func.c
        client/client_global.c
        client/client_global.h
        client/fdfs_upload_file.c
        client/fdfs_append_file.c
        client/fdfs_download_file.c
        client/tracker_client.c
        client/tracker_client.h
        client/storage_client.c
        client/storage_client1.h
        client/storage_client.h

        common/fdfs_global.c
        common/fdfs_global.h
        common/fdfs_http_shared.c
        common/fdfs_http_shared.h
        common/fdfs_define.h

        tracker/tracker_global.c
        tracker/tracker_global.h
        tracker/fdfs_trackerd.c
        tracker/tracker_types.h
        tracker/fdfs_server_id_func.c
        tracker/fdfs_server_id_func.h
        tracker/tracker_func.c
        tracker/tracker_func.h
        tracker/tracker_nio.c
        tracker/tracker_nio.h
        tracker/tracker_relationship.c
        tracker/tracker_relationship.h
        tracker/tracker_dump.c
        tracker/tracker_dump.h
        tracker/tracker_http_check.c
        tracker/tracker_http_check.h
        tracker/tracker_proto.h
        tracker/tracker_proto.c
        tracker/tracker_mem.c
        tracker/tracker_mem.h
        tracker/tracker_service.c
        tracker/tracker_service.h
        tracker/tracker_status.c


        storage/fdfs_storaged.c
        storage/fdht_client/fdht_types.h
        storage/fdht_client/fdht_global.c
        storage/fdht_client/fdht_global.h
        storage/fdht_client/fdht_client.c
        storage/fdht_client/fdht_client.h
        storage/fdht_client/fdht_func.c
        storage/fdht_client/fdht_func.h


        )