// 0x800211C8 ECheatLookup::WriteCheat(EFile (600 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-280(1); mfspr 0,8; stmw 28,0x108(1); stw 0,0x11c(1); mr 31,3; li 0,0; lwz 9,0x4c(31); mr 30,4; mr 28,5; stb 0,0x8(1); cmpwi 9,4; beq 4f; bgt 0f; cmpwi 9,2; beq 1f; bgt 2f; cmpwi 9,1; beq 7f; b 8f; 0:; cmpwi 9,6; beq 7f; blt 5f; cmpwi 9,7; beq 3f; b 8f; 1:; lwz 9,0x50(31); lis 4,-32707; addi 4,4,852; addi 3,1,8; lwz 6,0x0(9); b 6f; 2:; lwz 9,0x50(31); lis 4,-32707; addi 4,4,852; addi 3,1,8; lbz 6,0x0(9); b 6f; 3:; lwz 9,0x50(31); lis 4,-32707; addi 4,4,860; addi 3,1,8; lfs f1,0x0(9); addi 5,31,8; creqv 6,6,6; bl _s800211C8_0; b 8f; 4:; lwz 9,0x50(31); lis 4,-32707; addi 4,4,852; addi 3,1,8; lbz 6,0x0(9); addi 5,31,8; extsb 6,6; crxor 6,6,6; bl _s800211C8_1; b 8f; 5:; lwz 9,0x50(31); lis 4,-32707; addi 4,4,852; addi 3,1,8; lha 6,0x0(9); 6:; addi 5,31,8; crxor 6,6,6; bl _s800211C8_2; b 8f; 7:; lis 4,-32707; lwz 6,0x50(31); addi 4,4,868; addi 3,1,8; addi 5,31,8; crxor 6,6,6; bl _s800211C8_3; 8:; lwz 9,0x48(31); lis 29,-32707; cmpwi 9,0; beq 13f; lbz 0,0x0(9); cmpwi 0,0; beq 13f; addi 3,1,8; bl _s800211C8_4; subfic 0,3,51; srawi. 0,0,2; bne 9f; li 0,1; 9:; cmpwi 0,0; ble 12f; li 9,0; addi 10,1,8; mtspr 9,9; cmpw 9,0; bge 11f; mtspr 9,0; li 11,9; add 9,3,10; 10:; stb 11,0x0(9); addi 9,9,1; bdnz 10b; mtspr 9,0; 11:; mfspr 0,9; add 9,3,0; li 0,0; stbx 0,10,9; 12:; lis 4,-32707; addi 3,1,8; addi 4,4,876; bl _s800211C8_5; lwz 4,0x48(31); addi 3,1,8; bl _s800211C8_6; 13:; lis 4,-32707; addi 3,1,8; addi 4,4,880; bl _s800211C8_7; addi 3,1,8; bl _s800211C8_8; mr. 3,3; beq 14f; lwz 9,0x28(30); mr 5,3; addi 4,1,8; lha 3,0x20(9); lwz 0,0x24(9); add 3,30,3; mtspr 8,0; blrl; 14:; lwz 0,0x58(31); cmpwi 0,0; beq 15f; addi 4,29,880; addi 3,1,8; crxor 6,6,6; bl _s800211C8_9; addi 3,1,8; bl _s800211C8_10; lwz 9,0x28(30); mr 5,3; addi 4,1,8; lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,30,3; blrl; li 0,0; stw 0,0x0(28); 15:; lwz 0,0x11c(1); mtspr 8,0; lmw 28,0x108(1); addi 1,1,280"
extern "C" void _s800211C8_0();
extern "C" void _s800211C8_1();
extern "C" void _s800211C8_2();
extern "C" void _s800211C8_3();
extern "C" void _s800211C8_4();
extern "C" void _s800211C8_5();
extern "C" void _s800211C8_6();
extern "C" void _s800211C8_7();
extern "C" void _s800211C8_8();
extern "C" void _s800211C8_9();
extern "C" void _s800211C8_10();
extern "C" void f_800211C8() {}
