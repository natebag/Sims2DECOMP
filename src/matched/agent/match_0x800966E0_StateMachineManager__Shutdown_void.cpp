// 0x800966E0 StateMachineManager::Shutdown(void) (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 0,0x2c(1); lwz 8,-21500(13); cmpwi 8,0; beq 1f; li 0,0; addi 7,1,8; stw 0,0x8(1); addi 9,1,16; stw 0,0x4(7); addi 11,7,8; stw 0,0x4(9); addi 10,8,8; lwz 0,0x0(8); lwz 9,0x8(1); stw 0,0x8(1); stw 9,0x0(8); lwz 0,0x4(8); lwz 9,0xc(1); stw 0,0xc(1); stw 9,0x4(8); lwz 0,0x4(11); stw 0,0x24(1); lwz 9,0x8(8); lwz 0,0x4(10); stw 9,0x8(7); stw 0,0x4(11); lwz 9,0x20(1); lwz 0,0x24(1); stw 9,0x8(8); stw 0,0x4(10); lwz 3,0x8(1); cmpwi 3,0; beq 1f; lwz 0,0xc(7); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 0f; bl _s800966E0_0; b 1f; 0:; bl _s800966E0_1; 1:; li 0,0; stw 0,-21500(13); lwz 0,0x2c(1); mtspr 8,0; addi 1,1,40"
extern "C" void _s800966E0_0();
extern "C" void _s800966E0_1();
extern "C" void f_800966E0() {}
