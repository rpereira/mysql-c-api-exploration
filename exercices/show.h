#ifndef _LIB_SHOW_H_
#define _LIB_SHOW_H_

#include <mysql/mysql.h>

void list_table_status(MYSQL_RES *result);

void print_res_header(MYSQL_RES *result);

void print_res_top(MYSQL_RES *result);

void print_res_row(MYSQL_RES *result, MYSQL_ROW current);

void print_result_set(MYSQL_RES *result);

#endif /* _LIB_SHOW_H_ */
