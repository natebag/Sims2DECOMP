// 0x802307CC ELightGrid::EvaluatePortalLights(int, (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,4; mr 28,3; cmpw 31,5; bge 1f; rlwinm 9,31,5,0,26; addi 0,9,32; subf 31,31,5; addi 9,9,16416; add 30,0,28; add 29,9,28; 0:; mr 4,30; mr 5,29; mr 3,28; addi 29,29,32; bl _s802307CC_0; addi 30,30,32; addic. 31,31,-1; bne 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802307CC_0();
extern "C" void f_802307CC() {}
