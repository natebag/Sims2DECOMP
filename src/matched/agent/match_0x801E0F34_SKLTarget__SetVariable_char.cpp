// 0x801E0F34 SKLTarget::SetVariable(char (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 31,4; mr 30,3; lbz 3,0x0(31); extsb 3,3; bl _s801E0F34_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; lwz 3,-29584(13); mr 4,31; bl _s801E0F34_1; mr. 3,3; bne 1f; li 0,1; stw 3,0x98(30); stw 0,0xa0(30); b 4f; 1:; lwz 3,-29572(13); mr 4,31; bl _s801E0F34_2; mr. 29,3; bne 2f; addi 3,1,8; bl _s801E0F34_3; lis 4,-32705; lwz 6,0x94(30); addi 4,4,23000; addi 3,1,8; li 5,0; bl _s801E0F34_4; stw 29,0xa0(30); addi 3,1,8; stw 29,0x98(30); li 4,2; bl _s801E0F34_5; b 4f; 2:; lwz 3,-29560(13); mr 4,31; bl _s801E0F34_6; mr. 3,3; bne 3f; stw 3,0x8c(30); b 4f; 3:; lwz 3,-29548(13); mr 4,31; bl _s801E0F34_7; mr. 31,3; bne 4f; stw 31,0x8c(30); addi 3,1,8; bl _s801E0F34_8; lis 4,-32705; lwz 6,0x94(30); addi 4,4,23028; addi 3,1,8; li 5,0; bl _s801E0F34_9; stw 31,0x88(30); addi 3,1,8; li 4,2; bl _s801E0F34_10; 4:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"
extern "C" void _s801E0F34_0();
extern "C" void _s801E0F34_1();
extern "C" void _s801E0F34_2();
extern "C" void _s801E0F34_3();
extern "C" void _s801E0F34_4();
extern "C" void _s801E0F34_5();
extern "C" void _s801E0F34_6();
extern "C" void _s801E0F34_7();
extern "C" void _s801E0F34_8();
extern "C" void _s801E0F34_9();
extern "C" void _s801E0F34_10();
extern "C" void f_801E0F34() {}
