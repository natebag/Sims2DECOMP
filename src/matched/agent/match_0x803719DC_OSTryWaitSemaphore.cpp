// 0x803719DC OSTryWaitSemaphore (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); mr 30,3; bl _s803719DC_0; lwz 4,0x0(30); cmpwi 4,0; addi 31,4,0; ble 0f; addi 0,4,-1; stw 0,0x0(30); 0:; bl _s803719DC_1; mr 3,31; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s803719DC_0();
extern "C" void _s803719DC_1();
extern "C" void f_803719DC() {}
