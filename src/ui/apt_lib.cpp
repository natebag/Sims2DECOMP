// apt_lib.cpp - APT library internals
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 742 functions
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

// Set__Proto____9AptObjectP8AptValue
// Address: 0x80434EFC, Size: 152
void Set__Proto____9AptObjectP8AptValue() {
}

// negindex(lua_State *, int)
// Address: 0x8044408C, Size: 104
void negindex(lua_State * p0, int p1) {
}

// luaA_index(lua_State *, int)
// Address: 0x804440F4, Size: 60
void luaA_index(lua_State * p0, int p1) {
}

// luaA_indexAcceptable(lua_State *, int)
// Address: 0x80444130, Size: 80
void luaA_indexAcceptable(lua_State * p0, int p1) {
}

// luaA_pushobject(lua_State *, lua_TObject *)
// Address: 0x80444180, Size: 100
void luaA_pushobject(lua_State * p0, lua_TObject * p1) {
}

// lua_checkstack(lua_State *, int)
// Address: 0x804441E4, Size: 136
void lua_checkstack(lua_State * p0, int p1) {
}

// lua_xmove(lua_State *, lua_State *, int)
// Address: 0x8044426C, Size: 84
void lua_xmove(lua_State * p0, lua_State * p1, int p2) {
}

// lua_atpanic(lua_State *, int (*)(lua_State *))
// Address: 0x804442C0, Size: 16
void lua_atpanic(lua_State * p0, int (*)(lua_State *) p1) {
}

// lua_newthread(lua_State *)
// Address: 0x804442D0, Size: 104
void lua_newthread(lua_State * p0) {
}

// lua_gettop(lua_State *)
// Address: 0x80444338, Size: 20
void lua_gettop(lua_State * p0) {
}

// lua_settop(lua_State *, int)
// Address: 0x8044434C, Size: 112
void lua_settop(lua_State * p0, int p1) {
}

// lua_remove(lua_State *, int)
// Address: 0x804443BC, Size: 104
void lua_remove(lua_State * p0, int p1) {
}

// lua_insert(lua_State *, int)
// Address: 0x80444424, Size: 108
void lua_insert(lua_State * p0, int p1) {
}

// lua_replace(lua_State *, int)
// Address: 0x80444490, Size: 80
void lua_replace(lua_State * p0, int p1) {
}

// lua_pushvalue(lua_State *, int)
// Address: 0x804444E0, Size: 76
void lua_pushvalue(lua_State * p0, int p1) {
}

// lua_type(lua_State *, int)
// Address: 0x8044452C, Size: 52
void lua_type(lua_State * p0, int p1) {
}

// lua_typename(lua_State *, int)
// Address: 0x80444560, Size: 40
void lua_typename(lua_State * p0, int p1) {
}

// lua_iscfunction(lua_State *, int)
// Address: 0x80444588, Size: 88
void lua_iscfunction(lua_State * p0, int p1) {
}

// lua_isnumber(lua_State *, int)
// Address: 0x804445E0, Size: 88
void lua_isnumber(lua_State * p0, int p1) {
}

// lua_isstring(lua_State *, int)
// Address: 0x80444638, Size: 48
void lua_isstring(lua_State * p0, int p1) {
}

// lua_isuserdata(lua_State *, int)
// Address: 0x80444668, Size: 72
void lua_isuserdata(lua_State * p0, int p1) {
}

// lua_rawequal(lua_State *, int, int)
// Address: 0x804446B0, Size: 100
void lua_rawequal(lua_State * p0, int p1, int p2) {
}

// lua_equal(lua_State *, int, int)
// Address: 0x80444714, Size: 140
void lua_equal(lua_State * p0, int p1, int p2) {
}

// lua_lessthan(lua_State *, int, int)
// Address: 0x804447A0, Size: 104
void lua_lessthan(lua_State * p0, int p1, int p2) {
}

// lua_tonumber(lua_State *, int)
// Address: 0x80444808, Size: 80
void lua_tonumber(lua_State * p0, int p1) {
}

// lua_toboolean(lua_State *, int)
// Address: 0x80444858, Size: 84
void lua_toboolean(lua_State * p0, int p1) {
}

// lua_tostring(lua_State *, int)
// Address: 0x804448AC, Size: 152
void lua_tostring(lua_State * p0, int p1) {
}

// lua_strlen(lua_State *, int)
// Address: 0x80444944, Size: 108
void lua_strlen(lua_State * p0, int p1) {
}

// lua_tocfunction(lua_State *, int)
// Address: 0x804449B0, Size: 80
void lua_tocfunction(lua_State * p0, int p1) {
}

// lua_touserdata(lua_State *, int)
// Address: 0x80444A00, Size: 84
void lua_touserdata(lua_State * p0, int p1) {
}

// lua_tothread(lua_State *, int)
// Address: 0x80444A54, Size: 64
void lua_tothread(lua_State * p0, int p1) {
}

// lua_topointer(lua_State *, int)
// Address: 0x80444A94, Size: 136
void lua_topointer(lua_State * p0, int p1) {
}

// lua_pushnil(lua_State *)
// Address: 0x80444B1C, Size: 28
void lua_pushnil(lua_State * p0) {
}

// lua_pushnumber(lua_State *, int)
// Address: 0x80444B38, Size: 32
void lua_pushnumber(lua_State * p0, int p1) {
}

// lua_pushlstring(lua_State *, char *, unsigned int)
// Address: 0x80444B58, Size: 116
void lua_pushlstring(lua_State * p0, char * p1, unsigned int p2) {
}

// lua_pushstring(lua_State *, char *)
// Address: 0x80444BCC, Size: 80
void lua_pushstring(lua_State * p0, char * p1) {
}

// lua_pushvfstring(lua_State *, char *, __va_list_tag *)
// Address: 0x80444C1C, Size: 88
void lua_pushvfstring(lua_State * p0, char * p1, __va_list_tag * p2) {
}

// lua_pushfstring(lua_State *, char *,...)
// Address: 0x80444C74, Size: 204
void lua_pushfstring(lua_State * p0, char * p1, ... p2) {
}

// lua_pushcclosure(lua_State *, int (*)(lua_State *), int)
// Address: 0x80444D40, Size: 204
void lua_pushcclosure(lua_State * p0, int (*)(lua_State *) p1, int p2) {
}

// lua_pushboolean(lua_State *, int)
// Address: 0x80444E0C, Size: 48
void lua_pushboolean(lua_State * p0, int p1) {
}

// lua_pushlightuserdata(lua_State *, void *)
// Address: 0x80444E3C, Size: 32
void lua_pushlightuserdata(lua_State * p0, void * p1) {
}

// lua_gettable(lua_State *, int)
// Address: 0x80444E5C, Size: 88
void lua_gettable(lua_State * p0, int p1) {
}

// lua_rawget(lua_State *, int)
// Address: 0x80444EB4, Size: 80
void lua_rawget(lua_State * p0, int p1) {
}

// lua_rawgeti(lua_State *, int, int)
// Address: 0x80444F04, Size: 92
void lua_rawgeti(lua_State * p0, int p1, int p2) {
}

// lua_newtable(lua_State *)
// Address: 0x80444F60, Size: 108
void lua_newtable(lua_State * p0) {
}

// lua_getmetatable(lua_State *, int)
// Address: 0x80444FCC, Size: 148
void lua_getmetatable(lua_State * p0, int p1) {
}

// lua_getfenv(lua_State *, int)
// Address: 0x80445060, Size: 112
void lua_getfenv(lua_State * p0, int p1) {
}

// lua_settable(lua_State *, int)
// Address: 0x804450D0, Size: 80
void lua_settable(lua_State * p0, int p1) {
}

// lua_rawset(lua_State *, int)
// Address: 0x80445120, Size: 96
void lua_rawset(lua_State * p0, int p1) {
}

// lua_rawseti(lua_State *, int, int)
// Address: 0x80445180, Size: 100
void lua_rawseti(lua_State * p0, int p1, int p2) {
}

// lua_setmetatable(lua_State *, int)
// Address: 0x804451E4, Size: 136
void lua_setmetatable(lua_State * p0, int p1) {
}

// lua_setfenv(lua_State *, int)
// Address: 0x8044526C, Size: 112
void lua_setfenv(lua_State * p0, int p1) {
}

// lua_call(lua_State *, int, int)
// Address: 0x804452DC, Size: 48
void lua_call(lua_State * p0, int p1, int p2) {
}

// f_call(lua_State *, void *)
// Address: 0x8044530C, Size: 40
void f_call(lua_State * p0, void * p1) {
}

// lua_pcall(lua_State *, int, int, int)
// Address: 0x80445334, Size: 132
void lua_pcall(lua_State * p0, int p1, int p2, int p3) {
}

// f_Ccall(lua_State *, void *)
// Address: 0x804453B8, Size: 196
void f_Ccall(lua_State * p0, void * p1) {
}

// lua_cpcall(lua_State *, int (*)(lua_State *), void *)
// Address: 0x8044547C, Size: 68
void lua_cpcall(lua_State * p0, int (*)(lua_State *) p1, void * p2) {
}

// lua_load(lua_State *, char *(*)(lua_State *, void *, unsigned int *), void *, char *)
// Address: 0x804454C0, Size: 96
void lua_load(lua_State * p0, char *(*)(lua_State *, void *, unsigned int *) p1, void * p2, char * p3) {
}

// lua_dump(lua_State *, int (*)(lua_State *, void *, unsigned int, void *), void *)
// Address: 0x80445520, Size: 96
void lua_dump(lua_State * p0, int (*)(lua_State *, void *, unsigned int, void *) p1, void * p2) {
}

// lua_getgcthreshold(lua_State *)
// Address: 0x80445580, Size: 16
void lua_getgcthreshold(lua_State * p0) {
}

// lua_getgccount(lua_State *)
// Address: 0x80445590, Size: 16
void lua_getgccount(lua_State * p0) {
}

// lua_setgcthreshold(lua_State *, int)
// Address: 0x804455A0, Size: 92
void lua_setgcthreshold(lua_State * p0, int p1) {
}

// lua_version(void)
// Address: 0x804455FC, Size: 12
void lua_version() {
}

// lua_error(lua_State *)
// Address: 0x80445608, Size: 36
void lua_error(lua_State * p0) {
}

// lua_next(lua_State *, int)
// Address: 0x8044562C, Size: 96
void lua_next(lua_State * p0, int p1) {
}

// lua_concat(lua_State *, int)
// Address: 0x8044568C, Size: 184
void lua_concat(lua_State * p0, int p1) {
}

// lua_newuserdata(lua_State *, unsigned int)
// Address: 0x80445744, Size: 116
void lua_newuserdata(lua_State * p0, unsigned int p1) {
}

// lua_pushupvalues(lua_State *)
// Address: 0x804457B8, Size: 144
void lua_pushupvalues(lua_State * p0) {
}

// aux_upvalue(lua_State *, int, int, lua_TObject **)
// Address: 0x80445848, Size: 184
void aux_upvalue(lua_State * p0, int p1, int p2, lua_TObject ** p3) {
}

// lua_getupvalue(lua_State *, int, int)
// Address: 0x80445900, Size: 92
void lua_getupvalue(lua_State * p0, int p1, int p2) {
}

// lua_setupvalue(lua_State *, int, int)
// Address: 0x8044595C, Size: 88
void lua_setupvalue(lua_State * p0, int p1, int p2) {
}

// currentpc(CallInfo *)
// Address: 0x804459B4, Size: 76
void currentpc(CallInfo * p0) {
}

// currentline(CallInfo *)
// Address: 0x80445A00, Size: 100
void currentline(CallInfo * p0) {
}

// luaG_inithooks(lua_State *)
// Address: 0x80445A64, Size: 80
void luaG_inithooks(lua_State * p0) {
}

// lua_sethook(lua_State *, void (*)(lua_State *, lua_Debug *), int, int)
// Address: 0x80445AB4, Size: 60
void lua_sethook(lua_State * p0, void (*)(lua_State *, lua_Debug *) p1, int p2, int p3) {
}

// lua_gethook(lua_State *)
// Address: 0x80445AF0, Size: 8
void lua_gethook(lua_State * p0) {
}

// lua_gethookmask(lua_State *)
// Address: 0x80445AF8, Size: 8
void lua_gethookmask(lua_State * p0) {
}

// lua_gethookcount(lua_State *)
// Address: 0x80445B00, Size: 8
void lua_gethookcount(lua_State * p0) {
}

// lua_getstack(lua_State *, int, lua_Debug *)
// Address: 0x80445B08, Size: 160
void lua_getstack(lua_State * p0, int p1, lua_Debug * p2) {
}

// getluaproto(CallInfo *)
// Address: 0x80445BA8, Size: 40
void getluaproto(CallInfo * p0) {
}

// lua_getlocal(lua_State *, lua_Debug *, int)
// Address: 0x80445BD0, Size: 140
void lua_getlocal(lua_State * p0, lua_Debug * p1, int p2) {
}

// lua_setlocal(lua_State *, lua_Debug *, int)
// Address: 0x80445C5C, Size: 184
void lua_setlocal(lua_State * p0, lua_Debug * p1, int p2) {
}

// funcinfo(lua_Debug *, lua_TObject *)
// Address: 0x80445D14, Size: 156
void funcinfo(lua_Debug * p0, lua_TObject * p1) {
}

// travglobals(lua_State *, lua_TObject *)
// Address: 0x80445DB0, Size: 144
void travglobals(lua_State * p0, lua_TObject * p1) {
}

// info_tailcall(lua_State *, lua_Debug *)
// Address: 0x80445E40, Size: 128
void info_tailcall(lua_State * p0, lua_Debug * p1) {
}

// auxgetinfo(lua_State *, char *, lua_Debug *, lua_TObject *, CallInfo *)
// Address: 0x80445EC0, Size: 352
void auxgetinfo(lua_State * p0, char * p1, lua_Debug * p2, lua_TObject * p3, CallInfo * p4) {
}

// lua_getinfo(lua_State *, char *, lua_Debug *)
// Address: 0x80446020, Size: 280
void lua_getinfo(lua_State * p0, char * p1, lua_Debug * p2) {
}

// precheck(Proto *)
// Address: 0x80446138, Size: 84
void precheck(Proto * p0) {
}

// checkopenop(Proto *, int)
// Address: 0x8044618C, Size: 80
void checkopenop(Proto * p0, int p1) {
}

// checkRK(Proto *, int)
// Address: 0x804461DC, Size: 52
void checkRK(Proto * p0, int p1) {
}

