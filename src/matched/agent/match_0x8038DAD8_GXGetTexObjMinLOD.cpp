// 0x8038DAD8 GXGetTexObjMinLOD (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); lis 0,17200; lwz 3,0x4(3); lfd f2,-17552(13); rlwinm 3,3,0,24,31; lfs f0,-17520(13); stw 3,0x14(1); stw 0,0x10(1); lfd f1,0x10(1); fsubs f1,f1,f2; fmuls f1,f1,f0; addi 1,1,24"
extern "C" void f_8038DAD8() {}
