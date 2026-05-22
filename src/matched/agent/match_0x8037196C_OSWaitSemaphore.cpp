// 0x8037196C OSWaitSemaphore (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); mr 29,3; bl _s8037196C_0; mr 31,3; b 1f; 0:; addi 3,29,4; bl _s8037196C_1; 1:; lwz 30,0x0(29); cmpwi 30,0; ble 0b; lwz 4,0x0(29); addi 3,31,0; addi 0,4,-1; stw 0,0x0(29); bl _s8037196C_2; mr 3,30; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8037196C_0();
extern "C" void _s8037196C_1();
extern "C" void _s8037196C_2();
extern "C" void f_8037196C() {}
