// 0x803C7DB0 EStream (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 29,3; mr 28,4; lwz 9,0x18(29); addi 4,1,8; lwz 31,0x4(28); li 5,4; lha 3,0x38(9); lwz 0,0x3c(9); add 3,29,3; stw 31,0x8(1); mtspr 8,0; blrl; cmpwi 31,0; ble 1f; li 30,0; 0:; lwz 9,0x0(28); mr 3,29; lwzx 4,9,30; addi 30,30,4; bl _s803C7DB0_0; addic. 31,31,-1; bne 0b; 1:; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s803C7DB0_0();
extern "C" void f_803C7DB0() {}
