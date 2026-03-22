// apt_lib.cpp - APT library internals
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 454 functions
//
// These are stub implementations to be replaced with matching decompilations.
// Each function needs to be decompiled to match the original binary.

#include "types.h"
#include "stub_classes.h"

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
void negindex() {
}

// f_call(lua_State *, void *)
// Address: 0x8044530C, Size: 40
void f_call() {
}

// f_Ccall(lua_State *, void *)
// Address: 0x804453B8, Size: 196
void f_Ccall() {
}

// aux_upvalue(lua_State *, int, int, lua_TObject **)
// Address: 0x80445848, Size: 184
void aux_upvalue() {
}

// currentpc(CallInfo *)
// Address: 0x804459B4, Size: 76
void currentpc() {
}

// currentline(CallInfo *)
// Address: 0x80445A00, Size: 100
void currentline() {
}

// getluaproto(CallInfo *)
// Address: 0x80445BA8, Size: 40
void getluaproto() {
}

// funcinfo(lua_Debug *, lua_TObject *)
// Address: 0x80445D14, Size: 156
void funcinfo() {
}

// travglobals(lua_State *, lua_TObject *)
// Address: 0x80445DB0, Size: 144
void travglobals() {
}

// info_tailcall(lua_State *, lua_Debug *)
// Address: 0x80445E40, Size: 128
void info_tailcall() {
}

// auxgetinfo(lua_State *, char *, lua_Debug *, lua_TObject *, CallInfo *)
// Address: 0x80445EC0, Size: 352
void auxgetinfo() {
}

// precheck(Proto *)
// Address: 0x80446138, Size: 84
void precheck() {
}

// checkopenop(Proto *, int)
// Address: 0x8044618C, Size: 80
void checkopenop() {
}

// checkRK(Proto *, int)
// Address: 0x804461DC, Size: 52
void checkRK() {
}

// kname(Proto *, int)
// Address: 0x80446674, Size: 56
void kname() {
}

// getobjname(CallInfo *, int, char **)
// Address: 0x804466AC, Size: 316
void getobjname() {
}

// getfuncname(CallInfo *, char **)
// Address: 0x804467E8, Size: 160
void getfuncname() {
}

// isinstack(CallInfo *, lua_TObject *)
// Address: 0x80446888, Size: 52
void isinstack() {
}

// addinfo(lua_State *, char *)
// Address: 0x80446A8C, Size: 136
void addinfo() {
}

// seterrorobj(lua_State *, int, lua_TObject *)
// Address: 0x80446C8C, Size: 180
void seterrorobj() {
}

// restore_stack_limit(lua_State *)
// Address: 0x80446DFC, Size: 112
void restore_stack_limit() {
}

// correctstack(lua_State *, lua_TObject *)
// Address: 0x80446E6C, Size: 144
void correctstack() {
}

// adjust_varargs(lua_State *, int, lua_TObject *)
// Address: 0x80447178, Size: 372
void adjust_varargs() {
}

// tryfuncTM(lua_State *, lua_TObject *)
// Address: 0x804472EC, Size: 212
void tryfuncTM() {
}

// callrethooks(lua_State *, lua_TObject *)
// Address: 0x8044758C, Size: 132
void callrethooks() {
}

// resume(lua_State *, void *)
// Address: 0x804477AC, Size: 196
void resume() {
}

// resume_error(lua_State *, char *)
// Address: 0x80447870, Size: 140
void resume_error() {
}

// f_parser(lua_State *, void *)
// Address: 0x80447B78, Size: 200
void f_parser() {
}

// DumpBlock(void *, unsigned int, DumpState *)
// Address: 0x80447CD8, Size: 60
void DumpBlock() {
}

// DumpByte(int, DumpState *)
// Address: 0x80447D14, Size: 48
void DumpByte() {
}

// DumpInt(int, DumpState *)
// Address: 0x80447D44, Size: 48
void DumpInt() {
}

// DumpSize(unsigned int, DumpState *)
// Address: 0x80447D74, Size: 48
void DumpSize() {
}

// DumpNumber(int, DumpState *)
// Address: 0x80447DA4, Size: 48
void DumpNumber() {
}

// DumpString(TString *, DumpState *)
// Address: 0x80447DD4, Size: 108
void DumpString() {
}

// DumpCode(Proto *, DumpState *)
// Address: 0x80447E40, Size: 72
void DumpCode() {
}

// DumpLocals(Proto *, DumpState *)
// Address: 0x80447E88, Size: 140
void DumpLocals() {
}

// DumpLines(Proto *, DumpState *)
// Address: 0x80447F14, Size: 72
void DumpLines() {
}

// DumpUpvalues(Proto *, DumpState *)
// Address: 0x80447F5C, Size: 96
void DumpUpvalues() {
}

// DumpConstants(Proto *, DumpState *)
// Address: 0x80447FBC, Size: 224
void DumpConstants() {
}

// DumpFunction(Proto *, TString *, DumpState *)
// Address: 0x8044809C, Size: 192
void DumpFunction() {
}

// DumpHeader(DumpState *)
// Address: 0x8044815C, Size: 196
void DumpHeader() {
}

// reallymarkobject(GCState *, GCObject *)
// Address: 0x80448684, Size: 172
void reallymarkobject() {
}

// marktmu(GCState *)
// Address: 0x80448730, Size: 92
void marktmu() {
}

// removekey(Node *)
// Address: 0x80448874, Size: 32
void removekey() {
}

// traversetable(GCState *, Table *)
// Address: 0x80448894, Size: 552
void traversetable() {
}

// traverseproto(GCState *, Proto *)
// Address: 0x80448ABC, Size: 328
void traverseproto() {
}

// traverseclosure(GCState *, Closure *)
// Address: 0x80448C04, Size: 300
void traverseclosure() {
}

// checkstacksizes(lua_State *, lua_TObject *)
// Address: 0x80448D30, Size: 160
void checkstacksizes() {
}

// traversestack(GCState *, lua_State *)
// Address: 0x80448DD0, Size: 248
void traversestack() {
}

// propagatemarks(GCState *)
// Address: 0x80448EC8, Size: 184
void propagatemarks() {
}

