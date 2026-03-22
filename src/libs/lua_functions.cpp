// lua_functions.cpp - Lua scripting engine functions
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 291 functions
//
// These are stub implementations to be replaced with matching decompilations.
// Each function needs to be decompiled to match the original binary.

#include "types.h"

// Forward declarations
class EStream;
class EFile;
class ERC;
class EMat4;
class EVec3;
class EVec4;
class EStorable;
class FastAllocPool;
struct ImageProcessingManager;
struct AptSysClock;
struct DVDFileInfo;
struct DVDCommandBlock;
struct DVDDiskID;
struct GXColor;
struct GXTexObj;
struct GXTlutObj;
struct OSThread;
struct OSAlarm;
struct OSContext;
struct OSMutex;
struct OSMessageQueue;
struct GXRenderModeObj;
struct GXFifoObj;
struct GXLightObj;
struct PADStatus;
struct CARDFileInfo;
struct DSPTask;
class BString;
class BString2;
class EAnimNodeDataPos;
class iResFile;
struct FrameEffectsManager;
struct EAnimNote;
struct AptGetBytesEnum;
struct ObjectSaveTypeTable2;
struct ObjectSaveTypeTable3;
struct ObjectSaveIDTable;
struct UserDataSaveLoad;
struct SpriteIdToResIdNode;
class cSimulator;
class Neighbor;
class CasSimDescriptionS2C;
struct AptValue;
struct AptObject;
struct CBFunctorBase;

// luaA_index(lua_State *, int)
// Address: 0x804440F4, Size: 60
void luaA_index() {
}

// luaA_indexAcceptable(lua_State *, int)
// Address: 0x80444130, Size: 80
void luaA_indexAcceptable() {
}

// luaA_pushobject(lua_State *, lua_TObject *)
// Address: 0x80444180, Size: 100
void luaA_pushobject() {
}

// lua_checkstack(lua_State *, int)
// Address: 0x804441E4, Size: 136
void lua_checkstack() {
}

// lua_xmove(lua_State *, lua_State *, int)
// Address: 0x8044426C, Size: 84
void lua_xmove() {
}

// lua_atpanic(lua_State *, int (*)(lua_State *))
// Address: 0x804442C0, Size: 16
void lua_atpanic() {
}

// lua_newthread(lua_State *)
// Address: 0x804442D0, Size: 104
void lua_newthread() {
}

// lua_gettop(lua_State *)
// Address: 0x80444338, Size: 20
void lua_gettop() {
}

// lua_settop(lua_State *, int)
// Address: 0x8044434C, Size: 112
void lua_settop() {
}

// lua_remove(lua_State *, int)
// Address: 0x804443BC, Size: 104
void lua_remove() {
}

// lua_insert(lua_State *, int)
// Address: 0x80444424, Size: 108
void lua_insert() {
}

// lua_replace(lua_State *, int)
// Address: 0x80444490, Size: 80
void lua_replace() {
}

// lua_pushvalue(lua_State *, int)
// Address: 0x804444E0, Size: 76
void lua_pushvalue() {
}

// lua_type(lua_State *, int)
// Address: 0x8044452C, Size: 52
void lua_type() {
}

// lua_typename(lua_State *, int)
// Address: 0x80444560, Size: 40
void lua_typename() {
}

// lua_iscfunction(lua_State *, int)
// Address: 0x80444588, Size: 88
void lua_iscfunction() {
}

// lua_isnumber(lua_State *, int)
// Address: 0x804445E0, Size: 88
void lua_isnumber() {
}

// lua_isstring(lua_State *, int)
// Address: 0x80444638, Size: 48
void lua_isstring() {
}

// lua_isuserdata(lua_State *, int)
// Address: 0x80444668, Size: 72
void lua_isuserdata() {
}

// lua_rawequal(lua_State *, int, int)
// Address: 0x804446B0, Size: 100
void lua_rawequal() {
}

// lua_equal(lua_State *, int, int)
// Address: 0x80444714, Size: 140
void lua_equal() {
}

// lua_lessthan(lua_State *, int, int)
// Address: 0x804447A0, Size: 104
void lua_lessthan() {
}

// lua_tonumber(lua_State *, int)
// Address: 0x80444808, Size: 80
void lua_tonumber() {
}

// lua_toboolean(lua_State *, int)
// Address: 0x80444858, Size: 84
void lua_toboolean() {
}

// lua_tostring(lua_State *, int)
// Address: 0x804448AC, Size: 152
void lua_tostring() {
}

// lua_strlen(lua_State *, int)
// Address: 0x80444944, Size: 108
void lua_strlen() {
}

// lua_tocfunction(lua_State *, int)
// Address: 0x804449B0, Size: 80
void lua_tocfunction() {
}

// lua_touserdata(lua_State *, int)
// Address: 0x80444A00, Size: 84
void lua_touserdata() {
}

// lua_tothread(lua_State *, int)
// Address: 0x80444A54, Size: 64
void lua_tothread() {
}

