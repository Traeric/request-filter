#include "module_command.h"
#include "main.h"


/*
 * 指令处理函数
 */
static ngx_int_t request_filter_machine_handler(ngx_http_request_t *r)
{
	request_filter_loc_conf_t *args;

	/* 获取参数 */
	args = ngx_http_get_module_loc_conf(r, request_filter);

	ngx_log_error(NGX_LOG_NOTICE, r->connection->log, 0, "************=========**********");
	ngx_log_error(NGX_LOG_NOTICE, r->connection->log, 0, "request filter处理函数1 %i ||", args->limitTime);
	ngx_log_error(NGX_LOG_NOTICE, r->connection->log, 0, "request filter处理函数2 %i ||", args->limitCount);

	return NGX_DECLINED;
}


/*
 * 设置处理函数
 */
char *request_filter_machine_init(ngx_conf_t *cf, ngx_command_t *cmd, void *conf)
{
	ngx_http_core_loc_conf_t *clcf;
	/* 得到location块的配置 */
	clcf = ngx_http_conf_get_module_loc_conf(cf, ngx_http_core_module);
	/* 设置处理函数 */
	clcf->handler = request_filter_machine_handler;
	/* 设置参数 */
	char *rv = ngx_conf_set_str_slot(cf, cmd, conf);
	if (rv != NGX_CONF_OK)
	{
		return rv;
	}

	return NGX_CONF_OK;
}
