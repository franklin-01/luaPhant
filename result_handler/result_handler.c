#include "result_handler.h"
#include <lauxlib.h>
#include <libpq-fe.h>
#include <lua.h>

int result_handler(lua_State *L) {
  PGresult *data = (PGresult *)lua_touserdata(L, 1);

  const int rows_length = PQntuples(data);
  const int cols_length = PQnfields(data);

  lua_newtable(L);

  for (int i = 0; i < rows_length; i++) {
    lua_pushinteger(L, i + 1);
    lua_newtable(L);
    for (int j = 0; j < cols_length; j++) {
      lua_pushstring(L, PQfname(data, j));
      lua_pushstring(L, PQgetvalue(data, i, j));
      lua_settable(L, -3);
    }
    lua_settable(L, -3);
  }

  return 1;
}
