#include <lauxlib.h>
#include <libpq-fe.h>
#include <lua.h>

int exec_query(lua_State *L) {
  PGconn *conn = lua_touserdata(L, 1);

  const char *query = lua_tostring(L, 2);

  PGresult *result_data = PQexec(conn, query);

  lua_pushlightuserdata(L, result_data);

  return 1;
}