// valismarked(lua_TObject *)
// Address: 0x80448F80, Size: 72
void valismarked() {
}

// cleartablekeys(GCObject *)
// Address: 0x80448FC8, Size: 132
void cleartablekeys() {
}

// cleartablevalues(GCObject *)
// Address: 0x8044904C, Size: 192
void cleartablevalues() {
}

// freeobj(lua_State *, GCObject *)
// Address: 0x8044910C, Size: 176
void freeobj() {
}

// sweeplist(lua_State *, GCObject **, int)
// Address: 0x804491BC, Size: 128
void sweeplist() {
}

// sweepstrings(lua_State *, int)
// Address: 0x8044923C, Size: 128
void sweepstrings() {
}

// checkSizes(lua_State *, unsigned int)
// Address: 0x804492BC, Size: 184
void checkSizes() {
}

// do1gcTM(lua_State *, Udata *)
// Address: 0x80449374, Size: 156
void do1gcTM() {
}

// markroot(GCState *, lua_State *)
// Address: 0x80449534, Size: 184
void markroot() {
}

// mark(lua_State *)
// Address: 0x804495EC, Size: 188
void mark() {
}

// pushstr(lua_State *, char *)
// Address: 0x80449A90, Size: 128
void pushstr() {
}

// next(LexState *)
// Address: 0x80449FCC, Size: 104
void next() {
}

// lookahead(LexState *)
// Address: 0x8044A034, Size: 52
void lookahead() {
}

// error_expected(LexState *, int)
// Address: 0x8044A068, Size: 84
void error_expected() {
}

// testnext(LexState *, int)
// Address: 0x8044A0BC, Size: 60
void testnext() {
}

// check(LexState *, int)
// Address: 0x8044A0F8, Size: 68
void check() {
}

// check_match(LexState *, int, int, int)
// Address: 0x8044A13C, Size: 168
void check_match() {
}

// str_checkname(LexState *)
// Address: 0x8044A1E4, Size: 80
void str_checkname() {
}

// init_exp(expdesc *, expkind, int)
// Address: 0x8044A234, Size: 24
void init_exp() {
}

// codestring(LexState *, expdesc *, TString *)
// Address: 0x8044A24C, Size: 68
void codestring() {
}

// checkname(LexState *, expdesc *)
// Address: 0x8044A290, Size: 64
void checkname() {
}

// new_localvar(LexState *, TString *, int)
// Address: 0x8044A35C, Size: 112
void new_localvar() {
}

// adjustlocalvars(LexState *, int)
// Address: 0x8044A3CC, Size: 84
void adjustlocalvars() {
}

// removevars(LexState *, int)
// Address: 0x8044A420, Size: 76
void removevars() {
}

// new_localvarstr(LexState *, char *, int)
// Address: 0x8044A46C, Size: 92
void new_localvarstr() {
}

// create_local(LexState *, char *)
// Address: 0x8044A4C8, Size: 60
void create_local() {
}

// indexupvalue(FuncState *, TString *, expdesc *)
// Address: 0x8044A504, Size: 312
void indexupvalue() {
}

// searchvar(FuncState *, TString *)
// Address: 0x8044A63C, Size: 76
void searchvar() {
}

// markupval(FuncState *, int)
// Address: 0x8044A688, Size: 52
void markupval() {
}

// singlevaraux(FuncState *, TString *, expdesc *, int)
// Address: 0x8044A6BC, Size: 224
void singlevaraux() {
}

// singlevar(LexState *, expdesc *, int)
// Address: 0x8044A79C, Size: 80
void singlevar() {
}

// adjust_assign(LexState *, int, int, expdesc *)
// Address: 0x8044A7EC, Size: 168
void adjust_assign() {
}

// code_params(LexState *, int, int)
// Address: 0x8044A894, Size: 132
void code_params() {
}

// enterblock(FuncState *, BlockCnt *, int)
// Address: 0x8044A918, Size: 44
void enterblock() {
}

// leaveblock(FuncState *)
// Address: 0x8044A944, Size: 120
void leaveblock() {
}

// pushclosure(LexState *, FuncState *, expdesc *)
// Address: 0x8044A9BC, Size: 264
void pushclosure() {
}

// open_func(LexState *, FuncState *)
// Address: 0x8044AAC4, Size: 164
void open_func() {
}

// close_func(LexState *)
// Address: 0x8044AB68, Size: 332
void close_func() {
}

// recfield(LexState *, ConsControl *)
// Address: 0x8044AE10, Size: 232
void recfield() {
}

// closelistfield(FuncState *, ConsControl *)
// Address: 0x8044AEF8, Size: 128
void closelistfield() {
}

// lastlistfield(FuncState *, ConsControl *)
// Address: 0x8044AF78, Size: 172
void lastlistfield() {
}

// listfield(LexState *, ConsControl *)
// Address: 0x8044B024, Size: 100
void listfield() {
}

// constructor(LexState *, expdesc *)
// Address: 0x8044B088, Size: 428
void constructor() {
}

// parlist(LexState *)
// Address: 0x8044B234, Size: 188
void parlist() {
}

// body(LexState *, expdesc *, int, int)
// Address: 0x8044B2F0, Size: 176
void body() {
}

// explist1(LexState *, expdesc *)
// Address: 0x8044B3A0, Size: 108
void explist1() {
}

// funcargs(LexState *, expdesc *)
// Address: 0x8044B40C, Size: 384
void funcargs() {
}

// prefixexp(LexState *, expdesc *)
// Address: 0x8044B58C, Size: 164
void prefixexp() {
}

// primaryexp(LexState *, expdesc *)
// Address: 0x8044B630, Size: 252
void primaryexp() {
}

// simpleexp(LexState *, expdesc *)
// Address: 0x8044B72C, Size: 292
void simpleexp() {
}

// getunopr(int)
// Address: 0x8044B850, Size: 40
void getunopr() {
}

// getbinopr(int)
// Address: 0x8044B878, Size: 272
void getbinopr() {
}

// subexpr(LexState *, expdesc *, int)
// Address: 0x8044B988, Size: 320
void subexpr() {
}

