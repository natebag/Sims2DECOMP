// 0x803035D4 PEmitterReg (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lwz 3,0x0(29); lis 4,-32702; addi 4,4,-1912; mr 5,30; li 6,1; bl _s803035D4_0; stw 29,0xb8(30); stw 3,0x8c(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803035D4_0();
extern "C" void f_803035D4() {}
