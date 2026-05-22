// 0x8039BBC8 __VMBASEISIServiceExceptionPrep (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8039BC14" lines="stw 0,0x0(3); stw 1,0x4(3); stw 2,0x8(3); stmw 6,0x18(3); mfspr 0,913; stw 0,0x1a8(3); mfspr 0,914; stw 0,0x1ac(3); mfspr 0,915; stw 0,0x1b0(3); mfspr 0,916; stw 0,0x1b4(3); mfspr 0,917; stw 0,0x1b8(3); mfspr 0,918; stw 0,0x1bc(3); mfspr 0,919; stw 0,0x1c0(3)"
extern "C" void f_8039BC14();
extern "C" void f_8039BBC8() {}