// expr(LexState *, expdesc *)
// Address: 0x8044BAC8, Size: 36
void expr() {
}

// block_follow(int)
// Address: 0x8044BAEC, Size: 56
void block_follow() {
}

// block(LexState *)
// Address: 0x8044BB24, Size: 76
void block() {
}

// check_conflict(LexState *, LHS_assign *, expdesc *)
// Address: 0x8044BB70, Size: 172
void check_conflict() {
}

// assignment(LexState *, LHS_assign *, int)
// Address: 0x8044BC1C, Size: 340
void assignment() {
}

// cond(LexState *, expdesc *)
// Address: 0x8044BD70, Size: 92
void cond() {
}

// whilestat(LexState *, int)
// Address: 0x8044BDCC, Size: 456
void whilestat() {
}

// repeatstat(LexState *, int)
// Address: 0x8044BF94, Size: 148
void repeatstat() {
}

// exp1(LexState *)
// Address: 0x8044C028, Size: 68
void exp1() {
}

// forbody(LexState *, int, int, int, int)
// Address: 0x8044C06C, Size: 252
void forbody() {
}

// fornum(LexState *, TString *, int)
// Address: 0x8044C168, Size: 280
void fornum() {
}

// forlist(LexState *, TString *)
// Address: 0x8044C280, Size: 268
void forlist() {
}

// forstat(LexState *, int)
// Address: 0x8044C38C, Size: 200
void forstat() {
}

// test_then_block(LexState *, expdesc *)
// Address: 0x8044C454, Size: 80
void test_then_block() {
}

// ifstat(LexState *, int)
// Address: 0x8044C4A4, Size: 244
void ifstat() {
}

// localfunc(LexState *)
// Address: 0x8044C598, Size: 188
void localfunc() {
}

// localstat(LexState *)
// Address: 0x8044C654, Size: 168
void localstat() {
}

// funcname(LexState *, expdesc *)
// Address: 0x8044C6FC, Size: 116
void funcname() {
}

// funcstat(LexState *, int)
// Address: 0x8044C770, Size: 112
void funcstat() {
}

// exprstat(LexState *)
// Address: 0x8044C7E0, Size: 112
void exprstat() {
}

// retstat(LexState *)
// Address: 0x8044C850, Size: 248
void retstat() {
}

// breakstat(LexState *)
// Address: 0x8044C948, Size: 176
void breakstat() {
}

// statement(LexState *)
// Address: 0x8044C9F8, Size: 364
void statement() {
}

// chunk(LexState *)
// Address: 0x8044CB64, Size: 152
void chunk() {
}

// default_panic(lua_State *)
// Address: 0x8044CBFC, Size: 8
void default_panic() {
}

// mallocstate(lua_State *)
// Address: 0x8044CC04, Size: 60
void mallocstate() {
}

// freestate(lua_State *, lua_State *)
// Address: 0x8044CC40, Size: 40
void freestate() {
}

// stack_init(lua_State *, lua_State *)
// Address: 0x8044CC68, Size: 196
void stack_init() {
}

// freestack(lua_State *, lua_State *)
// Address: 0x8044CD2C, Size: 88
void freestack() {
}

// f_luaopen(lua_State *, void *)
// Address: 0x8044CD84, Size: 380
void f_luaopen() {
}

// preinit_state(lua_State *)
// Address: 0x8044CF00, Size: 76
void preinit_state() {
}

// close_state(lua_State *)
// Address: 0x8044CF4C, Size: 176
void close_state() {
}

// callallgcTM(lua_State *, void *)
// Address: 0x8044D144, Size: 32
void callallgcTM() {
}

// newlstr(lua_State *, char *, unsigned int, unsigned int)
// Address: 0x8044D304, Size: 224
void newlstr() {
}

// hashnum(Table *, int)
// Address: 0x8044D538, Size: 64
void hashnum() {
}

// arrayindex(lua_TObject *)
// Address: 0x8044D650, Size: 44
void arrayindex() {
}

// computesizes(int *, int, int *, int *)
// Address: 0x8044D84C, Size: 200
void computesizes() {
}

// numuse(Table *, int *, int *)
// Address: 0x8044D914, Size: 412
void numuse() {
}

// setarrayvector(lua_State *, Table *, int)
// Address: 0x8044DAB0, Size: 124
void setarrayvector() {
}

// setnodevector(lua_State *, Table *, int)
// Address: 0x8044DB2C, Size: 216
void setnodevector() {
}

// resize(lua_State *, Table *, int, int)
// Address: 0x8044DC04, Size: 432
void resize() {
}

// rehash(lua_State *, Table *)
// Address: 0x8044DDB4, Size: 92
void rehash() {
}

// newkey(lua_State *, Table *, lua_TObject *)
// Address: 0x8044DF28, Size: 308
void newkey() {
}

// unexpectedEOZ(LoadState *)
// Address: 0x8044E418, Size: 52
void unexpectedEOZ() {
}

// ezgetc(LoadState *)
// Address: 0x8044E44C, Size: 124
void ezgetc() {
}

// ezread(LoadState *, void *, int)
// Address: 0x8044E4C8, Size: 64
void ezread() {
}

// LoadBlock(LoadState *, void *, unsigned int)
// Address: 0x8044E508, Size: 112
void LoadBlock() {
}

// LoadVector(LoadState *, void *, int, unsigned int)
// Address: 0x8044E578, Size: 156
void LoadVector() {
}

// LoadInt(LoadState *)
// Address: 0x8044E614, Size: 92
void LoadInt() {
}

// LoadSize(LoadState *)
// Address: 0x8044E670, Size: 44
void LoadSize() {
}

// LoadNumber(LoadState *)
// Address: 0x8044E69C, Size: 44
void LoadNumber() {
}

// LoadString(LoadState *)
// Address: 0x8044E6C8, Size: 112
void LoadString() {
}

// LoadCode(LoadState *, Proto *)
// Address: 0x8044E738, Size: 104
void LoadCode() {
}

// LoadLocals(LoadState *, Proto *)
// Address: 0x8044E7A0, Size: 164
void LoadLocals() {
}

