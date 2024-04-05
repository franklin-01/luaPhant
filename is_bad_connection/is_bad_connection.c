#include "is_bad_connection.h"
#include <lauxlib.h>
#include <libpq-fe.h>
#include <lua.h>
#include <stdbool.h>

int is_bad_connection(lua_State *L) {
  PGconn *conn = lua_touserdata(L, 1);

  if (PQstatus(conn) == CONNECTION_BAD) {
    lua_pushboolean(L, true);
    return 1;
  }

  lua_pushboolean(L, false);

  return 1;
}
