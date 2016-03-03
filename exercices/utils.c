#include "utils.h"

#include <mysql/mysql.h>

void exit_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(EXIT_FAILURE);
}
