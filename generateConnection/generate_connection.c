#include "generate_connection.h"
#include <lauxlib.h>
#include <libpq-fe.h>
#include <lua.h>

int generate_connection(lua_State *L) {
  const char *host = lua_tostring(L, 1);
  const char *port = lua_tostring(L, 2);
  const char *dbname = lua_tostring(L, 3);
  const char *user = lua_tostring(L, 4);
  const char *password = lua_tostring(L, 5);

  PGconn *conn = PQsetdbLogin(host, port, NULL, NULL, dbname, user, password);

  lua_pushlightuserdata(L, conn);

  return 1;
};
