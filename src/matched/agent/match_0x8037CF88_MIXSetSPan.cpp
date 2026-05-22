// 0x8037CF88 MIXSetSPan (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; cmpwi 4,0; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); lwz 0,0x18(3); lis 3,-32688; mulli 5,0,96; addi 0,3,-30144; add 31,0,5; bge 0f; li 4,0; b 1f; 0:; cmpwi 4,127; ble 1f; li 4,127; 1:; stw 4,0x18(31); mr 3,31; bl _s8037CF88_0; lwz 0,0x4(31); oris 0,0,16384; stw 0,0x4(31); lwz 0,0x1c(1); lwz 31,0x14(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037CF88_0();
extern "C" void f_8037CF88() {}
