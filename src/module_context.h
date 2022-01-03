#ifndef _MODULE_CONTEXT_H_
#define _MODULE_CONTEXT_H_

#include <ngx_core.h>
#include <ngx_http.h>
#include <ngx_config.h>

extern void *request_filter_create_main_conf(ngx_conf_t *);

extern ngx_int_t request_filter_post_method(ngx_conf_t *);

#endif