// lua_topointer(lua_State *, int)
// Address: 0x80444A94, Size: 136
void lua_topointer() {
}

// lua_pushnil(lua_State *)
// Address: 0x80444B1C, Size: 28
void lua_pushnil() {
}

// lua_pushnumber(lua_State *, int)
// Address: 0x80444B38, Size: 32
void lua_pushnumber() {
}

// lua_pushlstring(lua_State *, char *, unsigned int)
// Address: 0x80444B58, Size: 116
void lua_pushlstring() {
}

// lua_pushstring(lua_State *, char *)
// Address: 0x80444BCC, Size: 80
void lua_pushstring() {
}

// lua_pushvfstring(lua_State *, char *, __va_list_tag *)
// Address: 0x80444C1C, Size: 88
void lua_pushvfstring() {
}

// lua_pushfstring(lua_State *, char *,...)
// Address: 0x80444C74, Size: 204
void lua_pushfstring() {
}

// lua_pushcclosure(lua_State *, int (*)(lua_State *), int)
// Address: 0x80444D40, Size: 204
void lua_pushcclosure() {
}

// lua_pushboolean(lua_State *, int)
// Address: 0x80444E0C, Size: 48
void lua_pushboolean() {
}

// lua_pushlightuserdata(lua_State *, void *)
// Address: 0x80444E3C, Size: 32
void lua_pushlightuserdata() {
}

// lua_gettable(lua_State *, int)
// Address: 0x80444E5C, Size: 88
void lua_gettable() {
}

// lua_rawget(lua_State *, int)
// Address: 0x80444EB4, Size: 80
void lua_rawget() {
}

// lua_rawgeti(lua_State *, int, int)
// Address: 0x80444F04, Size: 92
void lua_rawgeti() {
}

// lua_newtable(lua_State *)
// Address: 0x80444F60, Size: 108
void lua_newtable() {
}

// lua_getmetatable(lua_State *, int)
// Address: 0x80444FCC, Size: 148
void lua_getmetatable() {
}

// lua_getfenv(lua_State *, int)
// Address: 0x80445060, Size: 112
void lua_getfenv() {
}

// lua_settable(lua_State *, int)
// Address: 0x804450D0, Size: 80
void lua_settable() {
}

// lua_rawset(lua_State *, int)
// Address: 0x80445120, Size: 96
void lua_rawset() {
}

// lua_rawseti(lua_State *, int, int)
// Address: 0x80445180, Size: 100
void lua_rawseti() {
}

// lua_setmetatable(lua_State *, int)
// Address: 0x804451E4, Size: 136
void lua_setmetatable() {
}

// lua_setfenv(lua_State *, int)
// Address: 0x8044526C, Size: 112
void lua_setfenv() {
}

// lua_call(lua_State *, int, int)
// Address: 0x804452DC, Size: 48
void lua_call() {
}

// lua_pcall(lua_State *, int, int, int)
// Address: 0x80445334, Size: 132
void lua_pcall() {
}

// lua_cpcall(lua_State *, int (*)(lua_State *), void *)
// Address: 0x8044547C, Size: 68
void lua_cpcall() {
}

// lua_load(lua_State *, char *(*)(lua_State *, void *, unsigned int *), void *, char *)
// Address: 0x804454C0, Size: 96
void lua_load() {
}

// lua_dump(lua_State *, int (*)(lua_State *, void *, unsigned int, void *), void *)
// Address: 0x80445520, Size: 96
void lua_dump() {
}

// lua_getgcthreshold(lua_State *)
// Address: 0x80445580, Size: 16
void lua_getgcthreshold() {
}

// lua_getgccount(lua_State *)
// Address: 0x80445590, Size: 16
void lua_getgccount() {
}

// lua_setgcthreshold(lua_State *, int)
// Address: 0x804455A0, Size: 92
void lua_setgcthreshold() {
}

// lua_version(void)
// Address: 0x804455FC, Size: 12
void lua_version() {
}

// lua_error(lua_State *)
// Address: 0x80445608, Size: 36
void lua_error() {
}

// lua_next(lua_State *, int)
// Address: 0x8044562C, Size: 96
void lua_next() {
}

// lua_concat(lua_State *, int)
// Address: 0x8044568C, Size: 184
void lua_concat() {
}

// lua_newuserdata(lua_State *, unsigned int)
// Address: 0x80445744, Size: 116
void lua_newuserdata() {
}

// lua_pushupvalues(lua_State *)
// Address: 0x804457B8, Size: 144
void lua_pushupvalues() {
}

// lua_getupvalue(lua_State *, int, int)
// Address: 0x80445900, Size: 92
void lua_getupvalue() {
}

// lua_setupvalue(lua_State *, int, int)
// Address: 0x8044595C, Size: 88
void lua_setupvalue() {
}

// luaG_inithooks(lua_State *)
// Address: 0x80445A64, Size: 80
void luaG_inithooks() {
}

