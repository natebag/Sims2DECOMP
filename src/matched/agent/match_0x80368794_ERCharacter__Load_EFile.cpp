// 0x80368794 ERCharacter::Load(EFile (704 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 22,0x38(1); stw 0,0x64(1); mr 29,3; mr 31,4; addi 3,1,8; bl _s80368794_0; lis 5,17224; addi 3,1,8; mr 4,31; ori 5,5,21059; li 6,9; li 7,9; bl _s80368794_1; cmpwi 3,0; beq 0f; addi 3,1,8; bl _s80368794_2; b 1f; 0:; addi 3,1,32; mr 30,3; bl _s80368794_3; mr 4,30; mr 3,31; bl _s80368794_4; lwz 4,0x20(1); mr 3,30; bl _s80368794_5; 1:; lwz 9,0x28(31); addi 4,1,48; li 5,4; addi 25,29,20; lwz 0,0x1c(9); li 30,0; lha 3,0x18(9); addi 22,29,48; mtspr 8,0; addi 24,29,32; add 3,31,3; addi 23,29,44; blrl; lwz 4,0x30(1); mr 3,25; li 5,0; bl _s80368794_6; b 6f; 2:; mulli 11,30,184; lwz 9,0x28(31); lwz 0,0x0(25); li 5,4; lha 3,0x18(9); li 28,0; lwz 9,0x1c(9); addi 26,30,1; add 29,0,11; add 3,31,3; mtspr 8,9; mr 4,29; addi 27,29,4; blrl; lwz 9,0x28(31); addi 4,1,52; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 4,0x34(1); mr 3,27; li 5,0; bl _s80368794_7; lwz 0,0x34(1); cmpw 28,0; bge 4f; li 30,0; 3:; lwz 9,0x28(31); li 5,4; lwz 4,0x0(27); addi 28,28,1; lwz 0,0x1c(9); lha 3,0x18(9); add 4,4,30; mtspr 8,0; addi 30,30,4; add 3,31,3; blrl; lwz 0,0x34(1); cmpw 28,0; blt 3b; 4:; lwz 9,0x28(31); addi 4,29,16; li 5,12; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,29,28; li 5,16; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,1,40; li 5,1; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lbz 0,0x28(1); li 9,1; cmpwi 0,0; bne 5f; li 9,0; 5:; stw 9,0xb0(29); addi 4,29,48; li 5,64; mr 30,26; lwz 9,0x28(31); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); addi 4,29,112; li 5,64; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; addi 4,29,180; mr 3,31; bl _s80368794_8; 6:; lwz 0,0x30(1); cmpw 30,0; blt 2b; lwz 9,0x28(31); mr 4,24; li 5,12; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); mr 4,23; li 5,4; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x28(31); mr 4,22; li 5,4; lha 3,0x18(9); lwz 0,0x1c(9); add 3,31,3; mtspr 8,0; blrl; addi 3,1,8; li 4,2; bl _s80368794_9; lwz 0,0x64(1); mtspr 8,0; lmw 22,0x38(1); addi 1,1,96"
extern "C" void _s80368794_0();
extern "C" void _s80368794_1();
extern "C" void _s80368794_2();
extern "C" void _s80368794_3();
extern "C" void _s80368794_4();
extern "C" void _s80368794_5();
extern "C" void _s80368794_6();
extern "C" void _s80368794_7();
extern "C" void _s80368794_8();
extern "C" void _s80368794_9();
extern "C" void f_80368794() {}
