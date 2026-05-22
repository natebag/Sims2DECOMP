// 0x8007604C SkinCompositor::FinalizeSkinTexture(void) (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x4(3); cmpwi 0,0; beq 0f; lwz 9,0x18(3); lwz 3,0x8(3); lwz 4,0x14(9); bl _s8007604C_0; b 1f; 0:; lwz 9,0x18(3); lwz 3,0x8(3); lwz 4,0x14(9); bl _s8007604C_1; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8007604C_0();
extern "C" void _s8007604C_1();
extern "C" void f_8007604C() {}
