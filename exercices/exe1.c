#include "utils.h"
#include "show.h"

#include <mysql/mysql.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    MYSQL *con = mysql_init(NULL);
    if (con == NULL) {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(EXIT_FAILURE);
    }

    if (mysql_real_connect(con, "localhost", "root", "", "dvds",
                          0, NULL, 0) == NULL) {
        exit_with_error(con);
    }

    char *stmt = "SELECT * FROM ACTOR LIMIT 5";
    if (mysql_query(con, stmt)) {
        exit_with_error(con);
    }

    MYSQL_RES *result = mysql_store_result(con);
    if (result == NULL) {
        exit_with_error(con);
    }

    printf("mysql> %s;\n", stmt);
    print_result_set(result);

    mysql_free_result(result);
    mysql_close(con);

    exit(EXIT_SUCCESS);
}