// luaG_symbexec(Proto *, int, int)
// Address: 0x80446210, Size: 1084
void luaG_symbexec(Proto * p0, int p1, int p2) {
}

// luaG_checkcode(Proto *)
// Address: 0x8044664C, Size: 40
void luaG_checkcode(Proto * p0) {
}

// kname(Proto *, int)
// Address: 0x80446674, Size: 56
void kname(Proto * p0, int p1) {
}

// getobjname(CallInfo *, int, char **)
// Address: 0x804466AC, Size: 316
void getobjname(CallInfo * p0, int p1, char ** p2) {
}

// getfuncname(CallInfo *, char **)
// Address: 0x804467E8, Size: 160
void getfuncname(CallInfo * p0, char ** p1) {
}

// isinstack(CallInfo *, lua_TObject *)
// Address: 0x80446888, Size: 52
void isinstack(CallInfo * p0, lua_TObject * p1) {
}

// luaG_typeerror(lua_State *, lua_TObject *, char *)
// Address: 0x804468BC, Size: 200
void luaG_typeerror(lua_State * p0, lua_TObject * p1, char * p2) {
}

// luaG_concaterror(lua_State *, lua_TObject *, lua_TObject *)
// Address: 0x80446984, Size: 56
void luaG_concaterror(lua_State * p0, lua_TObject * p1, lua_TObject * p2) {
}

// luaG_aritherror(lua_State *, lua_TObject *, lua_TObject *)
// Address: 0x804469BC, Size: 92
void luaG_aritherror(lua_State * p0, lua_TObject * p1, lua_TObject * p2) {
}

// luaG_ordererror(lua_State *, lua_TObject *, lua_TObject *)
// Address: 0x80446A18, Size: 116
void luaG_ordererror(lua_State * p0, lua_TObject * p1, lua_TObject * p2) {
}

// addinfo(lua_State *, char *)
// Address: 0x80446A8C, Size: 136
void addinfo(lua_State * p0, char * p1) {
}

// luaG_errormsg(lua_State *)
// Address: 0x80446B14, Size: 192
void luaG_errormsg(lua_State * p0) {
}

// luaG_runerror(lua_State *, char *,...)
// Address: 0x80446BD4, Size: 184
void luaG_runerror(lua_State * p0, char * p1, ... p2) {
}

// seterrorobj(lua_State *, int, lua_TObject *)
// Address: 0x80446C8C, Size: 180
void seterrorobj(lua_State * p0, int p1, lua_TObject * p2) {
}

// luaD_throw(lua_State *, int)
// Address: 0x80446D40, Size: 68
void luaD_throw(lua_State * p0, int p1) {
}

// luaD_rawrunprotected(lua_State *, void (*)(lua_State *, void *), void *)
// Address: 0x80446D84, Size: 120
void luaD_rawrunprotected(lua_State * p0, void (*)(lua_State *, void *) p1, void * p2) {
}

// restore_stack_limit(lua_State *)
// Address: 0x80446DFC, Size: 112
void restore_stack_limit(lua_State * p0) {
}

// correctstack(lua_State *, lua_TObject *)
// Address: 0x80446E6C, Size: 144
void correctstack(lua_State * p0, lua_TObject * p1) {
}

// luaD_reallocstack(lua_State *, int)
// Address: 0x80446EFC, Size: 108
void luaD_reallocstack(lua_State * p0, int p1) {
}

// luaD_reallocCI(lua_State *, int)
// Address: 0x80446F68, Size: 108
void luaD_reallocCI(lua_State * p0, int p1) {
}

// luaD_growstack(lua_State *, int)
// Address: 0x80446FD4, Size: 68
void luaD_growstack(lua_State * p0, int p1) {
}

// luaD_growCI(lua_State *)
// Address: 0x80447018, Size: 108
void luaD_growCI(lua_State * p0) {
}

// luaD_callhook(lua_State *, int, int)
// Address: 0x80447084, Size: 244
void luaD_callhook(lua_State * p0, int p1, int p2) {
}

// adjust_varargs(lua_State *, int, lua_TObject *)
// Address: 0x80447178, Size: 372
void adjust_varargs(lua_State * p0, int p1, lua_TObject * p2) {
}

// tryfuncTM(lua_State *, lua_TObject *)
// Address: 0x804472EC, Size: 212
void tryfuncTM(lua_State * p0, lua_TObject * p1) {
}

// luaD_precall(lua_State *, lua_TObject *)
// Address: 0x804473C0, Size: 460
void luaD_precall(lua_State * p0, lua_TObject * p1) {
}

// callrethooks(lua_State *, lua_TObject *)
// Address: 0x8044758C, Size: 132
void callrethooks(lua_State * p0, lua_TObject * p1) {
}

// luaD_poscall(lua_State *, int, lua_TObject *)
// Address: 0x80447610, Size: 208
void luaD_poscall(lua_State * p0, int p1, lua_TObject * p2) {
}

// luaD_call(lua_State *, lua_TObject *, int)
// Address: 0x804476E0, Size: 204
void luaD_call(lua_State * p0, lua_TObject * p1, int p2) {
}

// resume(lua_State *, void *)
// Address: 0x804477AC, Size: 196
void resume(lua_State * p0, void * p1) {
}

// resume_error(lua_State *, char *)
// Address: 0x80447870, Size: 140
void resume_error(lua_State * p0, char * p1) {
}

// lua_resume(lua_State *, int)
// Address: 0x804478FC, Size: 232
void lua_resume(lua_State * p0, int p1) {
}

// lua_yield(lua_State *, int)
// Address: 0x804479E4, Size: 240
void lua_yield(lua_State * p0, int p1) {
}

// luaD_pcall(lua_State *, void (*)(lua_State *, void *), void *, int, int)
// Address: 0x80447AD4, Size: 164
void luaD_pcall(lua_State * p0, void (*)(lua_State *, void *) p1, void * p2, int p3, int p4) {
}

// f_parser(lua_State *, void *)
// Address: 0x80447B78, Size: 200
void f_parser(lua_State * p0, void * p1) {
}

// luaD_protectedparser(lua_State *, Zio *, int)
// Address: 0x80447C40, Size: 152
void luaD_protectedparser(lua_State * p0, Zio * p1, int p2) {
}

// DumpBlock(void *, unsigned int, DumpState *)
// Address: 0x80447CD8, Size: 60
void DumpBlock(void * p0, unsigned int p1, DumpState * p2) {
}

// DumpByte(int, DumpState *)
// Address: 0x80447D14, Size: 48
void DumpByte(int p0, DumpState * p1) {
}

// DumpInt(int, DumpState *)
// Address: 0x80447D44, Size: 48
void DumpInt(int p0, DumpState * p1) {
}

// DumpSize(unsigned int, DumpState *)
// Address: 0x80447D74, Size: 48
void DumpSize(unsigned int p0, DumpState * p1) {
}

// DumpNumber(int, DumpState *)
// Address: 0x80447DA4, Size: 48
void DumpNumber(int p0, DumpState * p1) {
}

// DumpString(TString *, DumpState *)
// Address: 0x80447DD4, Size: 108
void DumpString(TString * p0, DumpState * p1) {
}

// DumpCode(Proto *, DumpState *)
// Address: 0x80447E40, Size: 72
void DumpCode(Proto * p0, DumpState * p1) {
}

// DumpLocals(Proto *, DumpState *)
// Address: 0x80447E88, Size: 140
void DumpLocals(Proto * p0, DumpState * p1) {
}

// DumpLines(Proto *, DumpState *)
// Address: 0x80447F14, Size: 72
void DumpLines(Proto * p0, DumpState * p1) {
}

// DumpUpvalues(Proto *, DumpState *)
// Address: 0x80447F5C, Size: 96
void DumpUpvalues(Proto * p0, DumpState * p1) {
}

// DumpConstants(Proto *, DumpState *)
// Address: 0x80447FBC, Size: 224
void DumpConstants(Proto * p0, DumpState * p1) {
}

// DumpFunction(Proto *, TString *, DumpState *)
// Address: 0x8044809C, Size: 192
void DumpFunction(Proto * p0, TString * p1, DumpState * p2) {
}

// DumpHeader(DumpState *)
// Address: 0x8044815C, Size: 196
void DumpHeader(DumpState * p0) {
}

// luaU_dump(lua_State *, Proto *, int (*)(lua_State *, void *, unsigned int, void *), void *)
// Address: 0x80448220, Size: 76
void luaU_dump(lua_State * p0, Proto * p1, int (*)(lua_State *, void *, unsigned int, void *) p2, void * p3) {
}

// luaF_newCclosure(lua_State *, int)
// Address: 0x8044826C, Size: 100
void luaF_newCclosure(lua_State * p0, int p1) {
}

// luaF_newLclosure(lua_State *, int, lua_TObject *)
// Address: 0x804482D0, Size: 120
void luaF_newLclosure(lua_State * p0, int p1, lua_TObject * p2) {
}

// luaF_findupval(lua_State *, lua_TObject *)
// Address: 0x80448348, Size: 148
void luaF_findupval(lua_State * p0, lua_TObject * p1) {
}

// luaF_close(lua_State *, lua_TObject *)
// Address: 0x804483DC, Size: 120
void luaF_close(lua_State * p0, lua_TObject * p1) {
}

// luaF_newproto(lua_State *)
// Address: 0x80448454, Size: 156
void luaF_newproto(lua_State * p0) {
}

// luaF_freeproto(lua_State *, Proto *)
// Address: 0x804484F0, Size: 204
void luaF_freeproto(lua_State * p0, Proto * p1) {
}

// luaF_freeclosure(lua_State *, Closure *)
// Address: 0x804485BC, Size: 76
void luaF_freeclosure(lua_State * p0, Closure * p1) {
}

// luaF_getlocalname(Proto *, int, int)
// Address: 0x80448608, Size: 124
void luaF_getlocalname(Proto * p0, int p1, int p2) {
}

// reallymarkobject(GCState *, GCObject *)
// Address: 0x80448684, Size: 172
void reallymarkobject(GCState * p0, GCObject * p1) {
}

// marktmu(GCState *)
// Address: 0x80448730, Size: 92
void marktmu(GCState * p0) {
}

// luaC_separateudata(lua_State *)
// Address: 0x8044878C, Size: 232
void luaC_separateudata(lua_State * p0) {
}

// removekey(Node *)
// Address: 0x80448874, Size: 32
void removekey(Node * p0) {
}

// traversetable(GCState *, Table *)
// Address: 0x80448894, Size: 552
void traversetable(GCState * p0, Table * p1) {
}

// traverseproto(GCState *, Proto *)
// Address: 0x80448ABC, Size: 328
void traverseproto(GCState * p0, Proto * p1) {
}

// traverseclosure(GCState *, Closure *)
// Address: 0x80448C04, Size: 300
void traverseclosure(GCState * p0, Closure * p1) {
}

// checkstacksizes(lua_State *, lua_TObject *)
// Address: 0x80448D30, Size: 160
void checkstacksizes(lua_State * p0, lua_TObject * p1) {
}

// traversestack(GCState *, lua_State *)
// Address: 0x80448DD0, Size: 248
void traversestack(GCState * p0, lua_State * p1) {
}

// propagatemarks(GCState *)
// Address: 0x80448EC8, Size: 184
void propagatemarks(GCState * p0) {
}

// valismarked(lua_TObject *)
// Address: 0x80448F80, Size: 72
void valismarked(lua_TObject * p0) {
}

// cleartablekeys(GCObject *)
// Address: 0x80448FC8, Size: 132
void cleartablekeys(GCObject * p0) {
}

// cleartablevalues(GCObject *)
// Address: 0x8044904C, Size: 192
void cleartablevalues(GCObject * p0) {
}

// freeobj(lua_State *, GCObject *)
// Address: 0x8044910C, Size: 176
void freeobj(lua_State * p0, GCObject * p1) {
}

// sweeplist(lua_State *, GCObject **, int)
// Address: 0x804491BC, Size: 128
void sweeplist(lua_State * p0, GCObject ** p1, int p2) {
}

// sweepstrings(lua_State *, int)
// Address: 0x8044923C, Size: 128
void sweepstrings(lua_State * p0, int p1) {
}

// checkSizes(lua_State *, unsigned int)
// Address: 0x804492BC, Size: 184
void checkSizes(lua_State * p0, unsigned int p1) {
}

// do1gcTM(lua_State *, Udata *)
// Address: 0x80449374, Size: 156
void do1gcTM(lua_State * p0, Udata * p1) {
}

// luaC_callGCTM(lua_State *)
// Address: 0x80449410, Size: 188
void luaC_callGCTM(lua_State * p0) {
}

// luaC_sweep(lua_State *, int)
// Address: 0x804494CC, Size: 104
void luaC_sweep(lua_State * p0, int p1) {
}

// markroot(GCState *, lua_State *)
// Address: 0x80449534, Size: 184
void markroot(GCState * p0, lua_State * p1) {
}

// mark(lua_State *)
// Address: 0x804495EC, Size: 188
void mark(lua_State * p0) {
}

// luaC_collectgarbage(lua_State *)
// Address: 0x804496A8, Size: 80
void luaC_collectgarbage(lua_State * p0) {
}

// luaC_link(lua_State *, GCObject *, unsigned char)
// Address: 0x804496F8, Size: 36
void luaC_link(lua_State * p0, GCObject * p1, unsigned char p2) {
}

// luaM_growaux(lua_State *, void *, int *, int, int, char *)
// Address: 0x8044971C, Size: 160
void luaM_growaux(lua_State * p0, void * p1, int * p2, int p3, int p4, char * p5) {
}

// luaM_realloc(lua_State *, void *, unsigned long, unsigned long)
// Address: 0x804497BC, Size: 232
void luaM_realloc(lua_State * p0, void * p1, unsigned long p2, unsigned long p3) {
}

// luaO_int2fb(unsigned int)
// Address: 0x804498A4, Size: 48
void luaO_int2fb(unsigned int p0) {
}

// luaO_log2(unsigned int)
// Address: 0x804498D4, Size: 164
void luaO_log2(unsigned int p0) {
}

// luaO_rawequalObj(lua_TObject *, lua_TObject *)
// Address: 0x80449978, Size: 124
void luaO_rawequalObj(lua_TObject * p0, lua_TObject * p1) {
}

// luaO_str2d(char *, int *)
// Address: 0x804499F4, Size: 156
void luaO_str2d(char * p0, int * p1) {
}