// LoadLines(LoadState *, Proto *)
// Address: 0x8044E844, Size: 104
void LoadLines() {
}

// LoadUpvalues(LoadState *, Proto *)
// Address: 0x8044E8AC, Size: 164
void LoadUpvalues() {
}

// LoadConstants(LoadState *, Proto *)
// Address: 0x8044E950, Size: 324
void LoadConstants() {
}

// LoadFunction(LoadState *, TString *)
// Address: 0x8044EA94, Size: 244
void LoadFunction() {
}

// LoadSignature(LoadState *)
// Address: 0x8044EB88, Size: 124
void LoadSignature() {
}

// TestSize(LoadState *, int, char *)
// Address: 0x8044EC04, Size: 96
void TestSize() {
}

// LoadHeader(LoadState *)
// Address: 0x8044EC64, Size: 416
void LoadHeader() {
}

// LoadChunk(LoadState *)
// Address: 0x8044EE04, Size: 56
void LoadChunk() {
}

// traceexec(lua_State *)
// Address: 0x8044EFA0, Size: 308
void traceexec() {
}

// callTMres(lua_State *, lua_TObject *, lua_TObject *, lua_TObject *)
// Address: 0x8044F0D4, Size: 164
void callTMres() {
}

// callTM(lua_State *, lua_TObject *, lua_TObject *, lua_TObject *, lua_TObject *)
// Address: 0x8044F178, Size: 172
void callTM() {
}

// call_binTM(lua_State *, lua_TObject *, lua_TObject *, lua_TObject *, TMS)
// Address: 0x8044F538, Size: 168
void call_binTM() {
}

// get_compTM(lua_State *, Table *, Table *, TMS)
// Address: 0x8044F5E0, Size: 224
void get_compTM() {
}

// call_orderTM(lua_State *, lua_TObject *, lua_TObject *, TMS)
// Address: 0x8044F6C0, Size: 188
void call_orderTM() {
}

// Arith(lua_State *, lua_TObject *, lua_TObject *, lua_TObject *, TMS)
// Address: 0x8044FCB0, Size: 420
void Arith() {
}

// tag_error(lua_State *, int, int)
// Address: 0x8045118C, Size: 68
void tag_error() {
}

// checkint(lua_State *, int)
// Address: 0x804519C4, Size: 100
void checkint() {
}

// getsizes(lua_State *)
// Address: 0x80451A28, Size: 196
void getsizes() {
}

// emptybuffer(luaL_Buffer *)
// Address: 0x80451CD8, Size: 100
void emptybuffer() {
}

// adjuststack(luaL_Buffer *)
// Address: 0x80451D3C, Size: 164
void adjuststack() {
}

// getF(lua_State *, void *, unsigned int *)
// Address: 0x8045218C, Size: 108
void getF() {
}

// errfile(lua_State *, int)
// Address: 0x804521F8, Size: 108
void errfile() {
}

// getS(lua_State *, void *, unsigned int *)
// Address: 0x80452404, Size: 40
void getS() {
}

// callalert(lua_State *, int)
// Address: 0x80452460, Size: 180
void callalert() {
}

// aux_do(lua_State *, int)
// Address: 0x80452514, Size: 84
void aux_do() {
}

// getfunc(lua_State *)
// Address: 0x80452A10, Size: 224
void getfunc() {
}

// aux_getfenv(lua_State *)
// Address: 0x80452AF0, Size: 108
void aux_getfenv() {
}

// load_aux(lua_State *, int)
// Address: 0x80453028, Size: 76
void load_aux() {
}

// getpath(lua_State *)
// Address: 0x8045366C, Size: 136
void getpath() {
}

// pushnextpath(lua_State *, char *)
// Address: 0x804536F4, Size: 132
void pushnextpath() {
}

// pushcomposename(lua_State *)
// Address: 0x80453778, Size: 160
void pushcomposename() {
}

// auxresume(lua_State *, lua_State *, int)
// Address: 0x80453A9C, Size: 220
void auxresume() {
}

// base_open(lua_State *)
// Address: 0x80453E88, Size: 292
void base_open() {
}

// pushresult(lua_State *, int, char *)
// Address: 0x80454028, Size: 184
void pushresult() {
}

// topfile(lua_State *, int)
// Address: 0x804540E0, Size: 88
void topfile() {
}

// io_type(lua_State *)
// Address: 0x80454138, Size: 136
void io_type() {
}

// tofile(lua_State *, int)
// Address: 0x804541C0, Size: 84
void tofile() {
}

// newfile(lua_State *)
// Address: 0x80454214, Size: 92
void newfile() {
}

// registerfile(lua_State *, __sFILE *, char *, char *)
// Address: 0x80454270, Size: 124
void registerfile() {
}

// aux_close(lua_State *)
// Address: 0x804542EC, Size: 136
void aux_close() {
}

// io_close(lua_State *)
// Address: 0x80454374, Size: 128
void io_close() {
}

// io_gc(lua_State *)
// Address: 0x804543F4, Size: 72
void io_gc() {
}

// io_tostring(lua_State *)
// Address: 0x8045443C, Size: 164
void io_tostring() {
}

// io_open(lua_State *)
// Address: 0x804544E0, Size: 140
void io_open() {
}

// io_popen(lua_State *)
// Address: 0x8045456C, Size: 48
void io_popen() {
}

// io_tmpfile(lua_State *)
// Address: 0x8045459C, Size: 88
void io_tmpfile() {
}

// getiofile(lua_State *, char *)
// Address: 0x804545F4, Size: 68
void getiofile() {
}

// g_iofile(lua_State *, char *, char *)
// Address: 0x80454638, Size: 272
void g_iofile() {
}

// io_input(lua_State *)
// Address: 0x80454748, Size: 48
void io_input() {
}

// io_output(lua_State *)
// Address: 0x80454778, Size: 48
void io_output() {
}

// aux_lines(lua_State *, int, int)
// Address: 0x804547A8, Size: 120
void aux_lines() {
}

// f_lines(lua_State *)
// Address: 0x80454820, Size: 68
void f_lines() {
}

