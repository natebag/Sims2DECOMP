// 0x8038049C CARDSetDiskID (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; mulli 5,3,272; stw 0,0x4(1); stwu 1,-24(1); lis 3,-32688; addi 0,3,-24000; stw 31,0x14(1); add 31,0,5; stw 30,0x10(1); addi 30,4,0; bl _s8038049C_0; lwz 0,0x4(31); cmpwi 0,-1; bne 0f; li 3,-1; b 3f; 0:; cmplwi 30,0; beq 1f; mr 0,30; b 2f; 1:; lis 0,-32768; 2:; stw 0,0x10c(31); bl _s8038049C_1; li 3,0; 3:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8038049C_0();
extern "C" void _s8038049C_1();
extern "C" void f_8038049C() {}
