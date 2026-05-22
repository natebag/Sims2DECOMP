// 0x8024D800 OSSaveContext (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stmw 13,0x34(3); mfspr 0,913; stw 0,0x1a8(3); mfspr 0,914; stw 0,0x1ac(3); mfspr 0,915; stw 0,0x1b0(3); mfspr 0,916; stw 0,0x1b4(3); mfspr 0,917; stw 0,0x1b8(3); mfspr 0,918; stw 0,0x1bc(3); mfspr 0,919; stw 0,0x1c0(3); mfcr 0; stw 0,0x80(3); mfspr 0,8; stw 0,0x84(3); stw 0,0x198(3); mfmsr 0; stw 0,0x19c(3); mfspr 0,9; stw 0,0x88(3); mfspr 0,1; stw 0,0x8c(3); stw 1,0x4(3); stw 2,0x8(3); li 0,1; stw 0,0xc(3); li 3,0"
extern "C" void f_8024D800() {}
