// 0x8038DB40 GXGetTexObjLODBias (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); lis 0,17200; lwz 3,0x0(3); lfd f2,-17512(13); rlwinm 3,3,23,24,31; lfs f0,-17516(13); extsh 3,3; extsb 3,3; xori 3,3,32768; stw 3,0x1c(1); stw 0,0x18(1); lfd f1,0x18(1); fsubs f1,f1,f2; fmuls f1,f1,f0; addi 1,1,32"
extern "C" void f_8038DB40() {}
