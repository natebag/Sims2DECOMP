// 0x8005CC2C SAnimator2::updateMovementState(void) (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x18(3); cmpwi 0,5; ble 0f; bl _s8005CC2C_0; b 2f; 0:; lwz 0,0x10(3); cmpwi 0,1; bne 1f; bl _s8005CC2C_1; b 2f; 1:; lwz 0,0x61c(3); andi. 9,0,1; beq 2f; bl _s8005CC2C_2; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8005CC2C_0();
extern "C" void _s8005CC2C_1();
extern "C" void _s8005CC2C_2();
extern "C" void f_8005CC2C() {}
