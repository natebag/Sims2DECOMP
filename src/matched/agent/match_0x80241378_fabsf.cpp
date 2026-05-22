// 0x80241378 fabsf (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); stfs f1,0x8(1); lwz 0,0x8(1); rlwinm 0,0,0,1,31; stw 0,0x8(1); lfs f0,0x8(1); fmr f1,f0; addi 1,1,16"
extern "C" void f_80241378() {}
