// 0x8024BB9C OSDefaultExceptionHandler (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8024E304" lines="stw 0,0x0(4); stw 1,0x4(4); stw 2,0x8(4); stmw 6,0x18(4); mfspr 0,913; stw 0,0x1a8(4); mfspr 0,914; stw 0,0x1ac(4); mfspr 0,915; stw 0,0x1b0(4); mfspr 0,916; stw 0,0x1b4(4); mfspr 0,917; stw 0,0x1b8(4); mfspr 0,918; stw 0,0x1bc(4); mfspr 0,919; stw 0,0x1c0(4); mfspr 5,18; mfspr 6,19; stwu 1,-8(1)"
extern "C" void f_8024E304();
extern "C" void f_8024BB9C() {}
