#ifndef _MAIN_H_
#define _MAIN_H_

#include <ngx_core.h>
#include <ngx_http.h>

extern ngx_module_t request_filter;

extern ngx_http_module_t request_filter_ctx;

extern ngx_command_t request_filter_commands[];

/*
    接收指令参数
*/
typedef struct {
    /* 人机识别指令 */
    ngx_int_t limitTime;    /* 限制多少时间内 */
    ngx_int_t limitCount;   /* 限制连续访问多少次 */


    /* 黑名单 */
} request_filter_loc_conf_t;

#endif
