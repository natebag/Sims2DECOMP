// 0x80159EE4 QuickDataBehaviorConstants::LoadFromIndex(unsigned (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 9,-21508(13); mr 31,3; mr 29,4; mr 30,5; lwz 11,0x0(9); lha 3,0x38(11); lwz 0,0x3c(11); add 3,9,3; mtspr 8,0; blrl; lwz 9,0x8(3); cmpwi 30,0; ble 1f; lwz 0,0x20(9); li 11,0; mr 9,0; cmpwi 0,0; beq 0f; lwz 11,-4(9); 0:; cmpw 30,11; ble 2f; 1:; li 0,0; li 3,0; sth 0,0x4(31); stw 0,0x18(31); b 4f; 2:; addi 9,30,-1; li 11,0; rlwinm 9,9,4,0,27; add 9,0,9; stw 9,0x18(31); lwz 5,0x4(9); cmpwi 5,0; beq 3f; lwz 11,-4(5); 3:; addi 30,31,8; mr 4,29; sth 11,0x4(31); mr 3,30; bl _s80159EE4_0; lwz 9,0x18(31); mr 3,30; lhz 4,0x2(9); bl _s80159EE4_1; li 3,1; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80159EE4_0();
extern "C" void _s80159EE4_1();
extern "C" void f_80159EE4() {}
