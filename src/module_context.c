#include "module_context.h"
#include "main.h"


/*
 * 为指令参数申请空间并赋予默认值
 */
void *ngx_http_request_filter_create_loc_conf(ngx_conf_t *cf)
{
	request_filter_loc_conf_t *conf;
	conf = ngx_pcalloc(cf->pool, sizeof(request_filter_loc_conf_t));
	if (conf == NULL)
	{
		return NGX_CONF_ERROR;
	}
	conf->limitTime = NGX_CONF_UNSET;
	conf->limitCount = NGX_CONF_UNSET;

	return conf;
}

/*
 * 合并location配置到全局的loc_conf中
 */
char *ngx_http_request_filter_merge_loc_conf(ngx_conf_t *cf, void *parent, void *child)
{
	request_filter_loc_conf_t *prev = parent;
	request_filter_loc_conf_t *conf = child;

	/* 默认3秒内 */
	ngx_conf_merge_value(conf->limitTime, prev->limitTime, 3000);
	/* 默认10次 */
	ngx_conf_merge_value(conf->limitCount, prev->limitCount, 10);

	return NGX_CONF_OK;
}




