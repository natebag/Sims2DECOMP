// 0x8024265C copysignf (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); stfs f1,0x8(1); lwz 9,0x8(1); stfs f2,0x8(1); lwz 0,0x8(1); rlwinm 9,9,0,1,31; clrlwi 0,0,0; or 9,9,0; stw 9,0x8(1); lfs f0,0x8(1); fmr f1,f0; addi 1,1,16"
extern "C" void f_8024265C() {}
