#include "utils.h"
#include "show.h"

#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_res_header(MYSQL_RES *result)
{
    MYSQL_FIELD *field;

    print_res_top(result);
    mysql_field_seek(result, 0);
    putchar('|');

    while((field = mysql_fetch_field(result))) {
        printf(" %-*s|", (int) field->max_length+1, field->name);
    }
    putchar('\n');
    print_res_top(result);
}

void print_res_top(MYSQL_RES *result)
{
    unsigned int i;
    unsigned int length;
    MYSQL_FIELD  *field;

    putchar('+');
    mysql_field_seek(result, 0);

    while((field = mysql_fetch_field(result))) {
        if ((length = (unsigned int) strlen(field->name)) > field->max_length) {
            field->max_length = length;
        }
        else {
            length = field->max_length;
        }

        for (i = length + 2; i-- > 0; ) {
            putchar('-');
        }
        putchar('+');
    }
    putchar('\n');
}

void print_res_row(MYSQL_RES *result, MYSQL_ROW current)
{
    unsigned int i;
    unsigned int length;
    MYSQL_FIELD  *field;

    putchar('|');
    mysql_field_seek(result, 0);

    for (i = 0 ; i < mysql_num_fields(result); i++) {
        field  = mysql_fetch_field(result);
        length = field->max_length;
        printf(" %-*s|", length + 1, current[i] ? (char*) current[i] : "");
    }
    putchar('\n');
}

void print_result_set(MYSQL *mysql, MYSQL_RES *result)
{
    MYSQL_ROW row;

    print_res_header(result);
    while ((row = mysql_fetch_row(result))) {
        print_res_row(result, row);
    }
    print_res_top(result);
    printf("%ld rows in set\n", (long) mysql_affected_rows(mysql));
}
