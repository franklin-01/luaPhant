#include "exec_query/exec_query.h"
#include "generateConnection/generate_connection.h"
#include "is_bad_connection/is_bad_connection.h"
#include "is_tuple_ok/is_tuple_ok.h"
#include "result_handler/result_handler.h"
#include <lauxlib.h>
#include <libpq-fe.h>
#include <lua.h>

int luaopen_postgres(lua_State *L) {
  const luaL_Reg function_list[6] = {
      {"is_bad_connection", is_bad_connection},
      {"generate_connection", generate_connection},
      {"is_tuple_ok", is_tuple_ok},
      {"result_handler", result_handler},
      {"exec_query", exec_query},
      {NULL, NULL}};

  luaL_newlib(L, function_list);
  return 1;
}