// pushstr(lua_State *, char *)
// Address: 0x80449A90, Size: 128
void pushstr(lua_State * p0, char * p1) {
}

// luaO_pushvfstring(lua_State *, char *, __va_list_tag *)
// Address: 0x80449B10, Size: 752
void luaO_pushvfstring(lua_State * p0, char * p1, __va_list_tag * p2) {
}

// luaO_pushfstring(lua_State *, char *,...)
// Address: 0x80449E00, Size: 148
void luaO_pushfstring(lua_State * p0, char * p1, ... p2) {
}

// luaO_chunkid(char *, char *, int)
// Address: 0x80449E94, Size: 312
void luaO_chunkid(char * p0, char * p1, int p2) {
}

// next(LexState *)
// Address: 0x80449FCC, Size: 104
void next(LexState * p0) {
}

// lookahead(LexState *)
// Address: 0x8044A034, Size: 52
void lookahead(LexState * p0) {
}

// error_expected(LexState *, int)
// Address: 0x8044A068, Size: 84
void error_expected(LexState * p0, int p1) {
}

// testnext(LexState *, int)
// Address: 0x8044A0BC, Size: 60
void testnext(LexState * p0, int p1) {
}

// check(LexState *, int)
// Address: 0x8044A0F8, Size: 68
void check(LexState * p0, int p1) {
}

// check_match(LexState *, int, int, int)
// Address: 0x8044A13C, Size: 168
void check_match(LexState * p0, int p1, int p2, int p3) {
}

// str_checkname(LexState *)
// Address: 0x8044A1E4, Size: 80
void str_checkname(LexState * p0) {
}

// init_exp(expdesc *, expkind, int)
// Address: 0x8044A234, Size: 24
void init_exp(expdesc * p0, expkind p1, int p2) {
}

// codestring(LexState *, expdesc *, TString *)
// Address: 0x8044A24C, Size: 68
void codestring(LexState * p0, expdesc * p1, TString * p2) {
}

// checkname(LexState *, expdesc *)
// Address: 0x8044A290, Size: 64
void checkname(LexState * p0, expdesc * p1) {
}

// luaI_registerlocalvar(LexState *, TString *)
// Address: 0x8044A2D0, Size: 140
void luaI_registerlocalvar(LexState * p0, TString * p1) {
}

// new_localvar(LexState *, TString *, int)
// Address: 0x8044A35C, Size: 112
void new_localvar(LexState * p0, TString * p1, int p2) {
}

// adjustlocalvars(LexState *, int)
// Address: 0x8044A3CC, Size: 84
void adjustlocalvars(LexState * p0, int p1) {
}

// removevars(LexState *, int)
// Address: 0x8044A420, Size: 76
void removevars(LexState * p0, int p1) {
}

// new_localvarstr(LexState *, char *, int)
// Address: 0x8044A46C, Size: 92
void new_localvarstr(LexState * p0, char * p1, int p2) {
}

// create_local(LexState *, char *)
// Address: 0x8044A4C8, Size: 60
void create_local(LexState * p0, char * p1) {
}

// indexupvalue(FuncState *, TString *, expdesc *)
// Address: 0x8044A504, Size: 312
void indexupvalue(FuncState * p0, TString * p1, expdesc * p2) {
}

// searchvar(FuncState *, TString *)
// Address: 0x8044A63C, Size: 76
void searchvar(FuncState * p0, TString * p1) {
}

// markupval(FuncState *, int)
// Address: 0x8044A688, Size: 52
void markupval(FuncState * p0, int p1) {
}

// singlevaraux(FuncState *, TString *, expdesc *, int)
// Address: 0x8044A6BC, Size: 224
void singlevaraux(FuncState * p0, TString * p1, expdesc * p2, int p3) {
}

// singlevar(LexState *, expdesc *, int)
// Address: 0x8044A79C, Size: 80
void singlevar(LexState * p0, expdesc * p1, int p2) {
}

// adjust_assign(LexState *, int, int, expdesc *)
// Address: 0x8044A7EC, Size: 168
void adjust_assign(LexState * p0, int p1, int p2, expdesc * p3) {
}

// code_params(LexState *, int, int)
// Address: 0x8044A894, Size: 132
void code_params(LexState * p0, int p1, int p2) {
}

// enterblock(FuncState *, BlockCnt *, int)
// Address: 0x8044A918, Size: 44
void enterblock(FuncState * p0, BlockCnt * p1, int p2) {
}

// leaveblock(FuncState *)
// Address: 0x8044A944, Size: 120
void leaveblock(FuncState * p0) {
}

// pushclosure(LexState *, FuncState *, expdesc *)
// Address: 0x8044A9BC, Size: 264
void pushclosure(LexState * p0, FuncState * p1, expdesc * p2) {
}

// open_func(LexState *, FuncState *)
// Address: 0x8044AAC4, Size: 164
void open_func(LexState * p0, FuncState * p1) {
}

// close_func(LexState *)
// Address: 0x8044AB68, Size: 332
void close_func(LexState * p0) {
}

// luaY_parser(lua_State *, Zio *, Mbuffer *)
// Address: 0x8044ACB4, Size: 172
void luaY_parser(lua_State * p0, Zio * p1, Mbuffer * p2) {
}

// luaY_field(LexState *, expdesc *)
// Address: 0x8044AD60, Size: 92
void luaY_field(LexState * p0, expdesc * p1) {
}

// luaY_index(LexState *, expdesc *)
// Address: 0x8044ADBC, Size: 84
void luaY_index(LexState * p0, expdesc * p1) {
}

// recfield(LexState *, ConsControl *)
// Address: 0x8044AE10, Size: 232
void recfield(LexState * p0, ConsControl * p1) {
}

// closelistfield(FuncState *, ConsControl *)
// Address: 0x8044AEF8, Size: 128
void closelistfield(FuncState * p0, ConsControl * p1) {
}

// lastlistfield(FuncState *, ConsControl *)
// Address: 0x8044AF78, Size: 172
void lastlistfield(FuncState * p0, ConsControl * p1) {
}

// listfield(LexState *, ConsControl *)
// Address: 0x8044B024, Size: 100
void listfield(LexState * p0, ConsControl * p1) {
}

// constructor(LexState *, expdesc *)
// Address: 0x8044B088, Size: 428
void constructor(LexState * p0, expdesc * p1) {
}

// parlist(LexState *)
// Address: 0x8044B234, Size: 188
void parlist(LexState * p0) {
}

// body(LexState *, expdesc *, int, int)
// Address: 0x8044B2F0, Size: 176
void body(LexState * p0, expdesc * p1, int p2, int p3) {
}

// explist1(LexState *, expdesc *)
// Address: 0x8044B3A0, Size: 108
void explist1(LexState * p0, expdesc * p1) {
}

// funcargs(LexState *, expdesc *)
// Address: 0x8044B40C, Size: 384
void funcargs(LexState * p0, expdesc * p1) {
}

// prefixexp(LexState *, expdesc *)
// Address: 0x8044B58C, Size: 164
void prefixexp(LexState * p0, expdesc * p1) {
}

// primaryexp(LexState *, expdesc *)
// Address: 0x8044B630, Size: 252
void primaryexp(LexState * p0, expdesc * p1) {
}

// simpleexp(LexState *, expdesc *)
// Address: 0x8044B72C, Size: 292
void simpleexp(LexState * p0, expdesc * p1) {
}

// getunopr(int)
// Address: 0x8044B850, Size: 40
void getunopr(int p0) {
}

// getbinopr(int)
// Address: 0x8044B878, Size: 272
void getbinopr(int p0) {
}

// subexpr(LexState *, expdesc *, int)
// Address: 0x8044B988, Size: 320
void subexpr(LexState * p0, expdesc * p1, int p2) {
}

// expr(LexState *, expdesc *)
// Address: 0x8044BAC8, Size: 36
void expr(LexState * p0, expdesc * p1) {
}

// block_follow(int)
// Address: 0x8044BAEC, Size: 56
void block_follow(int p0) {
}

// block(LexState *)
// Address: 0x8044BB24, Size: 76
void block(LexState * p0) {
}

// check_conflict(LexState *, LHS_assign *, expdesc *)
// Address: 0x8044BB70, Size: 172
void check_conflict(LexState * p0, LHS_assign * p1, expdesc * p2) {
}

// assignment(LexState *, LHS_assign *, int)
// Address: 0x8044BC1C, Size: 340
void assignment(LexState * p0, LHS_assign * p1, int p2) {
}

// cond(LexState *, expdesc *)
// Address: 0x8044BD70, Size: 92
void cond(LexState * p0, expdesc * p1) {
}

// whilestat(LexState *, int)
// Address: 0x8044BDCC, Size: 456
void whilestat(LexState * p0, int p1) {
}

// repeatstat(LexState *, int)
// Address: 0x8044BF94, Size: 148
void repeatstat(LexState * p0, int p1) {
}

// exp1(LexState *)
// Address: 0x8044C028, Size: 68
void exp1(LexState * p0) {
}

// forbody(LexState *, int, int, int, int)
// Address: 0x8044C06C, Size: 252
void forbody(LexState * p0, int p1, int p2, int p3, int p4) {
}

// fornum(LexState *, TString *, int)
// Address: 0x8044C168, Size: 280
void fornum(LexState * p0, TString * p1, int p2) {
}

// forlist(LexState *, TString *)
// Address: 0x8044C280, Size: 268
void forlist(LexState * p0, TString * p1) {
}

// forstat(LexState *, int)
// Address: 0x8044C38C, Size: 200
void forstat(LexState * p0, int p1) {
}

// test_then_block(LexState *, expdesc *)
// Address: 0x8044C454, Size: 80
void test_then_block(LexState * p0, expdesc * p1) {
}

// ifstat(LexState *, int)
// Address: 0x8044C4A4, Size: 244
void ifstat(LexState * p0, int p1) {
}

// localfunc(LexState *)
// Address: 0x8044C598, Size: 188
void localfunc(LexState * p0) {
}

// localstat(LexState *)
// Address: 0x8044C654, Size: 168
void localstat(LexState * p0) {
}

// funcname(LexState *, expdesc *)
// Address: 0x8044C6FC, Size: 116
void funcname(LexState * p0, expdesc * p1) {
}

// funcstat(LexState *, int)
// Address: 0x8044C770, Size: 112
void funcstat(LexState * p0, int p1) {
}

// exprstat(LexState *)
// Address: 0x8044C7E0, Size: 112
void exprstat(LexState * p0) {
}

// retstat(LexState *)
// Address: 0x8044C850, Size: 248
void retstat(LexState * p0) {
}

// breakstat(LexState *)
// Address: 0x8044C948, Size: 176
void breakstat(LexState * p0) {
}

// statement(LexState *)
// Address: 0x8044C9F8, Size: 364
void statement(LexState * p0) {
}

// chunk(LexState *)
// Address: 0x8044CB64, Size: 152
void chunk(LexState * p0) {
}

// default_panic(lua_State *)
// Address: 0x8044CBFC, Size: 8
void default_panic(lua_State * p0) {
}

// mallocstate(lua_State *)
// Address: 0x8044CC04, Size: 60
void mallocstate(lua_State * p0) {
}

// freestate(lua_State *, lua_State *)
// Address: 0x8044CC40, Size: 40
void freestate(lua_State * p0, lua_State * p1) {
}

// stack_init(lua_State *, lua_State *)
// Address: 0x8044CC68, Size: 196
void stack_init(lua_State * p0, lua_State * p1) {
}

// freestack(lua_State *, lua_State *)
// Address: 0x8044CD2C, Size: 88
void freestack(lua_State * p0, lua_State * p1) {
}

// f_luaopen(lua_State *, void *)
// Address: 0x8044CD84, Size: 380
void f_luaopen(lua_State * p0, void * p1) {
}

// preinit_state(lua_State *)
// Address: 0x8044CF00, Size: 76
void preinit_state(lua_State * p0) {
}

// close_state(lua_State *)
// Address: 0x8044CF4C, Size: 176
void close_state(lua_State * p0) {
}

// luaE_newthread(lua_State *)
// Address: 0x8044CFFC, Size: 112
void luaE_newthread(lua_State * p0) {
}

// luaE_freethread(lua_State *, lua_State *)
// Address: 0x8044D06C, Size: 80
void luaE_freethread(lua_State * p0, lua_State * p1) {
}

// lua_open(void)
// Address: 0x8044D0BC, Size: 136
void lua_open() {
}

// callallgcTM(lua_State *, void *)
// Address: 0x8044D144, Size: 32
void callallgcTM(lua_State * p0, void * p1) {
}

// lua_close(lua_State *)
// Address: 0x8044D164, Size: 136
void lua_close(lua_State * p0) {
}

// luaS_freeall(lua_State *)
// Address: 0x8044D1EC, Size: 52
void luaS_freeall(lua_State * p0) {
}

// luaS_resize(lua_State *, int)
// Address: 0x8044D220, Size: 228
void luaS_resize(lua_State * p0, int p1) {
}

// newlstr(lua_State *, char *, unsigned int, unsigned int)
// Address: 0x8044D304, Size: 224
void newlstr(lua_State * p0, char * p1, unsigned int p2, unsigned int p3) {
}

// luaS_newlstr(lua_State *, char *, unsigned int)
// Address: 0x8044D3E4, Size: 224
void luaS_newlstr(lua_State * p0, char * p1, unsigned int p2) {
}

// luaS_newudata(lua_State *, unsigned int)
// Address: 0x8044D4C4, Size: 116
void luaS_newudata(lua_State * p0, unsigned int p1) {
}

// hashnum(Table *, int)
// Address: 0x8044D538, Size: 64
void hashnum(Table * p0, int p1) {
}

// luaH_mainposition(Table *, lua_TObject *)
// Address: 0x8044D578, Size: 216
void luaH_mainposition(Table * p0, lua_TObject * p1) {
}

// arrayindex(lua_TObject *)
// Address: 0x8044D650, Size: 44
void arrayindex(lua_TObject * p0) {
}

// luaH_index(lua_State *, Table *, lua_TObject *)
// Address: 0x8044D67C, Size: 184
void luaH_index(lua_State * p0, Table * p1, lua_TObject * p2) {
}

// luaH_next(lua_State *, Table *, lua_TObject *)
// Address: 0x8044D734, Size: 280
void luaH_next(lua_State * p0, Table * p1, lua_TObject * p2) {
}

// computesizes(int *, int, int *, int *)
// Address: 0x8044D84C, Size: 200
void computesizes(int * p0, int p1, int * p2, int * p3) {
}

