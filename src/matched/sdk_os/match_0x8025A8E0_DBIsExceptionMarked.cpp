// COMPILER: mwcc
// 0x8025A8E0 DBIsExceptionMarked (28B) — Dolphin SDK db/db.c
//
// Tests bit (exception & 0xFF) of the debugger interface's exception mask word
// (field at +4). MWCC GC-1.2.5n.

extern unsigned int* __DBInterface;

extern "C" int DBIsExceptionMarked(int exception) {
    return __DBInterface[1] & (1 << (exception & 0xFF));
}