// io_lines(lua_State *)
// Address: 0x80454864, Size: 212
void io_lines() {
}

// read_number(lua_State *, __sFILE *)
// Address: 0x80454938, Size: 96
void read_number() {
}

// test_eof(lua_State *, __sFILE *)
// Address: 0x80454998, Size: 136
void test_eof() {
}

// read_line(lua_State *, __sFILE *)
// Address: 0x80454A20, Size: 192
void read_line() {
}

// read_chars(lua_State *, __sFILE *, unsigned int)
// Address: 0x80454AE0, Size: 188
void read_chars() {
}

// g_read(lua_State *, __sFILE *, int)
// Address: 0x80454B9C, Size: 460
void g_read() {
}

// io_read(lua_State *)
// Address: 0x80454D68, Size: 68
void io_read() {
}

// f_read(lua_State *)
// Address: 0x80454DAC, Size: 64
void f_read() {
}

// io_readline(lua_State *)
// Address: 0x80454DEC, Size: 160
void io_readline() {
}

// g_write(lua_State *, __sFILE *, int)
// Address: 0x80454E8C, Size: 248
void g_write() {
}

// io_write(lua_State *)
// Address: 0x80454F84, Size: 68
void io_write() {
}

// f_write(lua_State *)
// Address: 0x80454FC8, Size: 64
void f_write() {
}

// f_seek(lua_State *)
// Address: 0x80455008, Size: 220
void f_seek() {
}

// io_flush(lua_State *)
// Address: 0x804550E4, Size: 76
void io_flush() {
}

// f_flush(lua_State *)
// Address: 0x80455130, Size: 72
void f_flush() {
}

// createmeta(lua_State *)
// Address: 0x80455178, Size: 120
void createmeta() {
}

// io_execute(lua_State *)
// Address: 0x804551F0, Size: 72
void io_execute() {
}

// io_remove(lua_State *)
// Address: 0x80455238, Size: 80
void io_remove() {
}

// io_rename(lua_State *)
// Address: 0x80455288, Size: 104
void io_rename() {
}

// io_tmpname(lua_State *)
// Address: 0x804552F0, Size: 48
void io_tmpname() {
}

// io_getenv(lua_State *)
// Address: 0x80455320, Size: 72
void io_getenv() {
}

// io_clock(lua_State *)
// Address: 0x80455368, Size: 84
void io_clock() {
}

// setfield(lua_State *, char *, int)
// Address: 0x804553BC, Size: 72
void setfield() {
}

// setboolfield(lua_State *, char *, int)
// Address: 0x80455404, Size: 72
void setboolfield() {
}

// getboolfield(lua_State *, char *)
// Address: 0x8045544C, Size: 88
void getboolfield() {
}

// getfield(lua_State *, char *, int)
// Address: 0x804554A4, Size: 156
void getfield() {
}

// io_date(lua_State *)
// Address: 0x80455540, Size: 464
void io_date() {
}

// io_time(lua_State *)
// Address: 0x80455710, Size: 324
void io_time() {
}

// io_difftime(lua_State *)
// Address: 0x80455854, Size: 104
void io_difftime() {
}

// io_setloc(lua_State *)
// Address: 0x804558BC, Size: 208
void io_setloc() {
}

// io_exit(lua_State *)
// Address: 0x8045598C, Size: 28
void io_exit() {
}

// str_len(lua_State *)
// Address: 0x80455A78, Size: 68
void str_len() {
}

// posrelat(long, unsigned int)
// Address: 0x80455ABC, Size: 20
void posrelat() {
}

// str_sub(lua_State *)
// Address: 0x80455AD0, Size: 192
void str_sub() {
}

// str_lower(lua_State *)
// Address: 0x80455B90, Size: 180
void str_lower() {
}

// str_upper(lua_State *)
// Address: 0x80455C44, Size: 180
void str_upper() {
}

// str_rep(lua_State *)
// Address: 0x80455CF8, Size: 144
void str_rep() {
}

// str_byte(lua_State *)
// Address: 0x80455D88, Size: 128
void str_byte() {
}

// str_char(lua_State *)
// Address: 0x80455E08, Size: 184
void str_char() {
}

// writer(lua_State *, void *, unsigned int, void *)
// Address: 0x80455EC0, Size: 40
void writer() {
}

// str_dump(lua_State *)
// Address: 0x80455EE8, Size: 124
void str_dump() {
}

// check_capture(MatchState *, int)
// Address: 0x80455F64, Size: 92
void check_capture() {
}

// capture_to_close(MatchState *)
// Address: 0x80455FC0, Size: 100
void capture_to_close() {
}

// match_class(int, int)
// Address: 0x804560FC, Size: 304
void match_class() {
}

// matchbracketclass(int, char *, char *)
// Address: 0x8045622C, Size: 208
void matchbracketclass() {
}

// matchbalance(MatchState *, char *, char *)
// Address: 0x80456384, Size: 200
void matchbalance() {
}

// max_expand(MatchState *, char *, char *, char *)
// Address: 0x8045644C, Size: 148
void max_expand() {
}

// min_expand(MatchState *, char *, char *, char *)
// Address: 0x804564E0, Size: 124
void min_expand() {
}

// start_capture(MatchState *, char *, char *, int)
// Address: 0x8045655C, Size: 148
void start_capture() {
}

// end_capture(MatchState *, char *, char *)
// Address: 0x804565F0, Size: 108
void end_capture() {
}

// match_capture(MatchState *, char *, int)
// Address: 0x8045665C, Size: 120
void match_capture() {
}

// match(MatchState *, char *, char *)
// Address: 0x804566D4, Size: 728
void match() {
}

// lmemfind(char *, unsigned int, char *, unsigned int)
// Address: 0x804569AC, Size: 168
void lmemfind() {
}

// push_onecapture(MatchState *, int)
// Address: 0x80456A54, Size: 140
void push_onecapture() {
}

// push_captures(MatchState *, char *, char *)
// Address: 0x80456AE0, Size: 160
void push_captures() {
}

// str_find(lua_State *)
// Address: 0x80456B80, Size: 444
void str_find() {
}