// numuse(Table *, int *, int *)
// Address: 0x8044D914, Size: 412
void numuse(Table * p0, int * p1, int * p2) {
}

// setarrayvector(lua_State *, Table *, int)
// Address: 0x8044DAB0, Size: 124
void setarrayvector(lua_State * p0, Table * p1, int p2) {
}

// setnodevector(lua_State *, Table *, int)
// Address: 0x8044DB2C, Size: 216
void setnodevector(lua_State * p0, Table * p1, int p2) {
}

// resize(lua_State *, Table *, int, int)
// Address: 0x8044DC04, Size: 432
void resize(lua_State * p0, Table * p1, int p2, int p3) {
}

// rehash(lua_State *, Table *)
// Address: 0x8044DDB4, Size: 92
void rehash(lua_State * p0, Table * p1) {
}

// luaH_new(lua_State *, int, int)
// Address: 0x8044DE10, Size: 160
void luaH_new(lua_State * p0, int p1, int p2) {
}

// luaH_free(lua_State *, Table *)
// Address: 0x8044DEB0, Size: 120
void luaH_free(lua_State * p0, Table * p1) {
}

// newkey(lua_State *, Table *, lua_TObject *)
// Address: 0x8044DF28, Size: 308
void newkey(lua_State * p0, Table * p1, lua_TObject * p2) {
}

// luaH_getany(Table *, lua_TObject *)
// Address: 0x8044E05C, Size: 116
void luaH_getany(Table * p0, lua_TObject * p1) {
}

// luaH_getnum(Table *, int)
// Address: 0x8044E0D0, Size: 140
void luaH_getnum(Table * p0, int p1) {
}

// luaH_getstr(Table *, TString *)
// Address: 0x8044E15C, Size: 88
void luaH_getstr(Table * p0, TString * p1) {
}

// luaH_get(Table *, lua_TObject *)
// Address: 0x8044E1B4, Size: 76
void luaH_get(Table * p0, lua_TObject * p1) {
}

// luaH_set(lua_State *, Table *, lua_TObject *)
// Address: 0x8044E200, Size: 128
void luaH_set(lua_State * p0, Table * p1, lua_TObject * p2) {
}

// luaH_setnum(lua_State *, Table *, int)
// Address: 0x8044E280, Size: 100
void luaH_setnum(lua_State * p0, Table * p1, int p2) {
}

// luaT_init(lua_State *)
// Address: 0x8044E2E4, Size: 132
void luaT_init(lua_State * p0) {
}

// luaT_gettm(Table *, TMS, TString *)
// Address: 0x8044E368, Size: 88
void luaT_gettm(Table * p0, TMS p1, TString * p2) {
}

// luaT_gettmbyobj(lua_State *, lua_TObject *, TMS)
// Address: 0x8044E3C0, Size: 88
void luaT_gettmbyobj(lua_State * p0, lua_TObject * p1, TMS p2) {
}

// unexpectedEOZ(LoadState *)
// Address: 0x8044E418, Size: 52
void unexpectedEOZ(LoadState * p0) {
}

// ezgetc(LoadState *)
// Address: 0x8044E44C, Size: 124
void ezgetc(LoadState * p0) {
}

// ezread(LoadState *, void *, int)
// Address: 0x8044E4C8, Size: 64
void ezread(LoadState * p0, void * p1, int p2) {
}

// LoadBlock(LoadState *, void *, unsigned int)
// Address: 0x8044E508, Size: 112
void LoadBlock(LoadState * p0, void * p1, unsigned int p2) {
}

// LoadVector(LoadState *, void *, int, unsigned int)
// Address: 0x8044E578, Size: 156
void LoadVector(LoadState * p0, void * p1, int p2, unsigned int p3) {
}

// LoadInt(LoadState *)
// Address: 0x8044E614, Size: 92
void LoadInt(LoadState * p0) {
}

// LoadSize(LoadState *)
// Address: 0x8044E670, Size: 44
void LoadSize(LoadState * p0) {
}

// LoadNumber(LoadState *)
// Address: 0x8044E69C, Size: 44
void LoadNumber(LoadState * p0) {
}

// LoadString(LoadState *)
// Address: 0x8044E6C8, Size: 112
void LoadString(LoadState * p0) {
}

// LoadCode(LoadState *, Proto *)
// Address: 0x8044E738, Size: 104
void LoadCode(LoadState * p0, Proto * p1) {
}

// LoadLocals(LoadState *, Proto *)
// Address: 0x8044E7A0, Size: 164
void LoadLocals(LoadState * p0, Proto * p1) {
}

// LoadLines(LoadState *, Proto *)
// Address: 0x8044E844, Size: 104
void LoadLines(LoadState * p0, Proto * p1) {
}

// LoadUpvalues(LoadState *, Proto *)
// Address: 0x8044E8AC, Size: 164
void LoadUpvalues(LoadState * p0, Proto * p1) {
}

// LoadConstants(LoadState *, Proto *)
// Address: 0x8044E950, Size: 324
void LoadConstants(LoadState * p0, Proto * p1) {
}

// LoadFunction(LoadState *, TString *)
// Address: 0x8044EA94, Size: 244
void LoadFunction(LoadState * p0, TString * p1) {
}

// LoadSignature(LoadState *)
// Address: 0x8044EB88, Size: 124
void LoadSignature(LoadState * p0) {
}

// TestSize(LoadState *, int, char *)
// Address: 0x8044EC04, Size: 96
void TestSize(LoadState * p0, int p1, char * p2) {
}

// LoadHeader(LoadState *)
// Address: 0x8044EC64, Size: 416
void LoadHeader(LoadState * p0) {
}

// LoadChunk(LoadState *)
// Address: 0x8044EE04, Size: 56
void LoadChunk(LoadState * p0) {
}

// luaU_undump(lua_State *, Zio *, Mbuffer *)
// Address: 0x8044EE3C, Size: 108
void luaU_undump(lua_State * p0, Zio * p1, Mbuffer * p2) {
}

// luaU_endianness(void)
// Address: 0x8044EEA8, Size: 8
void luaU_endianness() {
}

// luaV_tonumber(lua_TObject *, lua_TObject *)
// Address: 0x8044EEB0, Size: 112
void luaV_tonumber(lua_TObject * p0, lua_TObject * p1) {
}

// luaV_tostring(lua_State *, lua_TObject *)
// Address: 0x8044EF20, Size: 128
void luaV_tostring(lua_State * p0, lua_TObject * p1) {
}

// traceexec(lua_State *)
// Address: 0x8044EFA0, Size: 308
void traceexec(lua_State * p0) {
}

// callTMres(lua_State *, lua_TObject *, lua_TObject *, lua_TObject *)
// Address: 0x8044F0D4, Size: 164
void callTMres(lua_State * p0, lua_TObject * p1, lua_TObject * p2, lua_TObject * p3) {
}

// callTM(lua_State *, lua_TObject *, lua_TObject *, lua_TObject *, lua_TObject *)
// Address: 0x8044F178, Size: 172
void callTM(lua_State * p0, lua_TObject * p1, lua_TObject * p2, lua_TObject * p3, lua_TObject * p4) {
}

// luaV_index(lua_State *, lua_TObject *, lua_TObject *, int)
// Address: 0x8044F224, Size: 172
void luaV_index(lua_State * p0, lua_TObject * p1, lua_TObject * p2, int p3) {
}

// luaV_getnotable(lua_State *, lua_TObject *, lua_TObject *, int)
// Address: 0x8044F2D0, Size: 156
void luaV_getnotable(lua_State * p0, lua_TObject * p1, lua_TObject * p2, int p3) {
}

// luaV_gettable(lua_State *, lua_TObject *, lua_TObject *, int)
// Address: 0x8044F36C, Size: 156
void luaV_gettable(lua_State * p0, lua_TObject * p1, lua_TObject * p2, int p3) {
}

// luaV_settable(lua_State *, lua_TObject *, lua_TObject *, lua_TObject *)
// Address: 0x8044F408, Size: 304
void luaV_settable(lua_State * p0, lua_TObject * p1, lua_TObject * p2, lua_TObject * p3) {
}

// call_binTM(lua_State *, lua_TObject *, lua_TObject *, lua_TObject *, TMS)
// Address: 0x8044F538, Size: 168
void call_binTM(lua_State * p0, lua_TObject * p1, lua_TObject * p2, lua_TObject * p3, TMS p4) {
}

// get_compTM(lua_State *, Table *, Table *, TMS)
// Address: 0x8044F5E0, Size: 224
void get_compTM(lua_State * p0, Table * p1, Table * p2, TMS p3) {
}

// call_orderTM(lua_State *, lua_TObject *, lua_TObject *, TMS)
// Address: 0x8044F6C0, Size: 188
void call_orderTM(lua_State * p0, lua_TObject * p1, lua_TObject * p2, TMS p3) {
}

// luaV_strcmp(TString *, TString *)
// Address: 0x8044F77C, Size: 144
void luaV_strcmp(TString * p0, TString * p1) {
}

// luaV_lessthan(lua_State *, lua_TObject *, lua_TObject *)
// Address: 0x8044F80C, Size: 180
void luaV_lessthan(lua_State * p0, lua_TObject * p1, lua_TObject * p2) {
}

// luaV_lessequal(lua_State *, lua_TObject *, lua_TObject *)
// Address: 0x8044F8C0, Size: 240
void luaV_lessequal(lua_State * p0, lua_TObject * p1, lua_TObject * p2) {
}

// luaV_equalval(lua_State *, lua_TObject *, lua_TObject *)
// Address: 0x8044F9B0, Size: 280
void luaV_equalval(lua_State * p0, lua_TObject * p1, lua_TObject * p2) {
}

// luaV_concat(lua_State *, int, int)
// Address: 0x8044FAC8, Size: 488
void luaV_concat(lua_State * p0, int p1, int p2) {
}

// Arith(lua_State *, lua_TObject *, lua_TObject *, lua_TObject *, TMS)
// Address: 0x8044FCB0, Size: 420
void Arith(lua_State * p0, lua_TObject * p1, lua_TObject * p2, lua_TObject * p3, TMS p4) {
}

// luaV_execute(lua_State *)
// Address: 0x8044FE54, Size: 4084
void luaV_execute(lua_State * p0) {
}

// luaZ_fill(Zio *)
// Address: 0x80450E48, Size: 116
void luaZ_fill(Zio * p0) {
}

// luaZ_lookahead(Zio *)
// Address: 0x80450EBC, Size: 104
void luaZ_lookahead(Zio * p0) {
}

// luaZ_init(Zio *, char *(*)(lua_State *, void *, unsigned int *), void *, char *)
// Address: 0x80450F24, Size: 28
void luaZ_init(Zio * p0, char *(*)(lua_State *, void *, unsigned int *) p1, void * p2, char * p3) {
}

// luaZ_read(Zio *, void *, unsigned int)
// Address: 0x80450F40, Size: 188
void luaZ_read(Zio * p0, void * p1, unsigned int p2) {
}

// luaZ_openspace(lua_State *, Mbuffer *, unsigned int)
// Address: 0x80450FFC, Size: 92
void luaZ_openspace(lua_State * p0, Mbuffer * p1, unsigned int p2) {
}

// luaL_argerror(lua_State *, int, char *)
// Address: 0x80451058, Size: 200
void luaL_argerror(lua_State * p0, int p1, char * p2) {
}

// luaL_typerror(lua_State *, int, char *)
// Address: 0x80451120, Size: 108
void luaL_typerror(lua_State * p0, int p1, char * p2) {
}

// tag_error(lua_State *, int, int)
// Address: 0x8045118C, Size: 68
void tag_error(lua_State * p0, int p1, int p2) {
}

// luaL_where(lua_State *, int)
// Address: 0x804511D0, Size: 136
void luaL_where(lua_State * p0, int p1) {
}

// luaL_error(lua_State *, char *,...)
// Address: 0x80451258, Size: 204
void luaL_error(lua_State * p0, char * p1, ... p2) {
}

// luaL_findstring(char *, char **)
// Address: 0x80451324, Size: 108
void luaL_findstring(char * p0, char ** p1) {
}

// luaL_newmetatable(lua_State *, char *)
// Address: 0x80451390, Size: 180
void luaL_newmetatable(lua_State * p0, char * p1) {
}

// luaL_getmetatable(lua_State *, char *)
// Address: 0x80451444, Size: 56
void luaL_getmetatable(lua_State * p0, char * p1) {
}

// luaL_checkudata(lua_State *, int, char *)
// Address: 0x8045147C, Size: 156
void luaL_checkudata(lua_State * p0, int p1, char * p2) {
}

// luaL_checkstack(lua_State *, int, char *)
// Address: 0x80451518, Size: 80
void luaL_checkstack(lua_State * p0, int p1, char * p2) {
}

// luaL_checktype(lua_State *, int, int)
// Address: 0x80451568, Size: 76
void luaL_checktype(lua_State * p0, int p1, int p2) {
}

// luaL_checkany(lua_State *, int)
// Address: 0x804515B4, Size: 76
void luaL_checkany(lua_State * p0, int p1) {
}

// luaL_checklstring(lua_State *, int, unsigned int *)
// Address: 0x80451600, Size: 104
void luaL_checklstring(lua_State * p0, int p1, unsigned int * p2) {
}

// luaL_optlstring(lua_State *, int, char *, unsigned int *)
// Address: 0x80451668, Size: 124
void luaL_optlstring(lua_State * p0, int p1, char * p2, unsigned int * p3) {
}

// luaL_checknumber(lua_State *, int)
// Address: 0x804516E4, Size: 96
void luaL_checknumber(lua_State * p0, int p1) {
}

// luaL_optnumber(lua_State *, int, int)
// Address: 0x80451744, Size: 76
void luaL_optnumber(lua_State * p0, int p1, int p2) {
}

// luaL_getmetafield(lua_State *, int, char *)
// Address: 0x80451790, Size: 140
void luaL_getmetafield(lua_State * p0, int p1, char * p2) {
}

// luaL_callmeta(lua_State *, int, char *)
// Address: 0x8045181C, Size: 132
void luaL_callmeta(lua_State * p0, int p1, char * p2) {
}

// luaL_openlib(lua_State *, char *, luaL_reg *, int)
// Address: 0x804518A0, Size: 292
void luaL_openlib(lua_State * p0, char * p1, luaL_reg * p2, int p3) {
}

// checkint(lua_State *, int)
// Address: 0x804519C4, Size: 100
void checkint(lua_State * p0, int p1) {
}

