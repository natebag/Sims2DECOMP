// 0x8038D85C GXInitTexObjLODBias (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); lfs f0,-17544(13); fcmpo f0,f1,f0; bge 0f; fmr f1,f0; b 1f; 0:; lfs f0,-17540(13); fcmpo f0,f1,f0; cror 2,1,2; bne 1f; lfs f1,-17536(13); 1:; lfs f0,-17532(13); lwz 4,0x0(3); fmuls f0,f0,f1; fctiwz f0,f0; stfd f0,0x10(1); lwz 0,0x14(1); rlwimi 4,0,9,15,22; stw 4,0x0(3); addi 1,1,24"
extern "C" void f_8038D85C() {}
