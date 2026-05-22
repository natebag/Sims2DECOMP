// 0x801743FC CasSimState::GetNextAvailableHairStyle(signed (464 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 24,0x28(1); stw 0,0x4c(1); mr 25,3; mr 24,5; mr 27,4; addi 3,1,8; mr 28,6; addi 4,25,8; li 5,2; bl _s801743FC_0; lwz 26,0xc(1); mr 3,25; li 5,4; mr 6,24; mr 4,26; bl _s801743FC_1; mr 30,3; cmpw 26,30; beq 7f; addi 31,1,24; addi 29,1,8; 0:; stw 30,0xc(1); cmpwi 30,1; beq 3f; bgt 1f; cmpwi 30,0; beq 2f; b 6f; 1:; cmpwi 30,2; beq 4f; cmpwi 30,3; beq 5f; b 6f; 2:; lwz 10,0x8(1); mr 3,28; lwz 11,0x4(29); li 4,2; lwz 9,0x8(29); mr 5,27; lwz 0,0xc(29); mr 6,31; stw 10,0x18(1); stw 11,0x4(31); stw 9,0x8(31); stw 0,0xc(31); bl _s801743FC_2; cmpwi 3,0; beq 6f; li 3,0; b 8f; 3:; lwz 10,0x8(1); mr 3,28; lwz 11,0x4(29); li 4,4; lwz 9,0x8(29); mr 5,27; lwz 0,0xc(29); mr 6,31; stw 10,0x18(1); stw 11,0x4(31); stw 9,0x8(31); stw 0,0xc(31); bl _s801743FC_3; cmpwi 3,0; beq 6f; li 3,1; b 8f; 4:; lwz 10,0x8(1); mr 3,28; lwz 11,0x4(29); li 4,5; lwz 9,0x8(29); mr 5,27; lwz 0,0xc(29); mr 6,31; stw 10,0x18(1); stw 11,0x4(31); stw 9,0x8(31); stw 0,0xc(31); bl _s801743FC_4; cmpwi 3,0; beq 6f; li 3,2; b 8f; 5:; lwz 10,0x8(1); mr 3,28; lwz 11,0x4(29); li 4,6; lwz 9,0x8(29); mr 5,27; lwz 0,0xc(29); mr 6,31; stw 10,0x18(1); stw 11,0x4(31); stw 9,0x8(31); stw 0,0xc(31); bl _s801743FC_5; cmpwi 3,0; li 3,3; bne 8f; 6:; mr 4,30; mr 3,25; li 5,4; mr 6,24; bl _s801743FC_6; mr 30,3; cmpw 26,30; bne 0b; 7:; mr 3,30; 8:; lwz 0,0x4c(1); mtspr 8,0; lmw 24,0x28(1); addi 1,1,72"
extern "C" void _s801743FC_0();
extern "C" void _s801743FC_1();
extern "C" void _s801743FC_2();
extern "C" void _s801743FC_3();
extern "C" void _s801743FC_4();
extern "C" void _s801743FC_5();
extern "C" void _s801743FC_6();
extern "C" void f_801743FC() {}
