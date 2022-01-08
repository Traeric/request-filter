#include "main.h"
#include "module_context.h"
#include "module_command.h"


// 模块入口
ngx_module_t request_filter = {
    NGX_MODULE_V1,
	&request_filter_ctx,
	request_filter_commands,
	NGX_HTTP_MODULE,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NGX_MODULE_V1_PADDING
};


// 模块信息
ngx_http_module_t request_filter_ctx = {
    NULL,       /* preconfiguration */
    NULL,       /* postconfiguration */
    /* 合并main配置 */
    NULL,  /* create main configuration */
    NULL,
    /* 合并server块配置 */
    NULL,
    NULL,
    /* 为location块配置分配内存 合并location块的配置 */
    ngx_http_request_filter_create_loc_conf,
    ngx_http_request_filter_merge_loc_conf
};

// 指令列表
ngx_command_t request_filter_commands[] = {
    /*
    人机识别指令
        mode1:
            在指定时间内 如果一个ip连续请求指定次数 认为是机器
        mode2:
            在指定时间内 如果一个ip连续请求某一资源指定次数 认为是机器
    */
    {
        ngx_string("request_filter_machine"),
		NGX_HTTP_LOC_CONF | NGX_CONF_TAKE2,
		request_filter_machine_init,
		NGX_HTTP_LOC_CONF_OFFSET,
		0,
		NULL
    },
    ngx_null_command,
};