// getsizes(lua_State *)
// Address: 0x80451A28, Size: 196
void getsizes(lua_State * p0) {
}

// luaL_setn(lua_State *, int, int)
// Address: 0x80451AEC, Size: 224
void luaL_setn(lua_State * p0, int p1, int p2) {
}

// luaL_getn(lua_State *, int)
// Address: 0x80451BCC, Size: 268
void luaL_getn(lua_State * p0, int p1) {
}

// emptybuffer(luaL_Buffer *)
// Address: 0x80451CD8, Size: 100
void emptybuffer(luaL_Buffer * p0) {
}

// adjuststack(luaL_Buffer *)
// Address: 0x80451D3C, Size: 164
void adjuststack(luaL_Buffer * p0) {
}

// luaL_prepbuffer(luaL_Buffer *)
// Address: 0x80451DE0, Size: 64
void luaL_prepbuffer(luaL_Buffer * p0) {
}

// luaL_addlstring(luaL_Buffer *, char *, unsigned int)
// Address: 0x80451E20, Size: 116
void luaL_addlstring(luaL_Buffer * p0, char * p1, unsigned int p2) {
}

// luaL_addstring(luaL_Buffer *, char *)
// Address: 0x80451E94, Size: 68
void luaL_addstring(luaL_Buffer * p0, char * p1) {
}

// luaL_pushresult(luaL_Buffer *)
// Address: 0x80451ED8, Size: 64
void luaL_pushresult(luaL_Buffer * p0) {
}

// luaL_addvalue(luaL_Buffer *)
// Address: 0x80451F18, Size: 188
void luaL_addvalue(luaL_Buffer * p0) {
}

// luaL_buffinit(lua_State *, luaL_Buffer *)
// Address: 0x80451FD4, Size: 24
void luaL_buffinit(lua_State * p0, luaL_Buffer * p1) {
}

// luaL_ref(lua_State *, int)
// Address: 0x80451FEC, Size: 272
void luaL_ref(lua_State * p0, int p1) {
}

// luaL_unref(lua_State *, int, int)
// Address: 0x804520FC, Size: 144
void luaL_unref(lua_State * p0, int p1, int p2) {
}

// getF(lua_State *, void *, unsigned int *)
// Address: 0x8045218C, Size: 108
void getF(lua_State * p0, void * p1, unsigned int * p2) {
}

// errfile(lua_State *, int)
// Address: 0x804521F8, Size: 108
void errfile(lua_State * p0, int p1) {
}

// luaL_loadfile(lua_State *, char *)
// Address: 0x80452264, Size: 416
void luaL_loadfile(lua_State * p0, char * p1) {
}

// getS(lua_State *, void *, unsigned int *)
// Address: 0x80452404, Size: 40
void getS(lua_State * p0, void * p1, unsigned int * p2) {
}

// luaL_loadbuffer(lua_State *, char *, unsigned int, char *)
// Address: 0x8045242C, Size: 52
void luaL_loadbuffer(lua_State * p0, char * p1, unsigned int p2, char * p3) {
}

// callalert(lua_State *, int)
// Address: 0x80452460, Size: 180
void callalert(lua_State * p0, int p1) {
}

// aux_do(lua_State *, int)
// Address: 0x80452514, Size: 84
void aux_do(lua_State * p0, int p1) {
}

// lua_dofile(lua_State *, char *)
// Address: 0x80452568, Size: 56
void lua_dofile(lua_State * p0, char * p1) {
}

// lua_dobuffer(lua_State *, char *, unsigned int, char *)
// Address: 0x804525A0, Size: 56
void lua_dobuffer(lua_State * p0, char * p1, unsigned int p2, char * p3) {
}

// lua_dostring(lua_State *, char *)
// Address: 0x804525D8, Size: 72
void lua_dostring(lua_State * p0, char * p1) {
}

// luaB_print(lua_State *)
// Address: 0x80452620, Size: 264
void luaB_print(lua_State * p0) {
}

// luaB_tonumber(lua_State *)
// Address: 0x80452728, Size: 304
void luaB_tonumber(lua_State * p0) {
}

// luaB_error(lua_State *)
// Address: 0x80452858, Size: 156
void luaB_error(lua_State * p0) {
}

// luaB_getmetatable(lua_State *)
// Address: 0x804528F4, Size: 104
void luaB_getmetatable(lua_State * p0) {
}

// luaB_setmetatable(lua_State *)
// Address: 0x8045295C, Size: 180
void luaB_setmetatable(lua_State * p0) {
}

// getfunc(lua_State *)
// Address: 0x80452A10, Size: 224
void getfunc(lua_State * p0) {
}

// aux_getfenv(lua_State *)
// Address: 0x80452AF0, Size: 108
void aux_getfenv(lua_State * p0) {
}

// luaB_getfenv(lua_State *)
// Address: 0x80452B5C, Size: 76
void luaB_getfenv(lua_State * p0) {
}

// luaB_setfenv(lua_State *)
// Address: 0x80452BA8, Size: 224
void luaB_setfenv(lua_State * p0) {
}

// luaB_rawequal(lua_State *)
// Address: 0x80452C88, Size: 92
void luaB_rawequal(lua_State * p0) {
}

// luaB_rawget(lua_State *)
// Address: 0x80452CE4, Size: 80
void luaB_rawget(lua_State * p0) {
}

// luaB_rawset(lua_State *)
// Address: 0x80452D34, Size: 92
void luaB_rawset(lua_State * p0) {
}

// luaB_gcinfo(lua_State *)
// Address: 0x80452D90, Size: 80
void luaB_gcinfo(lua_State * p0) {
}

// luaB_collectgarbage(lua_State *)
// Address: 0x80452DE0, Size: 68
void luaB_collectgarbage(lua_State * p0) {
}

// luaB_type(lua_State *)
// Address: 0x80452E24, Size: 88
void luaB_type(lua_State * p0) {
}

// luaB_next(lua_State *)
// Address: 0x80452E7C, Size: 100
void luaB_next(lua_State * p0) {
}

// luaB_pairs(lua_State *)
// Address: 0x80452EE0, Size: 108
void luaB_pairs(lua_State * p0) {
}

// luaB_ipairs(lua_State *)
// Address: 0x80452F4C, Size: 220
void luaB_ipairs(lua_State * p0) {
}

// load_aux(lua_State *, int)
// Address: 0x80453028, Size: 76
void load_aux(lua_State * p0, int p1) {
}

// luaB_loadstring(lua_State *)
// Address: 0x80453074, Size: 108
void luaB_loadstring(lua_State * p0) {
}

// luaB_loadfile(lua_State *)
// Address: 0x804530E0, Size: 80
void luaB_loadfile(lua_State * p0) {
}

// luaB_dofile(lua_State *)
// Address: 0x80453130, Size: 128
void luaB_dofile(lua_State * p0) {
}

// luaB_assert(lua_State *)
// Address: 0x804531B0, Size: 136
void luaB_assert(lua_State * p0) {
}

// luaB_unpack(lua_State *)
// Address: 0x80453238, Size: 132
void luaB_unpack(lua_State * p0) {
}

// luaB_pcall(lua_State *)
// Address: 0x804532BC, Size: 112
void luaB_pcall(lua_State * p0) {
}

// luaB_xpcall(lua_State *)
// Address: 0x8045332C, Size: 128
void luaB_xpcall(lua_State * p0) {
}

// luaB_tostring(lua_State *)
// Address: 0x804533AC, Size: 432
void luaB_tostring(lua_State * p0) {
}

// luaB_newproxy(lua_State *)
// Address: 0x8045355C, Size: 272
void luaB_newproxy(lua_State * p0) {
}

// getpath(lua_State *)
// Address: 0x8045366C, Size: 136
void getpath(lua_State * p0) {
}

// pushnextpath(lua_State *, char *)
// Address: 0x804536F4, Size: 132
void pushnextpath(lua_State * p0, char * p1) {
}

// pushcomposename(lua_State *)
// Address: 0x80453778, Size: 160
void pushcomposename(lua_State * p0) {
}

// luaB_require(lua_State *)
// Address: 0x80453818, Size: 644
void luaB_require(lua_State * p0) {
}

// auxresume(lua_State *, lua_State *, int)
// Address: 0x80453A9C, Size: 220
void auxresume(lua_State * p0, lua_State * p1, int p2) {
}

// luaB_coresume(lua_State *)
// Address: 0x80453B78, Size: 172
void luaB_coresume(lua_State * p0) {
}

// luaB_auxwrap(lua_State *)
// Address: 0x80453C24, Size: 152
void luaB_auxwrap(lua_State * p0) {
}

// luaB_cocreate(lua_State *)
// Address: 0x80453CBC, Size: 140
void luaB_cocreate(lua_State * p0) {
}

// luaB_cowrap(lua_State *)
// Address: 0x80453D48, Size: 68
void luaB_cowrap(lua_State * p0) {
}

// luaB_yield(lua_State *)
// Address: 0x80453D8C, Size: 56
void luaB_yield(lua_State * p0) {
}

// luaB_costatus(lua_State *)
// Address: 0x80453DC4, Size: 196
void luaB_costatus(lua_State * p0) {
}

// base_open(lua_State *)
// Address: 0x80453E88, Size: 292
void base_open(lua_State * p0) {
}

// luaopen_base(lua_State *)
// Address: 0x80453FAC, Size: 124
void luaopen_base(lua_State * p0) {
}

// pushresult(lua_State *, int, char *)
// Address: 0x80454028, Size: 184
void pushresult(lua_State * p0, int p1, char * p2) {
}

// topfile(lua_State *, int)
// Address: 0x804540E0, Size: 88
void topfile(lua_State * p0, int p1) {
}

// io_type(lua_State *)
// Address: 0x80454138, Size: 136
void io_type(lua_State * p0) {
}

// tofile(lua_State *, int)
// Address: 0x804541C0, Size: 84
void tofile(lua_State * p0, int p1) {
}

// newfile(lua_State *)
// Address: 0x80454214, Size: 92
void newfile(lua_State * p0) {
}

// registerfile(lua_State *, __sFILE *, char *, char *)
// Address: 0x80454270, Size: 124
void registerfile(lua_State * p0, __sFILE * p1, char * p2, char * p3) {
}

// aux_close(lua_State *)
// Address: 0x804542EC, Size: 136
void aux_close(lua_State * p0) {
}

// io_close(lua_State *)
// Address: 0x80454374, Size: 128
void io_close(lua_State * p0) {
}

// io_gc(lua_State *)
// Address: 0x804543F4, Size: 72
void io_gc(lua_State * p0) {
}

// io_tostring(lua_State *)
// Address: 0x8045443C, Size: 164
void io_tostring(lua_State * p0) {
}

// io_open(lua_State *)
// Address: 0x804544E0, Size: 140
void io_open(lua_State * p0) {
}

// io_popen(lua_State *)
// Address: 0x8045456C, Size: 48
void io_popen(lua_State * p0) {
}

// io_tmpfile(lua_State *)
// Address: 0x8045459C, Size: 88
void io_tmpfile(lua_State * p0) {
}

// getiofile(lua_State *, char *)
// Address: 0x804545F4, Size: 68
void getiofile(lua_State * p0, char * p1) {
}

// g_iofile(lua_State *, char *, char *)
// Address: 0x80454638, Size: 272
void g_iofile(lua_State * p0, char * p1, char * p2) {
}

// io_input(lua_State *)
// Address: 0x80454748, Size: 48
void io_input(lua_State * p0) {
}

// io_output(lua_State *)
// Address: 0x80454778, Size: 48
void io_output(lua_State * p0) {
}

// aux_lines(lua_State *, int, int)
// Address: 0x804547A8, Size: 120
void aux_lines(lua_State * p0, int p1, int p2) {
}

// f_lines(lua_State *)
// Address: 0x80454820, Size: 68
void f_lines(lua_State * p0) {
}

// io_lines(lua_State *)
// Address: 0x80454864, Size: 212
void io_lines(lua_State * p0) {
}

// read_number(lua_State *, __sFILE *)
// Address: 0x80454938, Size: 96
void read_number(lua_State * p0, __sFILE * p1) {
}

// test_eof(lua_State *, __sFILE *)
// Address: 0x80454998, Size: 136
void test_eof(lua_State * p0, __sFILE * p1) {
}

// read_line(lua_State *, __sFILE *)
// Address: 0x80454A20, Size: 192
void read_line(lua_State * p0, __sFILE * p1) {
}

// read_chars(lua_State *, __sFILE *, unsigned int)
// Address: 0x80454AE0, Size: 188
void read_chars(lua_State * p0, __sFILE * p1, unsigned int p2) {
}

// g_read(lua_State *, __sFILE *, int)
// Address: 0x80454B9C, Size: 460
void g_read(lua_State * p0, __sFILE * p1, int p2) {
}

// io_read(lua_State *)
// Address: 0x80454D68, Size: 68
void io_read(lua_State * p0) {
}

// f_read(lua_State *)
// Address: 0x80454DAC, Size: 64
void f_read(lua_State * p0) {
}

// io_readline(lua_State *)
// Address: 0x80454DEC, Size: 160
void io_readline(lua_State * p0) {
}

// g_write(lua_State *, __sFILE *, int)
// Address: 0x80454E8C, Size: 248
void g_write(lua_State * p0, __sFILE * p1, int p2) {
}

// io_write(lua_State *)
// Address: 0x80454F84, Size: 68
void io_write(lua_State * p0) {
}

// f_write(lua_State *)
// Address: 0x80454FC8, Size: 64
void f_write(lua_State * p0) {
}

// f_seek(lua_State *)
// Address: 0x80455008, Size: 220
void f_seek(lua_State * p0) {
}

// io_flush(lua_State *)
// Address: 0x804550E4, Size: 76
void io_flush(lua_State * p0) {
}

// f_flush(lua_State *)
// Address: 0x80455130, Size: 72
void f_flush(lua_State * p0) {
}

// createmeta(lua_State *)
// Address: 0x80455178, Size: 120
void createmeta(lua_State * p0) {
}

// io_execute(lua_State *)
// Address: 0x804551F0, Size: 72
void io_execute(lua_State * p0) {
}

// io_remove(lua_State *)
// Address: 0x80455238, Size: 80
void io_remove(lua_State * p0) {
}

// io_rename(lua_State *)
// Address: 0x80455288, Size: 104
void io_rename(lua_State * p0) {
}

