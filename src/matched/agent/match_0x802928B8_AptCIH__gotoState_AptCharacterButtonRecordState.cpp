// 0x802928B8 AptCIH::gotoState(AptCharacterButtonRecordState) (220 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 28,3; lwz 31,0x4c(28); lwz 0,0x18(31); cmpw 4,0; beq 2f; addi 3,31,28; stw 4,0x18(31); mr 26,3; li 4,0; bl _s802928B8_0; li 29,0; lwz 9,0x8(31); lwz 0,0x2c(9); cmpw 29,0; bge 2f; li 27,0; lis 25,-32704; li 30,0; 0:; lwz 9,0x30(9); lwz 11,0x18(31); lwzx 0,30,9; add 10,30,9; and. 9,0,11; beq 1f; lwz 6,0x4(10); addi 9,10,12; addi 0,10,36; stw 9,0xc(1); lfs f1,0x5bb8(25); mr 3,26; stw 0,0x8(1); li 4,0; stw 27,0x10(1); mr 5,29; stw 27,0x14(1); li 7,0; mr 8,28; li 9,0; li 10,-1; bl _s802928B8_1; 1:; lwz 9,0x8(31); addi 29,29,1; addi 30,30,68; lwz 0,0x2c(9); cmpw 29,0; blt 0b; 2:; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"
extern "C" void _s802928B8_0();
extern "C" void _s802928B8_1();
extern "C" void f_802928B8() {}
