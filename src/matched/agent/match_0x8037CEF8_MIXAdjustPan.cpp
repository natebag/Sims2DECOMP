// 0x8037CEF8 MIXAdjustPan (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); lwz 5,0x18(3); lis 3,-32688; addi 0,3,-30144; mulli 3,5,96; add 3,0,3; lwz 0,0x14(3); addi 31,3,0; add. 0,0,4; bge 0f; li 0,0; b 1f; 0:; cmpwi 0,127; ble 1f; li 0,127; 1:; stw 0,0x14(31); mr 3,31; bl _s8037CEF8_0; lwz 0,0x4(31); oris 0,0,16384; stw 0,0x4(31); lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037CEF8_0();
extern "C" void f_8037CEF8() {}
