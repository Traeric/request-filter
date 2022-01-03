#include "module_command.h"


/*
	指令处理函数
*/
char *request_filter_machine(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
	ngx_str_t *str = conf;
	char *rv;

	ngx_str_t *values = cf->args->elts;

	rv = ngx_conf_set_str_slot(cf, cmd, str);
	// NGX_CONF_OK 指令处理函数执行成功时返回 不为该返回值则表示指令处理函数执行出错
	if (rv != NGX_CONF_OK) {
		return rv;
	}
	// 打印字符
	ngx_log_error(NGX_LOG_NOTICE, cf->log, 0, "request filter指令初始化 %V", &values[0]);

	return NGX_CONF_OK;
}