// gfind_aux(lua_State *)
// Address: 0x80456D3C, Size: 236
void gfind_aux() {
}

// gfind(lua_State *)
// Address: 0x80456E28, Size: 116
void gfind() {
}

// add_s(MatchState *, luaL_Buffer *, char *, char *)
// Address: 0x80456E9C, Size: 348
void add_s() {
}

// str_gsub(lua_State *)
// Address: 0x80456FF8, Size: 460
void str_gsub() {
}

// scanformat(lua_State *, char *, char *, int *)
// Address: 0x8045731C, Size: 320
void scanformat() {
}

// str_format(lua_State *)
// Address: 0x8045745C, Size: 624
void str_format() {
}

// str_concat(lua_State *)
// Address: 0x80457AF4, Size: 276
void str_concat() {
}

// set2(lua_State *, int, int)
// Address: 0x80457C08, Size: 72
void set2() {
}

// sort_comp(lua_State *, int, int)
// Address: 0x80457C50, Size: 168
void sort_comp() {
}

// auxsort(lua_State *, int, int)
// Address: 0x80457CF8, Size: 756
void auxsort() {
}

// ea_us_strtod
// Address: 0x804580C0, Size: 624
void ea_us_strtod() {
}

// ea_tmpfile
// Address: 0x80458330, Size: 48
void ea_tmpfile() {
}

// getjumpcontrol(FuncState *, int)
// Address: 0x80458560, Size: 60
void getjumpcontrol() {
}

// need_value(FuncState *, int, int)
// Address: 0x8045859C, Size: 132
void need_value() {
}

// patchtestreg(unsigned long *, int)
// Address: 0x80458620, Size: 40
void patchtestreg() {
}

// freereg(FuncState *, int)
// Address: 0x80458900, Size: 36
void freereg() {
}

// freeexp(FuncState *, expdesc *)
// Address: 0x80458924, Size: 48
void freeexp() {
}

// addk(FuncState *, lua_TObject *, lua_TObject *)
// Address: 0x80458954, Size: 220
void addk() {
}

// nil_constant(FuncState *)
// Address: 0x80458A98, Size: 64
void nil_constant() {
}

// code_label(FuncState *, int, int, int)
// Address: 0x80458C28, Size: 80
void code_label() {
}

// discharge2reg(FuncState *, expdesc *, int)
// Address: 0x80458C78, Size: 280
void discharge2reg() {
}

// discharge2anyreg(FuncState *, expdesc *)
// Address: 0x80458D90, Size: 84
void discharge2anyreg() {
}

// invertjump(FuncState *, expdesc *)
// Address: 0x80459268, Size: 60
void invertjump() {
}

// jumponcond(FuncState *, expdesc *, int)
// Address: 0x804592A4, Size: 176
void jumponcond() {
}

// codenot(FuncState *, expdesc *)
// Address: 0x80459498, Size: 220
void codenot() {
}

// codebinop(FuncState *, expdesc *, BinOpr, int, int)
// Address: 0x80459730, Size: 148
void codebinop() {
}

// inclinenumber(LexState *)
// Address: 0x80459DD0, Size: 144
void inclinenumber() {
}

// readname(LexState *)
// Address: 0x80459F44, Size: 232
void readname() {
}

// read_numeral(LexState *, int, SemInfo *)
// Address: 0x8045A02C, Size: 1068
void read_numeral() {
}

// read_long_string(LexState *, SemInfo *)
// Address: 0x8045A458, Size: 872
void read_long_string() {
}

// read_string(LexState *, int, SemInfo *)
// Address: 0x8045A7C0, Size: 1072
void read_string() {
}

// DupString(char *)
// Address: 0x8045C6F8, Size: 108
void DupString() {
}

