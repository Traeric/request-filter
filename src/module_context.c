#include "module_context.h"
#include "main.h"

/*
	创建主区块配置
*/
void *request_filter_create_main_conf(ngx_conf_t *cf)
{
	ngx_str_t *conf;
	conf = ngx_pcalloc(cf->pool, sizeof(ngx_str_t));
	return conf;
}

/*
	postconfiguration处理函数
*/
static ngx_int_t request_filter_post_handler(ngx_http_request_t *r)
{
	ngx_str_t *str = ngx_http_get_module_main_conf(r, request_filter);
	ngx_log_error(NGX_LOG_NOTICE, r->connection->log, 0, "request filter前置处理函数 %V, uri: %V", str, &r->uri);
	ngx_log_error(NGX_LOG_NOTICE, r->connection->log, 0, "=================request filter前置处理函数执行结束==================");
	return NGX_DECLINED;
}

/*
	注册postconfiguration处理函数
*/
ngx_int_t request_filter_post_method(ngx_conf_t *cf)
{
	ngx_http_handler_pt *h;
	ngx_http_core_main_conf_t *cmcf;

	cmcf = ngx_http_conf_get_module_main_conf(cf, ngx_http_core_module);
	h = ngx_array_push(&cmcf->phases[NGX_HTTP_POST_READ_PHASE].handlers);

	if (h == NULL) {
		return NGX_ERROR;
	}
	*h = request_filter_post_handler;
	return NGX_OK;
}


