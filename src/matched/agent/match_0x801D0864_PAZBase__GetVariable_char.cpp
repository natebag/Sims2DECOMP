// 0x801D0864 PAZBase::GetVariable(char (528 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; li 3,32; bl _s801D0864_0; mr 29,3; li 0,0; stb 0,0x0(29); mr 4,30; lwz 9,0xb0(31); lwz 3,0x0(9); bl _s801D0864_1; cmpwi 3,0; bne 0f; lis 9,-32705; addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(29); sth 0,0x4(29); stb 8,0x6(29); b 16f; 0:; lwz 9,0xb0(31); mr 4,30; lwz 3,0x4(9); bl _s801D0864_2; cmpwi 3,0; bne 1f; lis 4,-32705; lwz 5,0xac(31); b 2f; 1:; lwz 9,0xb0(31); mr 4,30; lwz 3,0x8(9); bl _s801D0864_3; cmpwi 3,0; bne 3f; lis 4,-32705; lwz 5,0x8c(31); 2:; addi 4,4,-8800; mr 3,29; crxor 6,6,6; bl _s801D0864_4; b 16f; 3:; lwz 9,0xb0(31); mr 4,30; lwz 3,0xc(9); bl _s801D0864_5; cmpwi 3,0; bne 4f; lis 9,-32705; lhz 0,-5284(9); b 15f; 4:; lwz 9,0xb0(31); mr 4,30; lwz 3,0x10(9); bl _s801D0864_6; cmpwi 3,0; bne 10f; lis 9,-32697; li 30,1; lwz 0,0x61b0(9); cmpwi 0,0; bne 9f; lwz 11,-21484(13); cmpwi 11,0; beq 5f; lwz 9,0x0(11); lha 3,0x220(9); lwz 0,0x224(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 8f; 5:; lis 3,-32697; li 4,0; addi 3,3,24012; li 31,0; bl _s801D0864_7; cmpwi 3,0; bne 6f; lis 3,-32697; li 4,1; addi 3,3,24012; bl _s801D0864_8; cmpwi 3,0; beq 7f; 6:; li 31,1; 7:; cmpwi 31,0; beq 9f; 8:; li 30,0; 9:; cmpwi 30,0; bne 11f; b 12f; 10:; lwz 9,0xb0(31); mr 4,30; lwz 3,0x14(9); bl _s801D0864_9; cmpwi 3,0; bne 14f; lis 9,-32697; lwz 0,0x5c6c(9); cmpwi 0,0; bne 12f; 11:; lis 9,-32705; addi 4,9,-5288; b 13f; 12:; lis 9,-32705; addi 4,9,-5284; 13:; mr 3,29; bl _s801D0864_10; b 16f; 14:; lwz 9,0xb0(31); mr 4,30; lwz 3,0x18(9); bl _s801D0864_11; cmpwi 3,0; bne 16f; lis 9,-32705; lhz 0,-5288(9); 15:; sth 0,0x0(29); 16:; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801D0864_0();
extern "C" void _s801D0864_1();
extern "C" void _s801D0864_2();
extern "C" void _s801D0864_3();
extern "C" void _s801D0864_4();
extern "C" void _s801D0864_5();
extern "C" void _s801D0864_6();
extern "C" void _s801D0864_7();
extern "C" void _s801D0864_8();
extern "C" void _s801D0864_9();
extern "C" void _s801D0864_10();
extern "C" void _s801D0864_11();
extern "C" void f_801D0864() {}
