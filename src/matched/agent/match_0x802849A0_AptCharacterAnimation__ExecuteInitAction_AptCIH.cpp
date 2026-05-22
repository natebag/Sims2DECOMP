// 0x802849A0 AptCharacterAnimation::ExecuteInitAction(AptCIH (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; mfcr 12; stmw 25,0x14(1); stw 0,0x34(1); stw 12,0x10(1); mr 29,3; li 11,0; lwz 9,0x4(29); mr 30,4; lwz 0,0x0(9); cmpw 11,0; bge 4f; lis 25,-32694; cmpwi 4,30,0; li 27,0; li 10,0; 0:; lwz 9,0x4(9); lwzx 31,10,9; lwz 0,0x0(31); cmpwi 0,8; bne 3f; lwz 0,0x4(31); cmpw 0,5; bne 3f; mr 3,29; mr 4,30; bl _s802849A0_0; addi 26,1,8; addi 3,25,-16032; mr 4,26; bl _s802849A0_1; mr 28,3; beq cr4,1f; mr 3,30; bl _s802849A0_2; lwz 7,0x4c(3); b 2f; 1:; li 7,0; 2:; lwz 9,0x4(29); mr 5,30; li 6,-1; addi 3,25,-16032; lwz 11,0x4(9); lwzx 9,27,11; lwz 4,0x8(9); bl _s802849A0_3; addi 3,25,-16032; mr 4,28; mr 5,26; bl _s802849A0_4; lwz 0,0x4(31); neg 0,0; stw 0,0x4(31); b 4f; 3:; lwz 9,0x4(29); addi 11,11,1; addi 27,27,4; addi 10,10,4; lwz 0,0x0(9); cmpw 11,0; blt 0b; 4:; lwz 0,0x34(1); lwz 12,0x10(1); mtspr 8,0; lmw 25,0x14(1); mtcrf 8,12; addi 1,1,48"
extern "C" void _s802849A0_0();
extern "C" void _s802849A0_1();
extern "C" void _s802849A0_2();
extern "C" void _s802849A0_3();
extern "C" void _s802849A0_4();
extern "C" void f_802849A0() {}
