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

    MYSQL *con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(EXIT_FAILURE);
    }

    if (mysql_real_connect(con, "localhost", "root", "", "dvds",
                          0, NULL, 0) == NULL) {
        exit_with_error(con);
    }

    if (mysql_query(con, argv[1])) {
        exit_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        exit_with_error(con);
    }

    printf("mysql> %s;\n", argv[1]);
    print_result_set(result);

    mysql_free_result(result);
    mysql_close(con);

    exit(EXIT_SUCCESS);
}
