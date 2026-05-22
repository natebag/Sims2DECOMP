// 0x8006B7E8 EGlobal::ListenForController(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8006B800" lines="stw 30,0x94(1)"
extern "C" void f_8006B800();
extern "C" void f_8006B7E8() {}
