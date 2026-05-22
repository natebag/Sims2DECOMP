// 0x8002510C EHouse::SetLightIntensityScaleFromRoom(EILight (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 28,4; lwz 29,-21472(13); lwz 0,0x1c(28); addi 5,1,8; addi 6,1,10; cmpwi 0,0; beq 1f; lwz 3,0x28(28); li 4,0; mtspr 8,0; blrl; b 2f; 0:; lwz 8,0x38(3); addi 9,3,56; lwz 10,0x8(9); addi 11,28,156; lwz 0,0x4(9); stw 8,0x9c(28); stw 10,0x8(11); stw 0,0x4(11); b 7f; 1:; sth 0,0x8(1); sth 0,0xa(1); 2:; lwz 9,0x4(29); lwz 30,0x8(9); b 5f; 3:; lwz 31,0x14(30); cmpwi 31,0; beq 4f; lwz 0,0x34(31); cmpwi 0,0; beq 4f; lhz 4,0x2(31); mr 3,29; bl _s8002510C_0; mr. 3,3; beq 4f; lhz 9,0x0(31); lha 0,0x8(1); cmpw 9,0; beq 0b; 4:; mr 3,30; bl _s8002510C_1; mr 30,3; 5:; lwz 0,0x4(29); li 9,1; cmpw 30,0; bne 6f; li 9,0; 6:; cmpwi 9,0; bne 3b; 7:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s8002510C_0();
extern "C" void _s8002510C_1();
extern "C" void f_8002510C() {}
