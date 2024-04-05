#include <lauxlib.h>
#include <libpq-fe.h>
#include <lua.h>
#include <stdbool.h>

int is_tuple_ok(lua_State *L) {
  PGresult *res = (PGresult *)lua_touserdata(L, 1);

  if (PQresultStatus(res) == PGRES_TUPLES_OK) {
    lua_pushboolean(L, true);
    return 1;
  }

  lua_pushboolean(L, false);

  return false;
}
