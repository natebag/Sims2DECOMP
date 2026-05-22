// 0x8023884C Emitter::EmitterSetPostDestroyCallback(void (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 0,0x14(1); lwz 0,0x7c(3); mr 9,4; mr 10,5; cmpwi 0,0; beq 0f; li 0,0; li 4,0; li 5,0; li 6,0; li 7,0; li 8,0; stw 0,0xc(1); ori 4,4,65535; stw 0,0x8(1); ori 5,5,65535; ori 6,6,65535; ori 7,7,65535; ori 8,8,65535; bl _s8023884C_0; 0:; lwz 0,0x14(1); mtspr 8,0; addi 1,1,16"
extern "C" void _s8023884C_0();
extern "C" void f_8023884C() {}