// lua_sethook(lua_State *, void (*)(lua_State *, lua_Debug *), int, int)
// Address: 0x80445AB4, Size: 60
void lua_sethook() {
}

// lua_gethook(lua_State *)
// Address: 0x80445AF0, Size: 8
void lua_gethook() {
}

// lua_gethookmask(lua_State *)
// Address: 0x80445AF8, Size: 8
void lua_gethookmask() {
}

// lua_gethookcount(lua_State *)
// Address: 0x80445B00, Size: 8
void lua_gethookcount() {
}

// lua_getstack(lua_State *, int, lua_Debug *)
// Address: 0x80445B08, Size: 160
void lua_getstack() {
}

// lua_getlocal(lua_State *, lua_Debug *, int)
// Address: 0x80445BD0, Size: 140
void lua_getlocal() {
}

// lua_setlocal(lua_State *, lua_Debug *, int)
// Address: 0x80445C5C, Size: 184
void lua_setlocal() {
}

// lua_getinfo(lua_State *, char *, lua_Debug *)
// Address: 0x80446020, Size: 280
void lua_getinfo() {
}

// luaG_symbexec(Proto *, int, int)
// Address: 0x80446210, Size: 1084
void luaG_symbexec() {
}

// luaG_checkcode(Proto *)
// Address: 0x8044664C, Size: 40
void luaG_checkcode() {
}

// luaG_typeerror(lua_State *, lua_TObject *, char *)
// Address: 0x804468BC, Size: 200
void luaG_typeerror() {
}

// luaG_concaterror(lua_State *, lua_TObject *, lua_TObject *)
// Address: 0x80446984, Size: 56
void luaG_concaterror() {
}

// luaG_aritherror(lua_State *, lua_TObject *, lua_TObject *)
// Address: 0x804469BC, Size: 92
void luaG_aritherror() {
}

// luaG_ordererror(lua_State *, lua_TObject *, lua_TObject *)
// Address: 0x80446A18, Size: 116
void luaG_ordererror() {
}

// luaG_errormsg(lua_State *)
// Address: 0x80446B14, Size: 192
void luaG_errormsg() {
}

// luaG_runerror(lua_State *, char *,...)
// Address: 0x80446BD4, Size: 184
void luaG_runerror() {
}

// luaD_throw(lua_State *, int)
// Address: 0x80446D40, Size: 68
void luaD_throw() {
}

// luaD_rawrunprotected(lua_State *, void (*)(lua_State *, void *), void *)
// Address: 0x80446D84, Size: 120
void luaD_rawrunprotected() {
}

// luaD_reallocstack(lua_State *, int)
// Address: 0x80446EFC, Size: 108
void luaD_reallocstack() {
}

// luaD_reallocCI(lua_State *, int)
// Address: 0x80446F68, Size: 108
void luaD_reallocCI() {
}

// luaD_growstack(lua_State *, int)
// Address: 0x80446FD4, Size: 68
void luaD_growstack() {
}

// luaD_growCI(lua_State *)
// Address: 0x80447018, Size: 108
void luaD_growCI() {
}

// luaD_callhook(lua_State *, int, int)
// Address: 0x80447084, Size: 244
void luaD_callhook() {
}

// luaD_precall(lua_State *, lua_TObject *)
// Address: 0x804473C0, Size: 460
void luaD_precall() {
}

// luaD_poscall(lua_State *, int, lua_TObject *)
// Address: 0x80447610, Size: 208
void luaD_poscall() {
}

// luaD_call(lua_State *, lua_TObject *, int)
// Address: 0x804476E0, Size: 204
void luaD_call() {
}

// lua_resume(lua_State *, int)
// Address: 0x804478FC, Size: 232
void lua_resume() {
}

// lua_yield(lua_State *, int)
// Address: 0x804479E4, Size: 240
void lua_yield() {
}

// luaD_pcall(lua_State *, void (*)(lua_State *, void *), void *, int, int)
// Address: 0x80447AD4, Size: 164
void luaD_pcall() {
}

// luaD_protectedparser(lua_State *, Zio *, int)
// Address: 0x80447C40, Size: 152
void luaD_protectedparser() {
}

// luaU_dump(lua_State *, Proto *, int (*)(lua_State *, void *, unsigned int, void *), void *)
// Address: 0x80448220, Size: 76
void luaU_dump() {
}

// luaF_newCclosure(lua_State *, int)
// Address: 0x8044826C, Size: 100
void luaF_newCclosure() {
}

// luaF_newLclosure(lua_State *, int, lua_TObject *)
// Address: 0x804482D0, Size: 120
void luaF_newLclosure() {
}

// luaF_findupval(lua_State *, lua_TObject *)
// Address: 0x80448348, Size: 148
void luaF_findupval() {
}

// luaF_close(lua_State *, lua_TObject *)
// Address: 0x804483DC, Size: 120
void luaF_close() {
}

// luaF_newproto(lua_State *)
// Address: 0x80448454, Size: 156
void luaF_newproto() {
}