// io_tmpname(lua_State *)
// Address: 0x804552F0, Size: 48
void io_tmpname(lua_State * p0) {
}

// io_getenv(lua_State *)
// Address: 0x80455320, Size: 72
void io_getenv(lua_State * p0) {
}

// io_clock(lua_State *)
// Address: 0x80455368, Size: 84
void io_clock(lua_State * p0) {
}

// setfield(lua_State *, char *, int)
// Address: 0x804553BC, Size: 72
void setfield(lua_State * p0, char * p1, int p2) {
}

// setboolfield(lua_State *, char *, int)
// Address: 0x80455404, Size: 72
void setboolfield(lua_State * p0, char * p1, int p2) {
}

// getboolfield(lua_State *, char *)
// Address: 0x8045544C, Size: 88
void getboolfield(lua_State * p0, char * p1) {
}

// getfield(lua_State *, char *, int)
// Address: 0x804554A4, Size: 156
void getfield(lua_State * p0, char * p1, int p2) {
}

// io_date(lua_State *)
// Address: 0x80455540, Size: 464
void io_date(lua_State * p0) {
}

// io_time(lua_State *)
// Address: 0x80455710, Size: 324
void io_time(lua_State * p0) {
}

// io_difftime(lua_State *)
// Address: 0x80455854, Size: 104
void io_difftime(lua_State * p0) {
}

// io_setloc(lua_State *)
// Address: 0x804558BC, Size: 208
void io_setloc(lua_State * p0) {
}

// io_exit(lua_State *)
// Address: 0x8045598C, Size: 28
void io_exit(lua_State * p0) {
}

// luaopen_io(lua_State *)
// Address: 0x804559A8, Size: 208
void luaopen_io(lua_State * p0) {
}

// str_len(lua_State *)
// Address: 0x80455A78, Size: 68
void str_len(lua_State * p0) {
}

// posrelat(long, unsigned int)
// Address: 0x80455ABC, Size: 20
void posrelat(long p0, unsigned int p1) {
}

// str_sub(lua_State *)
// Address: 0x80455AD0, Size: 192
void str_sub(lua_State * p0) {
}

// str_lower(lua_State *)
// Address: 0x80455B90, Size: 180
void str_lower(lua_State * p0) {
}

// str_upper(lua_State *)
// Address: 0x80455C44, Size: 180
void str_upper(lua_State * p0) {
}

// str_rep(lua_State *)
// Address: 0x80455CF8, Size: 144
void str_rep(lua_State * p0) {
}

// str_byte(lua_State *)
// Address: 0x80455D88, Size: 128
void str_byte(lua_State * p0) {
}

// str_char(lua_State *)
// Address: 0x80455E08, Size: 184
void str_char(lua_State * p0) {
}

// writer(lua_State *, void *, unsigned int, void *)
// Address: 0x80455EC0, Size: 40
void writer(lua_State * p0, void * p1, unsigned int p2, void * p3) {
}

// str_dump(lua_State *)
// Address: 0x80455EE8, Size: 124
void str_dump(lua_State * p0) {
}

// check_capture(MatchState *, int)
// Address: 0x80455F64, Size: 92
void check_capture(MatchState * p0, int p1) {
}

// capture_to_close(MatchState *)
// Address: 0x80455FC0, Size: 100
void capture_to_close(MatchState * p0) {
}

// luaI_classend(MatchState *, char *)
// Address: 0x80456024, Size: 216
void luaI_classend(MatchState * p0, char * p1) {
}

// match_class(int, int)
// Address: 0x804560FC, Size: 304
void match_class(int p0, int p1) {
}

// matchbracketclass(int, char *, char *)
// Address: 0x8045622C, Size: 208
void matchbracketclass(int p0, char * p1, char * p2) {
}

// luaI_singlematch(int, char *, char *)
// Address: 0x804562FC, Size: 136
void luaI_singlematch(int p0, char * p1, char * p2) {
}

// matchbalance(MatchState *, char *, char *)
// Address: 0x80456384, Size: 200
void matchbalance(MatchState * p0, char * p1, char * p2) {
}

// max_expand(MatchState *, char *, char *, char *)
// Address: 0x8045644C, Size: 148
void max_expand(MatchState * p0, char * p1, char * p2, char * p3) {
}

// min_expand(MatchState *, char *, char *, char *)
// Address: 0x804564E0, Size: 124
void min_expand(MatchState * p0, char * p1, char * p2, char * p3) {
}

// start_capture(MatchState *, char *, char *, int)
// Address: 0x8045655C, Size: 148
void start_capture(MatchState * p0, char * p1, char * p2, int p3) {
}

// end_capture(MatchState *, char *, char *)
// Address: 0x804565F0, Size: 108
void end_capture(MatchState * p0, char * p1, char * p2) {
}

// match_capture(MatchState *, char *, int)
// Address: 0x8045665C, Size: 120
void match_capture(MatchState * p0, char * p1, int p2) {
}

// match(MatchState *, char *, char *)
// Address: 0x804566D4, Size: 728
void match(MatchState * p0, char * p1, char * p2) {
}

// lmemfind(char *, unsigned int, char *, unsigned int)
// Address: 0x804569AC, Size: 168
void lmemfind(char * p0, unsigned int p1, char * p2, unsigned int p3) {
}

// push_onecapture(MatchState *, int)
// Address: 0x80456A54, Size: 140
void push_onecapture(MatchState * p0, int p1) {
}

// push_captures(MatchState *, char *, char *)
// Address: 0x80456AE0, Size: 160
void push_captures(MatchState * p0, char * p1, char * p2) {
}

// str_find(lua_State *)
// Address: 0x80456B80, Size: 444
void str_find(lua_State * p0) {
}

// gfind_aux(lua_State *)
// Address: 0x80456D3C, Size: 236
void gfind_aux(lua_State * p0) {
}

// gfind(lua_State *)
// Address: 0x80456E28, Size: 116
void gfind(lua_State * p0) {
}

// add_s(MatchState *, luaL_Buffer *, char *, char *)
// Address: 0x80456E9C, Size: 348
void add_s(MatchState * p0, luaL_Buffer * p1, char * p2, char * p3) {
}

// str_gsub(lua_State *)
// Address: 0x80456FF8, Size: 460
void str_gsub(lua_State * p0) {
}

// luaI_addquoted(lua_State *, luaL_Buffer *, int)
// Address: 0x804571C4, Size: 344
void luaI_addquoted(lua_State * p0, luaL_Buffer * p1, int p2) {
}

// scanformat(lua_State *, char *, char *, int *)
// Address: 0x8045731C, Size: 320
void scanformat(lua_State * p0, char * p1, char * p2, int * p3) {
}

// str_format(lua_State *)
// Address: 0x8045745C, Size: 624
void str_format(lua_State * p0) {
}

// luaopen_string(lua_State *)
// Address: 0x804576CC, Size: 56
void luaopen_string(lua_State * p0) {
}

// luaB_foreachi(lua_State *)
// Address: 0x80457704, Size: 204
void luaB_foreachi(lua_State * p0) {
}

// luaB_foreach(lua_State *)
// Address: 0x804577D0, Size: 192
void luaB_foreach(lua_State * p0) {
}

// luaB_getn(lua_State *)
// Address: 0x80457890, Size: 80
void luaB_getn(lua_State * p0) {
}

// luaB_setn(lua_State *)
// Address: 0x804578E0, Size: 84
void luaB_setn(lua_State * p0) {
}

// luaB_tinsert(lua_State *)
// Address: 0x80457934, Size: 232
void luaB_tinsert(lua_State * p0) {
}

// luaB_tremove(lua_State *)
// Address: 0x80457A1C, Size: 216
void luaB_tremove(lua_State * p0) {
}

// str_concat(lua_State *)
// Address: 0x80457AF4, Size: 276
void str_concat(lua_State * p0) {
}

// set2(lua_State *, int, int)
// Address: 0x80457C08, Size: 72
void set2(lua_State * p0, int p1, int p2) {
}

// sort_comp(lua_State *, int, int)
// Address: 0x80457C50, Size: 168
void sort_comp(lua_State * p0, int p1, int p2) {
}

// auxsort(lua_State *, int, int)
// Address: 0x80457CF8, Size: 756
void auxsort(lua_State * p0, int p1, int p2) {
}

// luaB_sort(lua_State *)
// Address: 0x80457FEC, Size: 156
void luaB_sort(lua_State * p0) {
}

// luaopen_table(lua_State *)
// Address: 0x80458088, Size: 56
void luaopen_table(lua_State * p0) {
}

// ea_us_strtod
// Address: 0x804580C0, Size: 624
void ea_us_strtod() {
}

// ea_tmpfile
// Address: 0x80458330, Size: 48
void ea_tmpfile() {
}

// luaK_nil(FuncState *, int, int)
// Address: 0x80458360, Size: 164
void luaK_nil(FuncState * p0, int p1, int p2) {
}

// luaK_jump(FuncState *)
// Address: 0x80458404, Size: 96
void luaK_jump(FuncState * p0) {
}

// luaK_condjump(FuncState *, OpCode, int, int, int)
// Address: 0x80458464, Size: 52
void luaK_condjump(FuncState * p0, OpCode p1, int p2, int p3, int p4) {
}

// luaK_fixjump(FuncState *, int, int)
// Address: 0x80458498, Size: 128
void luaK_fixjump(FuncState * p0, int p1, int p2) {
}

// luaK_getlabel(FuncState *)
// Address: 0x80458518, Size: 16
void luaK_getlabel(FuncState * p0) {
}

// luaK_getjump(FuncState *, int)
// Address: 0x80458528, Size: 56
void luaK_getjump(FuncState * p0, int p1) {
}

// getjumpcontrol(FuncState *, int)
// Address: 0x80458560, Size: 60
void getjumpcontrol(FuncState * p0, int p1) {
}

// need_value(FuncState *, int, int)
// Address: 0x8045859C, Size: 132
void need_value(FuncState * p0, int p1, int p2) {
}

// patchtestreg(unsigned long *, int)
// Address: 0x80458620, Size: 40
void patchtestreg(unsigned long * p0, int p1) {
}

// luaK_patchlistaux(FuncState *, int, int, int, int, int, int)
// Address: 0x80458648, Size: 208
void luaK_patchlistaux(FuncState * p0, int p1, int p2, int p3, int p4, int p5, int p6) {
}

// luaK_dischargejpc(FuncState *)
// Address: 0x80458718, Size: 76
void luaK_dischargejpc(FuncState * p0) {
}

// luaK_patchlist(FuncState *, int, int)
// Address: 0x80458764, Size: 68
void luaK_patchlist(FuncState * p0, int p1, int p2) {
}

// luaK_patchtohere(FuncState *, int)
// Address: 0x804587A8, Size: 64
void luaK_patchtohere(FuncState * p0, int p1) {
}

// luaK_concat(FuncState *, int *, int)
// Address: 0x804587E8, Size: 124
void luaK_concat(FuncState * p0, int * p1, int p2) {
}

// luaK_checkstack(FuncState *, int)
// Address: 0x80458864, Size: 96
void luaK_checkstack(FuncState * p0, int p1) {
}

// luaK_reserveregs(FuncState *, int)
// Address: 0x804588C4, Size: 60
void luaK_reserveregs(FuncState * p0, int p1) {
}

// freereg(FuncState *, int)
// Address: 0x80458900, Size: 36
void freereg(FuncState * p0, int p1) {
}

// freeexp(FuncState *, expdesc *)
// Address: 0x80458924, Size: 48
void freeexp(FuncState * p0, expdesc * p1) {
}

// addk(FuncState *, lua_TObject *, lua_TObject *)
// Address: 0x80458954, Size: 220
void addk(FuncState * p0, lua_TObject * p1, lua_TObject * p2) {
}

// luaK_stringK(FuncState *, TString *)
// Address: 0x80458A30, Size: 52
void luaK_stringK(FuncState * p0, TString * p1) {
}

// luaK_numberK(FuncState *, int)
// Address: 0x80458A64, Size: 52
void luaK_numberK(FuncState * p0, int p1) {
}

// nil_constant(FuncState *)
// Address: 0x80458A98, Size: 64
void nil_constant(FuncState * p0) {
}

// luaK_setcallreturns(FuncState *, expdesc *, int)
// Address: 0x80458AD8, Size: 96
void luaK_setcallreturns(FuncState * p0, expdesc * p1, int p2) {
}

// luaK_dischargevars(FuncState *, expdesc *)
// Address: 0x80458B38, Size: 240
void luaK_dischargevars(FuncState * p0, expdesc * p1) {
}

// code_label(FuncState *, int, int, int)
// Address: 0x80458C28, Size: 80
void code_label(FuncState * p0, int p1, int p2, int p3) {
}

// discharge2reg(FuncState *, expdesc *, int)
// Address: 0x80458C78, Size: 280
void discharge2reg(FuncState * p0, expdesc * p1, int p2) {
}

// discharge2anyreg(FuncState *, expdesc *)
// Address: 0x80458D90, Size: 84
void discharge2anyreg(FuncState * p0, expdesc * p1) {
}

// luaK_exp2reg(FuncState *, expdesc *, int)
// Address: 0x80458DE4, Size: 336
void luaK_exp2reg(FuncState * p0, expdesc * p1, int p2) {
}

// luaK_exp2nextreg(FuncState *, expdesc *)
// Address: 0x80458F34, Size: 92
void luaK_exp2nextreg(FuncState * p0, expdesc * p1) {
}

// luaK_exp2anyreg(FuncState *, expdesc *)
// Address: 0x80458F90, Size: 124
void luaK_exp2anyreg(FuncState * p0, expdesc * p1) {
}

// luaK_exp2val(FuncState *, expdesc *)
// Address: 0x8045900C, Size: 56
void luaK_exp2val(FuncState * p0, expdesc * p1) {
}

// luaK_exp2RK(FuncState *, expdesc *)
// Address: 0x80459044, Size: 152
void luaK_exp2RK(FuncState * p0, expdesc * p1) {
}

// luaK_storevar(FuncState *, expdesc *, expdesc *)
// Address: 0x804590DC, Size: 252
void luaK_storevar(FuncState * p0, expdesc * p1, expdesc * p2) {
}

// luaK_self(FuncState *, expdesc *, expdesc *)
// Address: 0x804591D8, Size: 144
void luaK_self(FuncState * p0, expdesc * p1, expdesc * p2) {
}

// invertjump(FuncState *, expdesc *)
// Address: 0x80459268, Size: 60
void invertjump(FuncState * p0, expdesc * p1) {
}

