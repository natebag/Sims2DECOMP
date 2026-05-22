// 0x8019E2BC CASPersonalTarget::HandlePersonalityAnimation(char (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,0x84(3); lwz 31,0x14(9); cmpwi 31,0; beq 0f; bl _s8019E2BC_0; mr 4,3; mr 3,31; bl _s8019E2BC_1; 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8019E2BC_0();
extern "C" void _s8019E2BC_1();
extern "C" void f_8019E2BC() {}
