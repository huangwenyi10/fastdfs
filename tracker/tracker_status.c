/**
* Copyright (C) 2008 Happy Fish / YuQing
*
* FastDFS may be copied only under the terms of the GNU General
* Public License V3, which may be found in the FastDFS source kit.
* Please visit the FastDFS Home Page http://www.fastken.com/ for more detail.
**/

//tracker_func.c

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "fdfs_define.h"
#include "fastcommon/logger.h"
#include "fdfs_global.h"
#include "fastcommon/shared_func.h"
#include "fastcommon/sched_thread.h"
#include "fastcommon/ini_file_reader.h"
#include "tracker_types.h"
#include "tracker_global.h"
#include "tracker_status.h"

//#define <宏名> <字符串>
#define TRACKER_STATUS_FILENAME			".tracker_status"
#define TRACKER_STATUS_ITEM_UP_TIME		"up_time"
#define TRACKER_STATUS_ITEM_LAST_CHECK_TIME	"last_check_time"

int tracker_write_status_to_file(void *args)
{
	char full_filename[MAX_PATH_SIZE];
	char buff[256];
	int len;
    //设将可变参数(...)按照 format 格式化成字符串，并将字符串复制到 str 中，
    // size 为要写入的字符的最大数目，超过 size 会被截断。
    //g_fdfs_base_path = /tmp
    //完整地址：/tmp/data/.tracker_status
	snprintf(full_filename, sizeof(full_filename), "%s/data/%s", \
		g_fdfs_base_path, TRACKER_STATUS_FILENAME);
    //sprintf: 把格式化的数据写入某个字符串缓冲区
    //snprintf: 有长度限制地，把格式化的数据写入某个字符串缓冲区
	len = sprintf(buff, "%s=%d\n" \
		      "%s=%d\n",
		TRACKER_STATUS_ITEM_UP_TIME, (int)g_up_time,
		TRACKER_STATUS_ITEM_LAST_CHECK_TIME, (int)g_current_time
	);

	return writeToFile(full_filename, buff, len);
}

int tracker_load_status_from_file(TrackerStatus *pStatus)
{
	char full_filename[MAX_PATH_SIZE];
	IniContext iniContext;
	int result;

	snprintf(full_filename, sizeof(full_filename), "%s/data/%s", \
		g_fdfs_base_path, TRACKER_STATUS_FILENAME);
	if (!fileExists(full_filename))
	{
		return 0;
	}
	//void* memset(void* mem_loc, int c, size_t n);
    //第一个参数void* mem_loc：已开辟内存空间的首地址，通常为数组名或指针，由于其为void*，故函数能为任何类型的数据进行初始化。
    //第二个参数int c：初始化使用的内容，取器低字节部分。
    //第三个参数size_t n：需要初始化的字节数。
    //将已开辟内存空间 mem_loc 的首 n 个字节的值设为值 c
	memset(&iniContext, 0, sizeof(IniContext));
	if ((result=iniLoadFromFile(full_filename, &iniContext)) != 0)
	{
		logError("file: "__FILE__", line: %d, " \
			"load from status file \"%s\" fail, " \
			"error code: %d", \
			__LINE__, full_filename, result);
		return result;
	}
    // -> 定义了一个结构体，然后申明一个指针指向结构体，当需要用指针取出结构体中的数据，就要用到“->”
	pStatus->up_time = iniGetIntValue(NULL, TRACKER_STATUS_ITEM_UP_TIME, \
				&iniContext, 0);
	pStatus->last_check_time = iniGetIntValue(NULL, \
			TRACKER_STATUS_ITEM_LAST_CHECK_TIME, &iniContext, 0);

	iniFreeContext(&iniContext);

	return 0;
}