// luaF_freeproto(lua_State *, Proto *)
// Address: 0x804484F0, Size: 204
void luaF_freeproto() {
}

// luaF_freeclosure(lua_State *, Closure *)
// Address: 0x804485BC, Size: 76
void luaF_freeclosure() {
}

// luaF_getlocalname(Proto *, int, int)
// Address: 0x80448608, Size: 124
void luaF_getlocalname() {
}

// luaC_separateudata(lua_State *)
// Address: 0x8044878C, Size: 232
void luaC_separateudata() {
}

// luaC_callGCTM(lua_State *)
// Address: 0x80449410, Size: 188
void luaC_callGCTM() {
}

// luaC_sweep(lua_State *, int)
// Address: 0x804494CC, Size: 104
void luaC_sweep() {
}

// luaC_collectgarbage(lua_State *)
// Address: 0x804496A8, Size: 80
void luaC_collectgarbage() {
}

// luaC_link(lua_State *, GCObject *, unsigned char)
// Address: 0x804496F8, Size: 36
void luaC_link() {
}

// luaM_growaux(lua_State *, void *, int *, int, int, char *)
// Address: 0x8044971C, Size: 160
void luaM_growaux() {
}

// luaM_realloc(lua_State *, void *, unsigned long, unsigned long)
// Address: 0x804497BC, Size: 232
void luaM_realloc() {
}

// luaO_int2fb(unsigned int)
// Address: 0x804498A4, Size: 48
void luaO_int2fb() {
}

// luaO_log2(unsigned int)
// Address: 0x804498D4, Size: 164
void luaO_log2() {
}

// luaO_rawequalObj(lua_TObject *, lua_TObject *)
// Address: 0x80449978, Size: 124
void luaO_rawequalObj() {
}

// luaO_str2d(char *, int *)
// Address: 0x804499F4, Size: 156
void luaO_str2d() {
}

// luaO_pushvfstring(lua_State *, char *, __va_list_tag *)
// Address: 0x80449B10, Size: 752
void luaO_pushvfstring() {
}

// luaO_pushfstring(lua_State *, char *,...)
// Address: 0x80449E00, Size: 148
void luaO_pushfstring() {
}

// luaO_chunkid(char *, char *, int)
// Address: 0x80449E94, Size: 312
void luaO_chunkid() {
}

// luaI_registerlocalvar(LexState *, TString *)
// Address: 0x8044A2D0, Size: 140
void luaI_registerlocalvar() {
}

// luaY_parser(lua_State *, Zio *, Mbuffer *)
// Address: 0x8044ACB4, Size: 172
void luaY_parser() {
}

// luaY_field(LexState *, expdesc *)
// Address: 0x8044AD60, Size: 92
void luaY_field() {
}

// luaY_index(LexState *, expdesc *)
// Address: 0x8044ADBC, Size: 84
void luaY_index() {
}

// luaE_newthread(lua_State *)
// Address: 0x8044CFFC, Size: 112
void luaE_newthread() {
}

// luaE_freethread(lua_State *, lua_State *)
// Address: 0x8044D06C, Size: 80
void luaE_freethread() {
}

// lua_open(void)
// Address: 0x8044D0BC, Size: 136
void lua_open() {
}

// lua_close(lua_State *)
// Address: 0x8044D164, Size: 136
void lua_close() {
}

// luaS_freeall(lua_State *)
// Address: 0x8044D1EC, Size: 52
void luaS_freeall() {
}

// luaS_resize(lua_State *, int)
// Address: 0x8044D220, Size: 228
void luaS_resize() {
}

// luaS_newlstr(lua_State *, char *, unsigned int)
// Address: 0x8044D3E4, Size: 224
void luaS_newlstr() {
}

// luaS_newudata(lua_State *, unsigned int)
// Address: 0x8044D4C4, Size: 116
void luaS_newudata() {
}

// luaH_mainposition(Table *, lua_TObject *)
// Address: 0x8044D578, Size: 216
void luaH_mainposition() {
}

// luaH_index(lua_State *, Table *, lua_TObject *)
// Address: 0x8044D67C, Size: 184
void luaH_index() {
}

// luaH_next(lua_State *, Table *, lua_TObject *)
// Address: 0x8044D734, Size: 280
void luaH_next() {
}

// luaH_new(lua_State *, int, int)
// Address: 0x8044DE10, Size: 160
void luaH_new() {
}

// luaH_free(lua_State *, Table *)
// Address: 0x8044DEB0, Size: 120
void luaH_free() {
}

// luaH_getany(Table *, lua_TObject *)
// Address: 0x8044E05C, Size: 116
void luaH_getany() {
}

// luaH_getnum(Table *, int)
// Address: 0x8044E0D0, Size: 140
void luaH_getnum() {
}

// luaH_getstr(Table *, TString *)
// Address: 0x8044E15C, Size: 88
void luaH_getstr() {
}

