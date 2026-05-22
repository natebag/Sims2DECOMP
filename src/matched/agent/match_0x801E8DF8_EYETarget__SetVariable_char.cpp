// 0x801E8DF8 EYETarget::SetVariable(char (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,5; mr 3,4; bl _s801E8DF8_0; addi 11,31,212; lwz 9,0xd4(31); lwz 0,0x4(11); li 10,0; subf 0,9,0; srawi. 9,0,2; ble 2f; mr 7,11; li 8,0; 0:; lwz 9,0xd4(31); lwzx 11,9,8; lwz 0,0x4(11); cmpw 3,0; bne 1f; lwz 9,0x8(11); mr 4,30; lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; b 2f; 1:; lwz 0,0x4(7); addi 10,10,1; addi 8,8,4; subf 0,9,0; srawi 0,0,2; cmpw 10,0; blt 0b; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801E8DF8_0();
extern "C" void f_801E8DF8() {}
