// 0x8038D7BC GXInitTexObjMaxLOD (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); lfs f0,-17528(13); fcmpo f0,f1,f0; bge 0f; fmr f1,f0; b 1f; 0:; lfs f0,-17524(13); fcmpo f0,f1,f0; ble 1f; fmr f1,f0; 1:; lfs f0,-17560(13); lwz 4,0x4(3); fmuls f0,f0,f1; fctiwz f0,f0; stfd f0,0x10(1); lwz 0,0x14(1); rlwimi 4,0,8,16,23; stw 4,0x4(3); addi 1,1,24"
extern "C" void f_8038D7BC() {}