// luaH_get(Table *, lua_TObject *)
// Address: 0x8044E1B4, Size: 76
void luaH_get() {
}

// luaH_set(lua_State *, Table *, lua_TObject *)
// Address: 0x8044E200, Size: 128
void luaH_set() {
}

// luaH_setnum(lua_State *, Table *, int)
// Address: 0x8044E280, Size: 100
void luaH_setnum() {
}

// luaT_init(lua_State *)
// Address: 0x8044E2E4, Size: 132
void luaT_init() {
}

// luaT_gettm(Table *, TMS, TString *)
// Address: 0x8044E368, Size: 88
void luaT_gettm() {
}

// luaT_gettmbyobj(lua_State *, lua_TObject *, TMS)
// Address: 0x8044E3C0, Size: 88
void luaT_gettmbyobj() {
}

// luaU_undump(lua_State *, Zio *, Mbuffer *)
// Address: 0x8044EE3C, Size: 108
void luaU_undump() {
}

// luaU_endianness(void)
// Address: 0x8044EEA8, Size: 8
void luaU_endianness() {
}

// luaV_tonumber(lua_TObject *, lua_TObject *)
// Address: 0x8044EEB0, Size: 112
void luaV_tonumber() {
}

// luaV_tostring(lua_State *, lua_TObject *)
// Address: 0x8044EF20, Size: 128
void luaV_tostring() {
}

// luaV_index(lua_State *, lua_TObject *, lua_TObject *, int)
// Address: 0x8044F224, Size: 172
void luaV_index() {
}

// luaV_getnotable(lua_State *, lua_TObject *, lua_TObject *, int)
// Address: 0x8044F2D0, Size: 156
void luaV_getnotable() {
}

// luaV_gettable(lua_State *, lua_TObject *, lua_TObject *, int)
// Address: 0x8044F36C, Size: 156
void luaV_gettable() {
}

// luaV_settable(lua_State *, lua_TObject *, lua_TObject *, lua_TObject *)
// Address: 0x8044F408, Size: 304
void luaV_settable() {
}

// luaV_strcmp(TString *, TString *)
// Address: 0x8044F77C, Size: 144
void luaV_strcmp() {
}

// luaV_lessthan(lua_State *, lua_TObject *, lua_TObject *)
// Address: 0x8044F80C, Size: 180
void luaV_lessthan() {
}

// luaV_lessequal(lua_State *, lua_TObject *, lua_TObject *)
// Address: 0x8044F8C0, Size: 240
void luaV_lessequal() {
}

// luaV_equalval(lua_State *, lua_TObject *, lua_TObject *)
// Address: 0x8044F9B0, Size: 280
void luaV_equalval() {
}

// luaV_concat(lua_State *, int, int)
// Address: 0x8044FAC8, Size: 488
void luaV_concat() {
}

// luaV_execute(lua_State *)
// Address: 0x8044FE54, Size: 4084
void luaV_execute() {
}

// luaZ_fill(Zio *)
// Address: 0x80450E48, Size: 116
void luaZ_fill() {
}

// luaZ_lookahead(Zio *)
// Address: 0x80450EBC, Size: 104
void luaZ_lookahead() {
}

// luaZ_init(Zio *, char *(*)(lua_State *, void *, unsigned int *), void *, char *)
// Address: 0x80450F24, Size: 28
void luaZ_init() {
}

// luaZ_read(Zio *, void *, unsigned int)
// Address: 0x80450F40, Size: 188
void luaZ_read() {
}

// luaZ_openspace(lua_State *, Mbuffer *, unsigned int)
// Address: 0x80450FFC, Size: 92
void luaZ_openspace() {
}

// luaL_argerror(lua_State *, int, char *)
// Address: 0x80451058, Size: 200
void luaL_argerror() {
}

// luaL_typerror(lua_State *, int, char *)
// Address: 0x80451120, Size: 108
void luaL_typerror() {
}

// luaL_where(lua_State *, int)
// Address: 0x804511D0, Size: 136
void luaL_where() {
}

// luaL_error(lua_State *, char *,...)
// Address: 0x80451258, Size: 204
void luaL_error() {
}

// luaL_findstring(char *, char **)
// Address: 0x80451324, Size: 108
void luaL_findstring() {
}

// luaL_newmetatable(lua_State *, char *)
// Address: 0x80451390, Size: 180
void luaL_newmetatable() {
}

// luaL_getmetatable(lua_State *, char *)
// Address: 0x80451444, Size: 56
void luaL_getmetatable() {
}

// luaL_checkudata(lua_State *, int, char *)
// Address: 0x8045147C, Size: 156
void luaL_checkudata() {
}

// luaL_checkstack(lua_State *, int, char *)
// Address: 0x80451518, Size: 80
void luaL_checkstack() {
}

// luaL_checktype(lua_State *, int, int)
// Address: 0x80451568, Size: 76
void luaL_checktype() {
}

// luaL_checkany(lua_State *, int)
// Address: 0x804515B4, Size: 76
void luaL_checkany() {
}