// jumponcond(FuncState *, expdesc *, int)
// Address: 0x804592A4, Size: 176
void jumponcond(FuncState * p0, expdesc * p1, int p2) {
}

// luaK_goiftrue(FuncState *, expdesc *)
// Address: 0x80459354, Size: 168
void luaK_goiftrue(FuncState * p0, expdesc * p1) {
}

// luaK_goiffalse(FuncState *, expdesc *)
// Address: 0x804593FC, Size: 156
void luaK_goiffalse(FuncState * p0, expdesc * p1) {
}

// codenot(FuncState *, expdesc *)
// Address: 0x80459498, Size: 220
void codenot(FuncState * p0, expdesc * p1) {
}

// luaK_indexed(FuncState *, expdesc *, expdesc *)
// Address: 0x80459574, Size: 60
void luaK_indexed(FuncState * p0, expdesc * p1, expdesc * p2) {
}

// luaK_prefix(FuncState *, UnOpr, expdesc *)
// Address: 0x804595B0, Size: 204
void luaK_prefix(FuncState * p0, UnOpr p1, expdesc * p2) {
}

// luaK_infix(FuncState *, BinOpr, expdesc *)
// Address: 0x8045967C, Size: 180
void luaK_infix(FuncState * p0, BinOpr p1, expdesc * p2) {
}

// codebinop(FuncState *, expdesc *, BinOpr, int, int)
// Address: 0x80459730, Size: 148
void codebinop(FuncState * p0, expdesc * p1, BinOpr p2, int p3, int p4) {
}

// luaK_posfix(FuncState *, BinOpr, expdesc *, expdesc *)
// Address: 0x804597C4, Size: 500
void luaK_posfix(FuncState * p0, BinOpr p1, expdesc * p2, expdesc * p3) {
}

// luaK_fixline(FuncState *, int)
// Address: 0x804599B8, Size: 28
void luaK_fixline(FuncState * p0, int p1) {
}

// luaK_code(FuncState *, unsigned long, int)
// Address: 0x804599D4, Size: 224
void luaK_code(FuncState * p0, unsigned long p1, int p2) {
}

// luaK_codeABC(FuncState *, OpCode, int, int, int)
// Address: 0x80459AB4, Size: 64
void luaK_codeABC(FuncState * p0, OpCode p1, int p2, int p3, int p4) {
}

// luaK_codeABx(FuncState *, OpCode, int, unsigned int)
// Address: 0x80459AF4, Size: 56
void luaK_codeABx(FuncState * p0, OpCode p1, int p2, unsigned int p3) {
}

// luaX_init(lua_State *)
// Address: 0x80459B2C, Size: 116
void luaX_init(lua_State * p0) {
}

// luaX_checklimit(LexState *, int, int, char *)
// Address: 0x80459BA0, Size: 92
void luaX_checklimit(LexState * p0, int p1, int p2, char * p3) {
}

// luaX_errorline(LexState *, char *, char *, int)
// Address: 0x80459BFC, Size: 120
void luaX_errorline(LexState * p0, char * p1, char * p2, int p3) {
}

// luaX_error(LexState *, char *, char *)
// Address: 0x80459C74, Size: 36
void luaX_error(LexState * p0, char * p1, char * p2) {
}

// luaX_syntaxerror(LexState *, char *)
// Address: 0x80459C98, Size: 128
void luaX_syntaxerror(LexState * p0, char * p1) {
}

// luaX_token2str(LexState *, int)
// Address: 0x80459D18, Size: 84
void luaX_token2str(LexState * p0, int p1) {
}

// luaX_lexerror(LexState *, char *, int)
// Address: 0x80459D6C, Size: 100
void luaX_lexerror(LexState * p0, char * p1, int p2) {
}

// inclinenumber(LexState *)
// Address: 0x80459DD0, Size: 144
void inclinenumber(LexState * p0) {
}

// luaX_setinput(lua_State *, LexState *, Zio *, TString *)
// Address: 0x80459E60, Size: 228
void luaX_setinput(lua_State * p0, LexState * p1, Zio * p2, TString * p3) {
}

// readname(LexState *)
// Address: 0x80459F44, Size: 232
void readname(LexState * p0) {
}

// read_numeral(LexState *, int, SemInfo *)
// Address: 0x8045A02C, Size: 1068
void read_numeral(LexState * p0, int p1, SemInfo * p2) {
}

// read_long_string(LexState *, SemInfo *)
// Address: 0x8045A458, Size: 872
void read_long_string(LexState * p0, SemInfo * p1) {
}

// read_string(LexState *, int, SemInfo *)
// Address: 0x8045A7C0, Size: 1072
void read_string(LexState * p0, int p1, SemInfo * p2) {
}

// luaX_lex(LexState *, SemInfo *)
// Address: 0x8045ABF0, Size: 1828
void luaX_lex(LexState * p0, SemInfo * p1) {
}

// SplitPath(char *, char *, char *, char *, char *)
// Address: 0x8045C514, Size: 484
void SplitPath(char * p0, char * p1, char * p2, char * p3, char * p4) {
}

// DupString(char *)
// Address: 0x8045C6F8, Size: 108
void DupString(char * p0) {
}

// MatrixInvert(float **, int)
// Address: 0x80462C64, Size: 732
void MatrixInvert(float ** p0, int p1) {
}

// Rndf(void)
// Address: 0x80462F40, Size: 84
void Rndf() {
}

// SignedRndf(void)
// Address: 0x80462F94, Size: 48
void SignedRndf() {
}

// RootHeap(void)
// Address: 0x804678FC, Size: 112
void RootHeap() {
}

// ResourceHeap(void)
// Address: 0x80467A38, Size: 116
void ResourceHeap() {
}

// VMHeap(void)
// Address: 0x80467AD8, Size: 116
void VMHeap() {
}

// CUIHeap(void)
// Address: 0x80467C14, Size: 116
void CUIHeap() {
}

// AudioHeap(void)
// Address: 0x80467CB4, Size: 132
void AudioHeap() {
}

// ShaderHeap(void)
// Address: 0x80467D64, Size: 132
void ShaderHeap() {
}

// TextureHeap(void)
// Address: 0x80467E14, Size: 132
void TextureHeap() {
}

// AnimationHeap(void)
// Address: 0x80467EC4, Size: 132
void AnimationHeap() {
}

// ModelHeap(void)
// Address: 0x80467F74, Size: 132
void ModelHeap() {
}

// FlashesHeap(void)
// Address: 0x80468024, Size: 116
void FlashesHeap() {
}

// DefaultAlloc(unsigned int)
// Address: 0x80468E38, Size: 80
void DefaultAlloc(unsigned int p0) {
}

// MemStartSizePrint(void)
// Address: 0x804697AC, Size: 72
void MemStartSizePrint() {
}

// MemStartDumpPrint(void)
// Address: 0x804697F4, Size: 72
void MemStartDumpPrint() {
}

// MemDumpSizes(char *, int)
// Address: 0x8046983C, Size: 232
void MemDumpSizes(char * p0, int p1) {
}

// MemDumpRange(char *, int, int, int)
// Address: 0x80469924, Size: 368
void MemDumpRange(char * p0, int p1, int p2, int p3) {
}

// MemValidateHeap(int)
// Address: 0x8046A010, Size: 392
void MemValidateHeap(int p0) {
}

// efopen
// Address: 0x80472974, Size: 76
void efopen() {
}

// efseek
// Address: 0x80472A6C, Size: 104
void efseek() {
}

// efgets
// Address: 0x80472B3C, Size: 168
void efgets() {
}

// SnprintfLocal(char *, unsigned int, char *,...)
// Address: 0x80475794, Size: 144
void SnprintfLocal(char * p0, unsigned int p1, char * p2, ... p3) {
}

// local_fcvt
// Address: 0x80479C24, Size: 880
void local_fcvt() {
}

// ReadFormat8(char *, FormatData *, __va_list_tag **)
// Address: 0x8047A008, Size: 1608
void ReadFormat8(char * p0, FormatData * p1, __va_list_tag ** p2) {
}

// WriteLong(FormatData &, long, char *)
// Address: 0x8047A650, Size: 596
void WriteLong(FormatData & p0, long p1, char * p2) {
}

// WriteLongLong(FormatData &, long long, char *)
// Address: 0x8047A8A4, Size: 728
void WriteLongLong(FormatData & p0, long long p1, char * p2) {
}

// WriteDouble(FormatData &, double, char *)
// Address: 0x8047AB7C, Size: 564
void WriteDouble(FormatData & p0, double p1, char * p2) {
}

// VprintfCore8(bool (*)(char *, unsigned int, void *), void *, char *, __va_list_tag *)
// Address: 0x8047ADB0, Size: 2760
void VprintfCore8(bool (*)(char *, unsigned int, void *) p0, void * p1, char * p2, __va_list_tag * p3) {
}

// Printf(char *,...)
// Address: 0x8047B8F4, Size: 204
void Printf(char * p0, ... p1) {
}

// Sprintf(char *, char *,...)
// Address: 0x8047B9C0, Size: 156
void Sprintf(char * p0, char * p1, ... p2) {
}

// Snprintf(char *, unsigned int, char *,...)
// Address: 0x8047BA5C, Size: 144
void Snprintf(char * p0, unsigned int p1, char * p2, ... p3) {
}

// Vsprintf(char *, char *, __va_list_tag *)
// Address: 0x8047BAEC, Size: 52
void Vsprintf(char * p0, char * p1, __va_list_tag * p2) {
}

// IsSpace(char)
// Address: 0x8047BB20, Size: 56
void IsSpace(char p0) {
}

// local_atof(char *, char **)
// Address: 0x8047BB58, Size: 364
void local_atof(char * p0, char ** p1) {
}

// local_atoi(char *, char **)
// Address: 0x8047BCC4, Size: 160
void local_atoi(char * p0, char ** p1) {
}

// AtoF(char *)
// Address: 0x8047BD64, Size: 36
void AtoF(char * p0) {
}

// AtoI(char *)
// Address: 0x8047BD88, Size: 36
void AtoI(char * p0) {
}

// Sscanf(char *, char *,...)
// Address: 0x8047BDAC, Size: 1020
void Sscanf(char * p0, char * p1, ... p2) {
}

// MaxisDbgTraceBinary(void *, unsigned int)
// Address: 0x8047C310, Size: 240
void MaxisDbgTraceBinary(void * p0, unsigned int p1) {
}

// DbgLogTraceClose(void)
// Address: 0x8047C450, Size: 52
void DbgLogTraceClose() {
}

// E_SendTestEvent(char *,...)
// Address: 0x80481C00, Size: 188
void E_SendTestEvent(char * p0, ... p1) {
}

// SetSendTestEventFunc(void (*)(char *))
// Address: 0x80481CBC, Size: 8
void SetSendTestEventFunc(void (*)(char *) p0) {
}

// E_Log(char *,...)
// Address: 0x80481CC4, Size: 188
void E_Log(char * p0, ... p1) {
}

// SetLogFunc(void (*)(char *))
// Address: 0x80481D80, Size: 8
void SetLogFunc(void (*)(char *) p0) {
}

// E_LogError(char *,...)
// Address: 0x80481D88, Size: 180
void E_LogError(char * p0, ... p1) {
}

// E_IsLogDebugEnabled(void)
// Address: 0x80481E3C, Size: 8
void E_IsLogDebugEnabled() {
}

// E_LogDebugEnable(bool)
// Address: 0x80481E44, Size: 8
void E_LogDebugEnable(bool p0) {
}

// E_LogDebug(char *,...)
// Address: 0x80481E4C, Size: 192
void E_LogDebug(char * p0, ... p1) {
}

// E_LogMetric_L1(char *,...)
// Address: 0x80481F0C, Size: 192
void E_LogMetric_L1(char * p0, ... p1) {
}

// E_LogMetric_L2(char *,...)
// Address: 0x80481FCC, Size: 192
void E_LogMetric_L2(char * p0, ... p1) {
}

// E_LogMetric_L3(char *,...)
// Address: 0x8048208C, Size: 192
void E_LogMetric_L3(char * p0, ... p1) {
}

// SetLogMetricFunc(void (*)(char *, AutomationNS::ScriptLog::ReportingLevel))
// Address: 0x8048214C, Size: 8
void SetLogMetricFunc(void (*)(char *, AutomationNS::ScriptLog::ReportingLevel) p0) {
}

// MainInit
// Address: 0x80482154, Size: 104
void MainInit() {
}

// StartMainThread
// Address: 0x804821BC, Size: 108
void StartMainThread() {
}

// main
// Address: 0x80482228, Size: 68
void main() {
}

// setClipPlaneOffsets(unsigned char *, unsigned char *, EVec3 &)
// Address: 0x8048300C, Size: 92
void setClipPlaneOffsets(unsigned char * p0, unsigned char * p1, EVec3 & p2) {
}

// locprintf(char *,...)
// Address: 0x80490C3C, Size: 76
void locprintf(char * p0, ... p1) {
}

// FloatToFixed1_0_7(float)
// Address: 0x804A2654, Size: 84
void FloatToFixed1_0_7(float p0) {
}

// Fixed1_0_7ToFloat(signed char)
// Address: 0x804A26A8, Size: 100
void Fixed1_0_7ToFloat(signed char p0) {
}

// VertexDataInitialization(unsigned int, unsigned int, unsigned int, bool)
// Address: 0x804A270C, Size: 4
void VertexDataInitialization(unsigned int p0, unsigned int p1, unsigned int p2, bool p3) {
}

// VertexDataDeinitialization(void)
// Address: 0x804A2710, Size: 4
void VertexDataDeinitialization() {
}

// PSysLibOpen
// Address: 0x804A93FC, Size: 192
void PSysLibOpen() {
}

// PSysLibClose
// Address: 0x804A94BC, Size: 72
void PSysLibClose() {
}

// ParticleBirthSphere(pemitter *, PVector4 *, PVector4 *)
// Address: 0x804A9504, Size: 404
void ParticleBirthSphere(pemitter * p0, PVector4 * p1, PVector4 * p2) {
}

// ParticleBirthCone(pemitter *, PVector4 *, PVector4 *)
// Address: 0x804A9698, Size: 512
void ParticleBirthCone(pemitter * p0, PVector4 * p1, PVector4 * p2) {
}

// ParticleBirthCylinder(pemitter *, PVector4 *, PVector4 *)
// Address: 0x804A9898, Size: 344
void ParticleBirthCylinder(pemitter * p0, PVector4 * p1, PVector4 * p2) {
}

