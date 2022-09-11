cmake_minimum_required(VERSION 3.15)

project(fastdfs C)

set(CMAKE_CXX_STANDARD 11)


include_directories(common)
include_directories(storage)
include_directories(storage/fdht_client)
include_directories(storage/trunk_mgr)
include_directories(tracker)
#include_directories(test)
include_directories(client)
include_directories(/usr/local/include)

add_executable(fastdfs
#        test/test_upload.c

#        client/fdfs_client.h
#        client/client_func.h
#        client/client_func.c
#        client/client_global.c
#        client/client_global.h
#        client/fdfs_upload_file.c
#        client/fdfs_append_file.c
#        client/fdfs_download_file.c
#        client/tracker_client.c
#        client/tracker_client.h
#        client/storage_client.c
#        client/storage_client1.h
#        client/storage_client.h

        tracker/fdfs_server_id_func.c
        tracker/fdfs_server_id_func.h
        tracker/fdfs_shared_func.c
        tracker/fdfs_shared_func.h
        tracker/fdfs_trackerd.c
        tracker/tracker_dump.c
        tracker/tracker_dump.h
        tracker/tracker_func.c
        tracker/tracker_func.h
        tracker/tracker_global.c
        tracker/tracker_global.h
        tracker/tracker_http_check.h
        tracker/tracker_http_check.c
        tracker/tracker_mem.c
        tracker/tracker_mem.h
        tracker/tracker_nio.c
        tracker/tracker_nio.h
        tracker/tracker_proto.h
        tracker/tracker_proto.c
        tracker/tracker_relationship.c
        tracker/tracker_relationship.h
        tracker/tracker_service.c
        tracker/tracker_service.h
        tracker/tracker_status.c
        tracker/tracker_status.h
        tracker/tracker_types.h

        common/fdfs_define.h
        common/fdfs_global.c
        common/fdfs_global.h
        common/fdfs_http_shared.c
        common/fdfs_http_shared.h
        common/mime_file_parser.c
        common/mime_file_parser.h

        storage/fdht_client/fdht_client.c
        storage/fdht_client/fdht_client.h
        storage/fdht_client/fdht_define.h
        storage/fdht_client/fdht_func.c
        storage/fdht_client/fdht_func.h
        storage/fdht_client/fdht_global.c
        storage/fdht_client/fdht_global.h
        storage/fdht_client/fdht_proto.c
        storage/fdht_client/fdht_proto.h
        storage/fdht_client/fdht_proto_types.h
        storage/fdht_client/fdht_types.h

        storage/trunk_mgr/trunk_client.c
        storage/trunk_mgr/trunk_client.h
        storage/trunk_mgr/trunk_free_block_checker.c
        storage/trunk_mgr/trunk_free_block_checker.h
        storage/trunk_mgr/trunk_mem.c
        storage/trunk_mgr/trunk_mem.h
        storage/trunk_mgr/trunk_shared.c
        storage/trunk_mgr/trunk_shared.h
        storage/trunk_mgr/trunk_sync.c
        storage/trunk_mgr/trunk_sync.h

        storage/fdfs_storaged.c
        storage/storage_dio.c
        storage/storage_dio.h
        storage/storage_disk_recovery.c
        storage/storage_disk_recovery.h
        storage/storage_dump.c
        storage/storage_dump.h
        storage/storage_func.c
        storage/storage_func.h
        storage/storage_global.c
        storage/storage_global.h
        storage/storage_ip_changed_dealer.c
        storage/storage_ip_changed_dealer.h
        storage/storage_nio.c
        storage/storage_nio.h
        storage/storage_param_getter.c
        storage/storage_param_getter.h
        storage/storage_service.c
        storage/storage_service.h
        storage/storage_sync.c
        storage/storage_sync.h
        storage/storage_sync_func.h
        storage/storage_sync_func.c
        storage/tracker_client_thread.c
        storage/tracker_client_thread.h
        )