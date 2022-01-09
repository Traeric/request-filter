#include "machine_identify.h"
#include "main.h"


static void set_machine_value_to_conf(ngx_conf_t *cf, ngx_command_t *cmd, void *conf, ngx_uint_t offsetLen)
{
	char *p = conf;
	ngx_int_t *np;
	ngx_uint_t i;
	ngx_str_t *value = cf->args->elts;
	for (i = 1; i < cf->args->nelts; i++)
	{
		if (i - 1 >= offsetLen) {
			break;
		}
		np = (ngx_int_t *) (p + cmd->offset + (i - 1) * sizeof(ngx_int_t));
		*np = ngx_atoi(value[i].data, value[i].len);
	}
}

static ngx_int_t request_filter_machine_handler(ngx_http_request_t *);

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
	set_machine_value_to_conf(cf, cmd, conf, 2);
	return NGX_CONF_OK;
}

/*
 * 指令处理函数
 */
static ngx_int_t request_filter_machine_handler(ngx_http_request_t *r)
{
	request_filter_loc_conf_t *args;

	/* 获取参数 */
	args = ngx_http_get_module_loc_conf(r, request_filter);

	ngx_log_error(NGX_LOG_NOTICE, r->connection->log, 0, "************=========**********");
	ngx_log_error(NGX_LOG_NOTICE, r->connection->log, 0, "URI %V ||", &r->uri);
	ngx_log_error(NGX_LOG_NOTICE, r->connection->log, 0, "request filter处理函数2 %i ||", args->limitCount);

	return NGX_DECLINED;
}