// PCalcTabDataSet(particle *, pemitterinfo *, float)
// Address: 0x804A99F0, Size: 168
void PCalcTabDataSet(particle * p0, pemitterinfo * p1, float p2) {
}

// ParticleCreate(pemitter *, int)
// Address: 0x804A9A98, Size: 1688
void ParticleCreate(pemitter * p0, int p1) {
}

// ParticleProcess(pemitter *, float)
// Address: 0x804AA130, Size: 1496
void ParticleProcess(pemitter * p0, float p1) {
}

// ParticleProcessType0(pemitter *, float)
// Address: 0x804AA708, Size: 1664
void ParticleProcessType0(pemitter * p0, float p1) {
}

// ParticleProcessType1(pemitter *, float)
// Address: 0x804AAD88, Size: 1068
void ParticleProcessType1(pemitter * p0, float p1) {
}

// ParticleProcessType2(pemitter *, float)
// Address: 0x804AB1B4, Size: 1084
void ParticleProcessType2(pemitter * p0, float p1) {
}

// PEmitterProcess(pemitter *, float)
// Address: 0x804AB610, Size: 480
void PEmitterProcess(pemitter * p0, float p1) {
}

// PSystemProcess
// Address: 0x804AB7F0, Size: 312
void PSystemProcess() {
}

// PEmitterSubmitParticles
// Address: 0x804AB928, Size: 332
void PEmitterSubmitParticles() {
}

// PSystemClean
// Address: 0x804ABA74, Size: 176
void PSystemClean() {
}

// PSystemIsEmpty
// Address: 0x804ABB24, Size: 68
void PSystemIsEmpty() {
}

// PEmitterReset
// Address: 0x804ABBA4, Size: 152
void PEmitterReset() {
}

// PEmitterCreate
// Address: 0x804ABC3C, Size: 484
void PEmitterCreate() {
}

// PEmitterDestroy
// Address: 0x804ABE20, Size: 212
void PEmitterDestroy() {
}

// PEmitterReg
// Address: 0x804ABEF4, Size: 76
void PEmitterReg() {
}

// PEmitterUnReg
// Address: 0x804ABF40, Size: 92
void PEmitterUnReg() {
}

// PEmitterSetMatrix
// Address: 0x804ABF9C, Size: 140
void PEmitterSetMatrix() {
}

// PSystemCreate
// Address: 0x804AC05C, Size: 92
void PSystemCreate() {
}

// PSystemDestroy
// Address: 0x804AC0B8, Size: 68
void PSystemDestroy() {
}

// ParticleSysOpen
// Address: 0x804AC0FC, Size: 632
void ParticleSysOpen() {
}

// ParticleBirthPlane(pemitter *, PVector4 *, PVector4 *)
// Address: 0x804AC3E8, Size: 516
void ParticleBirthPlane(pemitter * p0, PVector4 * p1, PVector4 * p2) {
}

// ClipStringInternal(char *, ERFont *, int, int, float)
// Address: 0x804AF154, Size: 180
void ClipStringInternal(char * p0, ERFont * p1, int p2, int p3, float p4) {
}

// ClipString(char *, ERFont *, float)
// Address: 0x804AF208, Size: 140
void ClipString(char * p0, ERFont * p1, float p2) {
}

// CompareByName(void *, void *)
// Address: 0x804B8B00, Size: 108
void CompareByName(void * p0, void * p1) {
}

// CompareBySize(void *, void *)
// Address: 0x804B8B6C, Size: 100
void CompareBySize(void * p0, void * p1) {
}

// UpdateFloatTextWidget(CUIWindow *, int, float)
// Address: 0x804BA128, Size: 80
void UpdateFloatTextWidget(CUIWindow * p0, int p1, float p2) {
}

// FloatSliderPropertyUpdate(unsigned int, CUIWindow *, int)
// Address: 0x804BA1F0, Size: 112
void FloatSliderPropertyUpdate(unsigned int p0, CUIWindow * p1, int p2) {
}

// MaxisTraceLog(char *, char *,...)
// Address: 0x804BCA78, Size: 288
void MaxisTraceLog(char * p0, char * p1, ... p2) {
}

// MaxisTraceLogCapture(char *, bool)
// Address: 0x804BCB98, Size: 88
void MaxisTraceLogCapture(char * p0, bool p1) {
}

// MaxisTraceLogDebug(char *, bool)
// Address: 0x804BCBF0, Size: 88
void MaxisTraceLogDebug(char * p0, bool p1) {
}

// MaxisClearLog(char *)
// Address: 0x804BCC48, Size: 56
void MaxisClearLog(char * p0) {
}

// GetCycleCount(void)
// Address: 0x804BF474, Size: 132
void GetCycleCount() {
}

// CyclesToMS(unsigned int)
// Address: 0x804BF4F8, Size: 68
void CyclesToMS(unsigned int p0) {
}

// log2down(int)
// Address: 0x804C577C, Size: 24
void log2down(int p0) {
}

// Pause(float)
// Address: 0x804C5794, Size: 124
void Pause(float p0) {
}

// DumpBinary64(void *, int)
// Address: 0x804C5810, Size: 32
void DumpBinary64(void * p0, int p1) {
}

// ilog2(float)
// Address: 0x804C5830, Size: 104
void ilog2(float p0) {
}

// pow2(int)
// Address: 0x804C58C0, Size: 68
void pow2(int p0) {
}

// MemSet32(void *, unsigned int, int)
// Address: 0x804C5904, Size: 36
void MemSet32(void * p0, unsigned int p1, int p2) {
}

// blendDt(float, float, float, float)
// Address: 0x804C5928, Size: 104
void blendDt(float p0, float p1, float p2, float p3) {
}

// blendAngleDt(float, float, float, float)
// Address: 0x804C5990, Size: 196
void blendAngleDt(float p0, float p1, float p2, float p3) {
}

// GetAngleDelta(float, float)
// Address: 0x804C5A54, Size: 148
void GetAngleDelta(float p0, float p1) {
}

// GetAngleDiff(float, float)
// Address: 0x804C5AE8, Size: 152
void GetAngleDiff(float p0, float p1) {
}

// blendFloat(float, float, float)
// Address: 0x804C5B80, Size: 24
void blendFloat(float p0, float p1, float p2) {
}

// AngleRange90(float, bool *)
// Address: 0x804C5B98, Size: 168
void AngleRange90(float p0, bool * p1) {
}

// LineCircleIntersect(EVec2, EVec2, EVec2, float, EVec2 &, EVec2 &)
// Address: 0x804C5C40, Size: 476
void LineCircleIntersect(EVec2 p0, EVec2 p1, EVec2 p2, float p3, EVec2 & p4, EVec2 & p5) {
}

// CalcDeterminant(float, float, float, float)
// Address: 0x804C5E1C, Size: 12
void CalcDeterminant(float p0, float p1, float p2, float p3) {
}

// LineLineIntersect(EVec2, EVec2, EVec2, EVec2, EVec2 &)
// Address: 0x804C5E28, Size: 312
void LineLineIntersect(EVec2 p0, EVec2 p1, EVec2 p2, EVec2 p3, EVec2 & p4) {
}

// IsOnRightOf(EVec2, EVec2, EVec2)
// Address: 0x804C5F60, Size: 72
void IsOnRightOf(EVec2 p0, EVec2 p1, EVec2 p2) {
}

// IsRectTouchingArc(EVec2, EVec2, float, EVec2, EVec2)
// Address: 0x804C5FA8, Size: 640
void IsRectTouchingArc(EVec2 p0, EVec2 p1, float p2, EVec2 p3, EVec2 p4) {
}

// CalcTwoSides(float &, float &, float, float, float)
// Address: 0x804C6228, Size: 152
void CalcTwoSides(float & p0, float & p1, float p2, float p3, float p4) {
}

// CalcAdjacentSide(float &, float, float, float)
// Address: 0x804C62C0, Size: 100
void CalcAdjacentSide(float & p0, float p1, float p2, float p3) {
}

// CalcThreeAngles(float &, float &, float &, float, float, float)
// Address: 0x804C6324, Size: 188
void CalcThreeAngles(float & p0, float & p1, float & p2, float p3, float p4, float p5) {
}

// InitTree(void)
// Address: 0x804CBD28, Size: 68
void InitTree() {
}

// InsertNode(int)
// Address: 0x804CBD6C, Size: 372
void InsertNode(int p0) {
}

// DeleteNode(int)
// Address: 0x804CBEE0, Size: 292
void DeleteNode(int p0) {
}

// GetChar(void)
// Address: 0x804CC004, Size: 48
void GetChar() {
}

// PutChar(int)
// Address: 0x804CC034, Size: 52
void PutChar(int p0) {
}

// Add2Bytes(unsigned char *&, unsigned short)
// Address: 0x804CE1A0, Size: 36
void Add2Bytes(unsigned char *& p0, unsigned short p1) {
}

// Add1Byte(unsigned char *&, unsigned char)
// Address: 0x804CE1C4, Size: 36
void Add1Byte(unsigned char *& p0, unsigned char p1) {
}

// ComputeTCBMults(float, float, float &, float &)
// Address: 0x804CF2D0, Size: 60
void ComputeTCBMults(float p0, float p1, float & p2, float & p3) {
}

// ComputeHermiteBasis(float, float *)
// Address: 0x804D0A74, Size: 84
void ComputeHermiteBasis(float p0, float * p1) {
}

// InterpSpline(float, EVec3 *, float, float, float, float)
// Address: 0x804D0AC8, Size: 452
void InterpSpline(float p0, EVec3 * p1, float p2, float p3, float p4, float p5) {
}

// IsAnyPrintable(unsigned int)
// Address: 0x804D3578, Size: 44
void IsAnyPrintable(unsigned int p0) {
}

// CopyERAnimNodeArray(TArray<EAnimNodeDataPos, TArrayERAnimAllocator> &, char *)
// Address: 0x804D35A4, Size: 348
void CopyERAnimNodeArray(TArray<EAnimNodeDataPos, TArrayERAnimAllocator> & p0, char * p1) {
}

// CopyERAnimConstantArray(TArray<float, TArrayERAnimAllocator> &, char *)
// Address: 0x804D3700, Size: 148
void CopyERAnimConstantArray(TArray<float, TArrayERAnimAllocator> & p0, char * p1) {
}

// CopyERAnimNoteArray(TArray<EAnimNote, TArrayERAnimAllocator> &, char *)
// Address: 0x804D3794, Size: 220
void CopyERAnimNoteArray(TArray<EAnimNote, TArrayERAnimAllocator> & p0, char * p1) {
}

// CopyERAnimEventArray(TArray<EAnimEvent, TArrayERAnimAllocator> &, char *)
// Address: 0x804D3870, Size: 260
void CopyERAnimEventArray(TArray<EAnimEvent, TArrayERAnimAllocator> & p0, char * p1) {
}

// IffMapCompare(void *, void *)
// Address: 0x804D76B0, Size: 32
void IffMapCompare(void * p0, void * p1) {
}

// CenterRectAndShiftMatrix(float *, EMat4 &)
// Address: 0x804DDCFC, Size: 284
void CenterRectAndShiftMatrix(float * p0, EMat4 & p1) {
}

// CalcShadowBounds(ESubModelShader &, EBound3 &)
// Address: 0x804E17E4, Size: 444
void CalcShadowBounds(ESubModelShader & p0, EBound3 & p1) {
}

// applyFixups(void *, unsigned int, EFile *, unsigned int, EXPORT_DIRECTORY &)
// Address: 0x804E8538, Size: 836
void applyFixups(void * p0, unsigned int p1, EFile * p2, unsigned int p3, EXPORT_DIRECTORY & p4) {
}

// LoadXImage(char *, int)
// Address: 0x804E887C, Size: 136
void LoadXImage(char * p0, int p1) {
}

// ReloadXImage(EFile *, void *, unsigned int &, int)
// Address: 0x804E8938, Size: 796
void ReloadXImage(EFile * p0, void * p1, unsigned int & p2, int p3) {
}

// RemapRegister(signed char &)
// Address: 0x804EEAD0, Size: 180
void RemapRegister(signed char & p0) {
}

// IdleCheck(void)
// Address: 0x804F035C, Size: 148
void IdleCheck() {
}

// CUIAddControllerDebugTools(void)
// Address: 0x804F79B8, Size: 92
void CUIAddControllerDebugTools() {
}

// ResourceHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD04C, Size: 148
void ResourceHeapFreeMemory(EA::Allocator::GeneralAllocator * p0, unsigned int p1, unsigned int p2, void * p3) {
}

// AudioHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD0E0, Size: 152
void AudioHeapFreeMemory(EA::Allocator::GeneralAllocator * p0, unsigned int p1, unsigned int p2, void * p3) {
}

// VMHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD178, Size: 232
void VMHeapFreeMemory(EA::Allocator::GeneralAllocator * p0, unsigned int p1, unsigned int p2, void * p3) {
}

// FreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, EResourceManager &)
// Address: 0x804FD260, Size: 168
void FreeMemory(EA::Allocator::GeneralAllocator * p0, unsigned int p1, EResourceManager & p2) {
}

// DMAHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD308, Size: 8
void DMAHeapFreeMemory(EA::Allocator::GeneralAllocator * p0, unsigned int p1, unsigned int p2, void * p3) {
}

// ShaderHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD310, Size: 40
void ShaderHeapFreeMemory(EA::Allocator::GeneralAllocator * p0, unsigned int p1, unsigned int p2, void * p3) {
}

// TextureHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD338, Size: 84
void TextureHeapFreeMemory(EA::Allocator::GeneralAllocator * p0, unsigned int p1, unsigned int p2, void * p3) {
}

// AnimationHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD38C, Size: 40
void AnimationHeapFreeMemory(EA::Allocator::GeneralAllocator * p0, unsigned int p1, unsigned int p2, void * p3) {
}

// ModelHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD3B4, Size: 84
void ModelHeapFreeMemory(EA::Allocator::GeneralAllocator * p0, unsigned int p1, unsigned int p2, void * p3) {
}

// FlashesHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD408, Size: 40
void FlashesHeapFreeMemory(EA::Allocator::GeneralAllocator * p0, unsigned int p1, unsigned int p2, void * p3) {
}

// MemStartResourcePrint(void)
// Address: 0x804FEDC0, Size: 72
void MemStartResourcePrint() {
}

// MemDumpResources(void)
// Address: 0x804FEEE0, Size: 264
void MemDumpResources() {
}
