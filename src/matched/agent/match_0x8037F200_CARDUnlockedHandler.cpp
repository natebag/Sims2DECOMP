// 0x8037F200 __CARDUnlockedHandler (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); addi 30,3,0; mulli 4,30,272; lis 3,-32688; addi 0,3,-24000; add 3,0,4; lwz 0,0xdc(3); cmplwi 0,0; mr 31,0; beq 2f; li 0,0; stw 0,0xdc(3); mr 3,30; bl _s8037F200_0; cmpwi 3,0; beq 0f; li 4,1; b 1f; 0:; li 4,-3; 1:; addi 12,31,0; mtspr 8,12; addi 3,30,0; blrl; 2:; lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s8037F200_0();
extern "C" void f_8037F200() {}