// luaL_checklstring(lua_State *, int, unsigned int *)
// Address: 0x80451600, Size: 104
void luaL_checklstring() {
}

// luaL_optlstring(lua_State *, int, char *, unsigned int *)
// Address: 0x80451668, Size: 124
void luaL_optlstring() {
}

// luaL_checknumber(lua_State *, int)
// Address: 0x804516E4, Size: 96
void luaL_checknumber() {
}

// luaL_optnumber(lua_State *, int, int)
// Address: 0x80451744, Size: 76
void luaL_optnumber() {
}

// luaL_getmetafield(lua_State *, int, char *)
// Address: 0x80451790, Size: 140
void luaL_getmetafield() {
}

// luaL_callmeta(lua_State *, int, char *)
// Address: 0x8045181C, Size: 132
void luaL_callmeta() {
}

// luaL_openlib(lua_State *, char *, luaL_reg *, int)
// Address: 0x804518A0, Size: 292
void luaL_openlib() {
}

// luaL_setn(lua_State *, int, int)
// Address: 0x80451AEC, Size: 224
void luaL_setn() {
}

// luaL_getn(lua_State *, int)
// Address: 0x80451BCC, Size: 268
void luaL_getn() {
}

// luaL_prepbuffer(luaL_Buffer *)
// Address: 0x80451DE0, Size: 64
void luaL_prepbuffer() {
}

// luaL_addlstring(luaL_Buffer *, char *, unsigned int)
// Address: 0x80451E20, Size: 116
void luaL_addlstring() {
}

// luaL_addstring(luaL_Buffer *, char *)
// Address: 0x80451E94, Size: 68
void luaL_addstring() {
}

// luaL_pushresult(luaL_Buffer *)
// Address: 0x80451ED8, Size: 64
void luaL_pushresult() {
}

// luaL_addvalue(luaL_Buffer *)
// Address: 0x80451F18, Size: 188
void luaL_addvalue() {
}

// luaL_buffinit(lua_State *, luaL_Buffer *)
// Address: 0x80451FD4, Size: 24
void luaL_buffinit() {
}

// luaL_ref(lua_State *, int)
// Address: 0x80451FEC, Size: 272
void luaL_ref() {
}

// luaL_unref(lua_State *, int, int)
// Address: 0x804520FC, Size: 144
void luaL_unref() {
}

// luaL_loadfile(lua_State *, char *)
// Address: 0x80452264, Size: 416
void luaL_loadfile() {
}

// luaL_loadbuffer(lua_State *, char *, unsigned int, char *)
// Address: 0x8045242C, Size: 52
void luaL_loadbuffer() {
}

// lua_dofile(lua_State *, char *)
// Address: 0x80452568, Size: 56
void lua_dofile() {
}

// lua_dobuffer(lua_State *, char *, unsigned int, char *)
// Address: 0x804525A0, Size: 56
void lua_dobuffer() {
}

// lua_dostring(lua_State *, char *)
// Address: 0x804525D8, Size: 72
void lua_dostring() {
}

// luaB_print(lua_State *)
// Address: 0x80452620, Size: 264
void luaB_print() {
}

// luaB_tonumber(lua_State *)
// Address: 0x80452728, Size: 304
void luaB_tonumber() {
}

// luaB_error(lua_State *)
// Address: 0x80452858, Size: 156
void luaB_error() {
}

// luaB_getmetatable(lua_State *)
// Address: 0x804528F4, Size: 104
void luaB_getmetatable() {
}

// luaB_setmetatable(lua_State *)
// Address: 0x8045295C, Size: 180
void luaB_setmetatable() {
}

// luaB_getfenv(lua_State *)
// Address: 0x80452B5C, Size: 76
void luaB_getfenv() {
}

// luaB_setfenv(lua_State *)
// Address: 0x80452BA8, Size: 224
void luaB_setfenv() {
}

// luaB_rawequal(lua_State *)
// Address: 0x80452C88, Size: 92
void luaB_rawequal() {
}

// luaB_rawget(lua_State *)
// Address: 0x80452CE4, Size: 80
void luaB_rawget() {
}

// luaB_rawset(lua_State *)
// Address: 0x80452D34, Size: 92
void luaB_rawset() {
}

// luaB_gcinfo(lua_State *)
// Address: 0x80452D90, Size: 80
void luaB_gcinfo() {
}

// luaB_collectgarbage(lua_State *)
// Address: 0x80452DE0, Size: 68
void luaB_collectgarbage() {
}

// luaB_type(lua_State *)
// Address: 0x80452E24, Size: 88
void luaB_type() {
}

// luaB_next(lua_State *)
// Address: 0x80452E7C, Size: 100
void luaB_next() {
}

// luaB_pairs(lua_State *)
// Address: 0x80452EE0, Size: 108
void luaB_pairs() {
}

// luaB_ipairs(lua_State *)
// Address: 0x80452F4C, Size: 220
void luaB_ipairs() {
}

