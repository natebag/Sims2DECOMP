// 0x8004E868 ISimsObjectModel::SetWallForPortal(void) (492 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; mfcr 12; stmw 25,0x4c(1); stw 0,0x6c(1); stw 12,0x48(1); mr 28,3; li 0,0; lwz 11,0x328(28); stw 0,0x45c(28); cmpwi 11,0; beq 7f; lwz 9,0x4(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 7f; lwz 9,0x3c8(28); cmpwi 9,0; beq 7f; lwz 0,0x8(9); cmpwi 0,0; beq 7f; lwz 3,0x328(28); cmpwi 3,0; beq 0f; lwz 3,0x0(3); li 4,6; bl _s8004E868_0; mr 27,3; b 1f; 0:; li 27,0; 1:; lwz 9,0x0(27); lwz 11,0x3c8(28); lwz 10,0x0(9); lwz 25,0x8(11); lwz 9,0x4(10); lwz 0,0x2a4(9); lha 3,0x2a0(9); mtspr 8,0; add 3,10,3; blrl; lwz 11,0x328(28); mr 26,3; addi 3,1,8; lwz 9,0x4(11); lwz 0,0x35c(9); lha 4,0x358(9); mtspr 8,0; add 4,11,4; blrl; lwz 11,-21488(13); addi 4,1,8; lwz 9,0x0(11); lha 3,0x58(9); lwz 0,0x5c(9); add 3,11,3; mtspr 8,0; blrl; xori 3,3,1; cmpwi 3,0; beq 6f; mcrf cr4,cr0; cmpwi 26,0; bne 5f; lwz 11,-21488(13); addi 30,1,16; mr 3,30; addi 5,1,8; lwz 9,0x0(11); lha 4,0xa8(9); lwz 0,0xac(9); add 4,11,4; mtspr 8,0; blrl; mr 3,30; bl _s8004E868_1; mr 31,3; mr 29,30; b 3f; 2:; mr 4,31; mr 3,29; bl _s8004E868_2; mr 31,3; 3:; cmpwi 31,0; beq 4f; lwz 9,0x4(27); lha 3,0x10(9); lwz 0,0x14(9); add 3,27,3; mtspr 8,0; blrl; mr 30,3; mr 4,31; mr 3,29; bl _s8004E868_3; cmpw 30,3; bne 2b; mr 26,31; 4:; mr 3,29; li 4,2; bl _s8004E868_4; 5:; beq cr4,6f; cmpwi 26,0; beq 6f; mr 3,25; mr 4,26; addi 5,1,8; bl _s8004E868_5; stw 3,0x45c(28); 6:; addi 3,1,8; li 4,2; bl _s8004E868_6; 7:; lwz 0,0x6c(1); lwz 12,0x48(1); mtspr 8,0; lmw 25,0x4c(1); mtcrf 8,12; addi 1,1,104"
extern "C" void _s8004E868_0();
extern "C" void _s8004E868_1();
extern "C" void _s8004E868_2();
extern "C" void _s8004E868_3();
extern "C" void _s8004E868_4();
extern "C" void _s8004E868_5();
extern "C" void _s8004E868_6();
extern "C" void f_8004E868() {}
