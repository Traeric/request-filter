#ifndef _MODULE_CONTEXT_H_
#define _MODULE_CONTEXT_H_

#include <ngx_core.h>
#include <ngx_http.h>
#include <ngx_config.h>

extern void *ngx_http_request_filter_create_loc_conf(ngx_conf_t *);

extern char *ngx_http_request_filter_merge_loc_conf(ngx_conf_t *, void *, void *);

#endif