// luaB_loadstring(lua_State *)
// Address: 0x80453074, Size: 108
void luaB_loadstring() {
}

// luaB_loadfile(lua_State *)
// Address: 0x804530E0, Size: 80
void luaB_loadfile() {
}

// luaB_dofile(lua_State *)
// Address: 0x80453130, Size: 128
void luaB_dofile() {
}

// luaB_assert(lua_State *)
// Address: 0x804531B0, Size: 136
void luaB_assert() {
}

// luaB_unpack(lua_State *)
// Address: 0x80453238, Size: 132
void luaB_unpack() {
}

// luaB_pcall(lua_State *)
// Address: 0x804532BC, Size: 112
void luaB_pcall() {
}

// luaB_xpcall(lua_State *)
// Address: 0x8045332C, Size: 128
void luaB_xpcall() {
}

// luaB_tostring(lua_State *)
// Address: 0x804533AC, Size: 432
void luaB_tostring() {
}

// luaB_newproxy(lua_State *)
// Address: 0x8045355C, Size: 272
void luaB_newproxy() {
}

// luaB_require(lua_State *)
// Address: 0x80453818, Size: 644
void luaB_require() {
}

// luaB_coresume(lua_State *)
// Address: 0x80453B78, Size: 172
void luaB_coresume() {
}

// luaB_auxwrap(lua_State *)
// Address: 0x80453C24, Size: 152
void luaB_auxwrap() {
}

// luaB_cocreate(lua_State *)
// Address: 0x80453CBC, Size: 140
void luaB_cocreate() {
}

// luaB_cowrap(lua_State *)
// Address: 0x80453D48, Size: 68
void luaB_cowrap() {
}

// luaB_yield(lua_State *)
// Address: 0x80453D8C, Size: 56
void luaB_yield() {
}

// luaB_costatus(lua_State *)
// Address: 0x80453DC4, Size: 196
void luaB_costatus() {
}

// luaopen_base(lua_State *)
// Address: 0x80453FAC, Size: 124
void luaopen_base() {
}

// luaopen_io(lua_State *)
// Address: 0x804559A8, Size: 208
void luaopen_io() {
}

// luaI_classend(MatchState *, char *)
// Address: 0x80456024, Size: 216
void luaI_classend() {
}

// luaI_singlematch(int, char *, char *)
// Address: 0x804562FC, Size: 136
void luaI_singlematch() {
}

// luaI_addquoted(lua_State *, luaL_Buffer *, int)
// Address: 0x804571C4, Size: 344
void luaI_addquoted() {
}

// luaopen_string(lua_State *)
// Address: 0x804576CC, Size: 56
void luaopen_string() {
}

// luaB_foreachi(lua_State *)
// Address: 0x80457704, Size: 204
void luaB_foreachi() {
}

// luaB_foreach(lua_State *)
// Address: 0x804577D0, Size: 192
void luaB_foreach() {
}

// luaB_getn(lua_State *)
// Address: 0x80457890, Size: 80
void luaB_getn() {
}

// luaB_setn(lua_State *)
// Address: 0x804578E0, Size: 84
void luaB_setn() {
}

// luaB_tinsert(lua_State *)
// Address: 0x80457934, Size: 232
void luaB_tinsert() {
}

// luaB_tremove(lua_State *)
// Address: 0x80457A1C, Size: 216
void luaB_tremove() {
}

// luaB_sort(lua_State *)
// Address: 0x80457FEC, Size: 156
void luaB_sort() {
}

// luaopen_table(lua_State *)
// Address: 0x80458088, Size: 56
void luaopen_table() {
}

// luaK_nil(FuncState *, int, int)
// Address: 0x80458360, Size: 164
void luaK_nil() {
}

// luaK_jump(FuncState *)
// Address: 0x80458404, Size: 96
void luaK_jump() {
}

// luaK_condjump(FuncState *, OpCode, int, int, int)
// Address: 0x80458464, Size: 52
void luaK_condjump() {
}

// luaK_fixjump(FuncState *, int, int)
// Address: 0x80458498, Size: 128
void luaK_fixjump() {
}

// luaK_getlabel(FuncState *)
// Address: 0x80458518, Size: 16
void luaK_getlabel() {
}

// luaK_getjump(FuncState *, int)
// Address: 0x80458528, Size: 56
void luaK_getjump() {
}

// luaK_patchlistaux(FuncState *, int, int, int, int, int, int)
// Address: 0x80458648, Size: 208
void luaK_patchlistaux() {
}

// luaK_dischargejpc(FuncState *)
// Address: 0x80458718, Size: 76
void luaK_dischargejpc() {
}

// luaK_patchlist(FuncState *, int, int)
// Address: 0x80458764, Size: 68
void luaK_patchlist() {
}

// luaK_patchtohere(FuncState *, int)
// Address: 0x804587A8, Size: 64
void luaK_patchtohere() {
}

