#include "utils.h"
#include "show.h"

#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // Skip the program name
    (argc)--;
    if (argc == 0) {
        printf("Usage: %s \"<mysql-statement>\"\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    MYSQL mysql;
    mysql_init(&mysql);

    if (mysql_real_connect(&mysql, "localhost", "root", "", "dvds",
                          0, NULL, 0) == NULL) {
        exit_with_error(&mysql);
    }

    if (mysql_query(&mysql, argv[1])) {
        exit_with_error(&mysql);
    }

    MYSQL_RES *result = mysql_store_result(&mysql);
    if (result == NULL) {
        exit_with_error(&mysql);
    }

    printf("mysql> %s;\n", argv[1]);
    print_result_set(&mysql, result);

    mysql_free_result(result);
    mysql_close(&mysql);

    exit(EXIT_SUCCESS);
}
