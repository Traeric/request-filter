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
    NULL,
    request_filter_post_method,       /* postconfiguration */
    request_filter_create_main_conf,  /* create main configuration */
    NULL,
    NULL,
    NULL,
    NULL,
    NULL
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
		NGX_HTTP_MAIN_CONF | NGX_CONF_NOARGS | NGX_CONF_TAKE123,
		request_filter_machine,
		NGX_HTTP_MAIN_CONF_OFFSET,
		0,
		NULL
    },
    ngx_null_command,
};