// luaK_concat(FuncState *, int *, int)
// Address: 0x804587E8, Size: 124
void luaK_concat() {
}

// luaK_checkstack(FuncState *, int)
// Address: 0x80458864, Size: 96
void luaK_checkstack() {
}

// luaK_reserveregs(FuncState *, int)
// Address: 0x804588C4, Size: 60
void luaK_reserveregs() {
}

// luaK_stringK(FuncState *, TString *)
// Address: 0x80458A30, Size: 52
void luaK_stringK() {
}

// luaK_numberK(FuncState *, int)
// Address: 0x80458A64, Size: 52
void luaK_numberK() {
}

// luaK_setcallreturns(FuncState *, expdesc *, int)
// Address: 0x80458AD8, Size: 96
void luaK_setcallreturns() {
}

// luaK_dischargevars(FuncState *, expdesc *)
// Address: 0x80458B38, Size: 240
void luaK_dischargevars() {
}

// luaK_exp2reg(FuncState *, expdesc *, int)
// Address: 0x80458DE4, Size: 336
void luaK_exp2reg() {
}

// luaK_exp2nextreg(FuncState *, expdesc *)
// Address: 0x80458F34, Size: 92
void luaK_exp2nextreg() {
}

// luaK_exp2anyreg(FuncState *, expdesc *)
// Address: 0x80458F90, Size: 124
void luaK_exp2anyreg() {
}

// luaK_exp2val(FuncState *, expdesc *)
// Address: 0x8045900C, Size: 56
void luaK_exp2val() {
}

// luaK_exp2RK(FuncState *, expdesc *)
// Address: 0x80459044, Size: 152
void luaK_exp2RK() {
}

// luaK_storevar(FuncState *, expdesc *, expdesc *)
// Address: 0x804590DC, Size: 252
void luaK_storevar() {
}

// luaK_self(FuncState *, expdesc *, expdesc *)
// Address: 0x804591D8, Size: 144
void luaK_self() {
}

// luaK_goiftrue(FuncState *, expdesc *)
// Address: 0x80459354, Size: 168
void luaK_goiftrue() {
}

// luaK_goiffalse(FuncState *, expdesc *)
// Address: 0x804593FC, Size: 156
void luaK_goiffalse() {
}

// luaK_indexed(FuncState *, expdesc *, expdesc *)
// Address: 0x80459574, Size: 60
void luaK_indexed() {
}

// luaK_prefix(FuncState *, UnOpr, expdesc *)
// Address: 0x804595B0, Size: 204
void luaK_prefix() {
}

// luaK_infix(FuncState *, BinOpr, expdesc *)
// Address: 0x8045967C, Size: 180
void luaK_infix() {
}

// luaK_posfix(FuncState *, BinOpr, expdesc *, expdesc *)
// Address: 0x804597C4, Size: 500
void luaK_posfix() {
}

// luaK_fixline(FuncState *, int)
// Address: 0x804599B8, Size: 28
void luaK_fixline() {
}

// luaK_code(FuncState *, unsigned long, int)
// Address: 0x804599D4, Size: 224
void luaK_code() {
}

// luaK_codeABC(FuncState *, OpCode, int, int, int)
// Address: 0x80459AB4, Size: 64
void luaK_codeABC() {
}

// luaK_codeABx(FuncState *, OpCode, int, unsigned int)
// Address: 0x80459AF4, Size: 56
void luaK_codeABx() {
}

// luaX_init(lua_State *)
// Address: 0x80459B2C, Size: 116
void luaX_init() {
}

// luaX_checklimit(LexState *, int, int, char *)
// Address: 0x80459BA0, Size: 92
void luaX_checklimit() {
}

// luaX_errorline(LexState *, char *, char *, int)
// Address: 0x80459BFC, Size: 120
void luaX_errorline() {
}

// luaX_error(LexState *, char *, char *)
// Address: 0x80459C74, Size: 36
void luaX_error() {
}

// luaX_syntaxerror(LexState *, char *)
// Address: 0x80459C98, Size: 128
void luaX_syntaxerror() {
}

// luaX_token2str(LexState *, int)
// Address: 0x80459D18, Size: 84
void luaX_token2str() {
}

// luaX_lexerror(LexState *, char *, int)
// Address: 0x80459D6C, Size: 100
void luaX_lexerror() {
}

// luaX_setinput(lua_State *, LexState *, Zio *, TString *)
// Address: 0x80459E60, Size: 228
void luaX_setinput() {
}

// luaX_lex(LexState *, SemInfo *)
// Address: 0x8045ABF0, Size: 1828
void luaX_lex() {
}

// luaP_opnames
// Address: 0x80691F90, Size: 140
void luaP_opnames() {
}

// luaP_opmodes
// Address: 0x8069201C, Size: 35
void luaP_opmodes() {
}

// luaT_typenames
// Address: 0x806922F0, Size: 36
void luaT_typenames() {
}

// luaO_nilobject
// Address: 0x8079128C, Size: 8
void luaO_nilobject() {
}
