#ifndef _MAIN_H_
#define _MAIN_H_

#include <ngx_core.h>
#include <ngx_http.h>

extern ngx_module_t request_filter;

extern ngx_http_module_t request_filter_ctx;

extern ngx_command_t request_filter_commands[];

#endif