// MatrixInvert(float **, int)
// Address: 0x80462C64, Size: 732
void MatrixInvert() {
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
void DefaultAlloc() {
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
void MemDumpSizes() {
}

// MemDumpRange(char *, int, int, int)
// Address: 0x80469924, Size: 368
void MemDumpRange() {
}

// MemValidateHeap(int)
// Address: 0x8046A010, Size: 392
void MemValidateHeap() {
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
void SnprintfLocal() {
}

// local_fcvt
// Address: 0x80479C24, Size: 880
void local_fcvt() {
}

// ReadFormat8(char *, FormatData *, __va_list_tag **)
// Address: 0x8047A008, Size: 1608
void ReadFormat8() {
}

// WriteLong(FormatData &, long, char *)
// Address: 0x8047A650, Size: 596
void WriteLong() {
}

// WriteLongLong(FormatData &, long long, char *)
// Address: 0x8047A8A4, Size: 728
void WriteLongLong() {
}

// WriteDouble(FormatData &, double, char *)
// Address: 0x8047AB7C, Size: 564
void WriteDouble() {
}

// VprintfCore8(bool (*)(char *, unsigned int, void *), void *, char *, __va_list_tag *)
// Address: 0x8047ADB0, Size: 2760
void VprintfCore8() {
}

// Printf(char *,...)
// Address: 0x8047B8F4, Size: 204
void Printf() {
}

// Sprintf(char *, char *,...)
// Address: 0x8047B9C0, Size: 156
void Sprintf() {
}

// Snprintf(char *, unsigned int, char *,...)
// Address: 0x8047BA5C, Size: 144
void Snprintf() {
}

// Vsprintf(char *, char *, __va_list_tag *)
// Address: 0x8047BAEC, Size: 52
void Vsprintf() {
}

// IsSpace(char)
// Address: 0x8047BB20, Size: 56
void IsSpace() {
}

// local_atof(char *, char **)
// Address: 0x8047BB58, Size: 364
void local_atof() {
}

// local_atoi(char *, char **)
// Address: 0x8047BCC4, Size: 160
void local_atoi() {
}

// AtoF(char *)
// Address: 0x8047BD64, Size: 36
void AtoF() {
}

// AtoI(char *)
// Address: 0x8047BD88, Size: 36
void AtoI() {
}

// Sscanf(char *, char *,...)
// Address: 0x8047BDAC, Size: 1020
void Sscanf() {
}

// MaxisDbgTraceBinary(void *, unsigned int)
// Address: 0x8047C310, Size: 240
void MaxisDbgTraceBinary() {
}

// DbgLogTraceClose(void)
// Address: 0x8047C450, Size: 52
void DbgLogTraceClose() {
}

// E_SendTestEvent(char *,...)
// Address: 0x80481C00, Size: 188
void E_SendTestEvent() {
}

// SetSendTestEventFunc(void (*)(char *))
// Address: 0x80481CBC, Size: 8
void SetSendTestEventFunc() {
}

// E_Log(char *,...)
// Address: 0x80481CC4, Size: 188
void E_Log() {
}

// SetLogFunc(void (*)(char *))
// Address: 0x80481D80, Size: 8
void SetLogFunc() {
}

// E_LogError(char *,...)
// Address: 0x80481D88, Size: 180
void E_LogError() {
}

// E_IsLogDebugEnabled(void)
// Address: 0x80481E3C, Size: 8
void E_IsLogDebugEnabled() {
}

// E_LogDebugEnable(bool)
// Address: 0x80481E44, Size: 8
void E_LogDebugEnable() {
}

// E_LogDebug(char *,...)
// Address: 0x80481E4C, Size: 192
void E_LogDebug() {
}

// E_LogMetric_L1(char *,...)
// Address: 0x80481F0C, Size: 192
void E_LogMetric_L1() {
}

// E_LogMetric_L2(char *,...)
// Address: 0x80481FCC, Size: 192
void E_LogMetric_L2() {
}

// E_LogMetric_L3(char *,...)
// Address: 0x8048208C, Size: 192
void E_LogMetric_L3() {
}

// SetLogMetricFunc(void (*)(char *, AutomationNS::ScriptLog::ReportingLevel))
// Address: 0x8048214C, Size: 8
void SetLogMetricFunc() {
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
void setClipPlaneOffsets() {
}

// locprintf(char *,...)
// Address: 0x80490C3C, Size: 76
void locprintf() {
}

// FloatToFixed1_0_7(float)
// Address: 0x804A2654, Size: 84
void FloatToFixed1_0_7() {
}

// Fixed1_0_7ToFloat(signed char)
// Address: 0x804A26A8, Size: 100
void Fixed1_0_7ToFloat() {
}

// VertexDataInitialization(unsigned int, unsigned int, unsigned int, bool)
// Address: 0x804A270C, Size: 4
void VertexDataInitialization() {
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
void ParticleBirthSphere() {
}

// ParticleBirthCone(pemitter *, PVector4 *, PVector4 *)
// Address: 0x804A9698, Size: 512
void ParticleBirthCone() {
}

// ParticleBirthCylinder(pemitter *, PVector4 *, PVector4 *)
// Address: 0x804A9898, Size: 344
void ParticleBirthCylinder() {
}

// PCalcTabDataSet(particle *, pemitterinfo *, float)
// Address: 0x804A99F0, Size: 168
void PCalcTabDataSet() {
}

// ParticleCreate(pemitter *, int)
// Address: 0x804A9A98, Size: 1688
void ParticleCreate() {
}

// ParticleProcess(pemitter *, float)
// Address: 0x804AA130, Size: 1496
void ParticleProcess() {
}

// ParticleProcessType0(pemitter *, float)
// Address: 0x804AA708, Size: 1664
void ParticleProcessType0() {
}

// ParticleProcessType1(pemitter *, float)
// Address: 0x804AAD88, Size: 1068
void ParticleProcessType1() {
}

// ParticleProcessType2(pemitter *, float)
// Address: 0x804AB1B4, Size: 1084
void ParticleProcessType2() {
}

// PEmitterProcess(pemitter *, float)
// Address: 0x804AB610, Size: 480
void PEmitterProcess() {
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
void ParticleBirthPlane() {
}

// ClipStringInternal(char *, ERFont *, int, int, float)
// Address: 0x804AF154, Size: 180
void ClipStringInternal() {
}

// ClipString(char *, ERFont *, float)
// Address: 0x804AF208, Size: 140
void ClipString() {
}

// CompareByName(void *, void *)
// Address: 0x804B8B00, Size: 108
void CompareByName() {
}

// CompareBySize(void *, void *)
// Address: 0x804B8B6C, Size: 100
void CompareBySize() {
}

// UpdateFloatTextWidget(CUIWindow *, int, float)
// Address: 0x804BA128, Size: 80
void UpdateFloatTextWidget() {
}

// FloatSliderPropertyUpdate(unsigned int, CUIWindow *, int)
// Address: 0x804BA1F0, Size: 112
void FloatSliderPropertyUpdate() {
}

// MaxisTraceLog(char *, char *,...)
// Address: 0x804BCA78, Size: 288
void MaxisTraceLog() {
}

// MaxisTraceLogCapture(char *, bool)
// Address: 0x804BCB98, Size: 88
void MaxisTraceLogCapture() {
}

// MaxisTraceLogDebug(char *, bool)
// Address: 0x804BCBF0, Size: 88
void MaxisTraceLogDebug() {
}

// MaxisClearLog(char *)
// Address: 0x804BCC48, Size: 56
void MaxisClearLog() {
}

// GetCycleCount(void)
// Address: 0x804BF474, Size: 132
void GetCycleCount() {
}

// CyclesToMS(unsigned int)
// Address: 0x804BF4F8, Size: 68
void CyclesToMS() {
}

// log2down(int)
// Address: 0x804C577C, Size: 24
void log2down() {
}

// Pause(float)
// Address: 0x804C5794, Size: 124
void Pause() {
}

// DumpBinary64(void *, int)
// Address: 0x804C5810, Size: 32
void DumpBinary64() {
}

// ilog2(float)
// Address: 0x804C5830, Size: 104
void ilog2() {
}

// pow2(int)
// Address: 0x804C58C0, Size: 68
void pow2() {
}

// MemSet32(void *, unsigned int, int)
// Address: 0x804C5904, Size: 36
void MemSet32() {
}

// blendDt(float, float, float, float)
// Address: 0x804C5928, Size: 104
void blendDt() {
}

// blendAngleDt(float, float, float, float)
// Address: 0x804C5990, Size: 196
void blendAngleDt() {
}

// GetAngleDelta(float, float)
// Address: 0x804C5A54, Size: 148
void GetAngleDelta() {
}

// GetAngleDiff(float, float)
// Address: 0x804C5AE8, Size: 152
void GetAngleDiff() {
}

// blendFloat(float, float, float)
// Address: 0x804C5B80, Size: 24
void blendFloat() {
}

// AngleRange90(float, bool *)
// Address: 0x804C5B98, Size: 168
void AngleRange90() {
}

// LineCircleIntersect(EVec2, EVec2, EVec2, float, EVec2 &, EVec2 &)
// Address: 0x804C5C40, Size: 476
void LineCircleIntersect() {
}

// CalcDeterminant(float, float, float, float)
// Address: 0x804C5E1C, Size: 12
void CalcDeterminant() {
}

// LineLineIntersect(EVec2, EVec2, EVec2, EVec2, EVec2 &)
// Address: 0x804C5E28, Size: 312
void LineLineIntersect() {
}

// IsOnRightOf(EVec2, EVec2, EVec2)
// Address: 0x804C5F60, Size: 72
void IsOnRightOf() {
}

// IsRectTouchingArc(EVec2, EVec2, float, EVec2, EVec2)
// Address: 0x804C5FA8, Size: 640
void IsRectTouchingArc() {
}

// CalcTwoSides(float &, float &, float, float, float)
// Address: 0x804C6228, Size: 152
void CalcTwoSides() {
}

// CalcAdjacentSide(float &, float, float, float)
// Address: 0x804C62C0, Size: 100
void CalcAdjacentSide() {
}

// CalcThreeAngles(float &, float &, float &, float, float, float)
// Address: 0x804C6324, Size: 188
void CalcThreeAngles() {
}

// InitTree(void)
// Address: 0x804CBD28, Size: 68
void InitTree() {
}

// InsertNode(int)
// Address: 0x804CBD6C, Size: 372
void InsertNode() {
}

// DeleteNode(int)
// Address: 0x804CBEE0, Size: 292
void DeleteNode() {
}

// GetChar(void)
// Address: 0x804CC004, Size: 48
void GetChar() {
}

// PutChar(int)
// Address: 0x804CC034, Size: 52
void PutChar() {
}

// Add2Bytes(unsigned char *&, unsigned short)
// Address: 0x804CE1A0, Size: 36
void Add2Bytes() {
}

// Add1Byte(unsigned char *&, unsigned char)
// Address: 0x804CE1C4, Size: 36
void Add1Byte() {
}

// ComputeTCBMults(float, float, float &, float &)
// Address: 0x804CF2D0, Size: 60
void ComputeTCBMults() {
}

// ComputeHermiteBasis(float, float *)
// Address: 0x804D0A74, Size: 84
void ComputeHermiteBasis() {
}

// InterpSpline(float, EVec3 *, float, float, float, float)
// Address: 0x804D0AC8, Size: 452
void InterpSpline() {
}

// IsAnyPrintable(unsigned int)
// Address: 0x804D3578, Size: 44
void IsAnyPrintable() {
}

// CopyERAnimNodeArray(TArray<EAnimNodeDataPos, TArrayERAnimAllocator> &, char *)
// Address: 0x804D35A4, Size: 348
void CopyERAnimNodeArray() {
}

// CopyERAnimConstantArray(TArray<float, TArrayERAnimAllocator> &, char *)
// Address: 0x804D3700, Size: 148
void CopyERAnimConstantArray() {
}

// CopyERAnimNoteArray(TArray<EAnimNote, TArrayERAnimAllocator> &, char *)
// Address: 0x804D3794, Size: 220
void CopyERAnimNoteArray() {
}

// CopyERAnimEventArray(TArray<EAnimEvent, TArrayERAnimAllocator> &, char *)
// Address: 0x804D3870, Size: 260
void CopyERAnimEventArray() {
}

// IffMapCompare(void *, void *)
// Address: 0x804D76B0, Size: 32
void IffMapCompare() {
}

// CenterRectAndShiftMatrix(float *, EMat4 &)
// Address: 0x804DDCFC, Size: 284
void CenterRectAndShiftMatrix() {
}

// CalcShadowBounds(ESubModelShader &, EBound3 &)
// Address: 0x804E17E4, Size: 444
void CalcShadowBounds() {
}

// applyFixups(void *, unsigned int, EFile *, unsigned int, EXPORT_DIRECTORY &)
// Address: 0x804E8538, Size: 836
void applyFixups() {
}

// LoadXImage(char *, int)
// Address: 0x804E887C, Size: 136
void LoadXImage() {
}

// ReloadXImage(EFile *, void *, unsigned int &, int)
// Address: 0x804E8938, Size: 796
void ReloadXImage() {
}

// RemapRegister(signed char &)
// Address: 0x804EEAD0, Size: 180
void RemapRegister() {
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
void ResourceHeapFreeMemory() {
}

// AudioHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD0E0, Size: 152
void AudioHeapFreeMemory() {
}

// VMHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD178, Size: 232
void VMHeapFreeMemory() {
}

// FreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, EResourceManager &)
// Address: 0x804FD260, Size: 168
void FreeMemory() {
}

// DMAHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD308, Size: 8
void DMAHeapFreeMemory() {
}

// ShaderHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD310, Size: 40
void ShaderHeapFreeMemory() {
}

// TextureHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD338, Size: 84
void TextureHeapFreeMemory() {
}

// AnimationHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD38C, Size: 40
void AnimationHeapFreeMemory() {
}

// ModelHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD3B4, Size: 84
void ModelHeapFreeMemory() {
}

// FlashesHeapFreeMemory(EA::Allocator::GeneralAllocator *, unsigned int, unsigned int, void *)
// Address: 0x804FD408, Size: 40
void FlashesHeapFreeMemory() {
}

// MemStartResourcePrint(void)
// Address: 0x804FEDC0, Size: 72
void MemStartResourcePrint() {
}

// MemDumpResources(void)
// Address: 0x804FEEE0, Size: 264
void MemDumpResources() {
}
