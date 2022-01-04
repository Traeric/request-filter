#ifndef _MODULE_COMMAND_H_
#define _MODULE_COMMAND_H_

#include <ngx_core.h>
#include <ngx_http.h>

extern char *request_filter_machine_init(ngx_conf_t *, ngx_command_t *, void *);

#endif
