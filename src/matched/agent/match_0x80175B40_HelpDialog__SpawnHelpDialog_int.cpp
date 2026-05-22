// 0x80175B40 HelpDialog::SpawnHelpDialog(int, (924 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; mfcr 12; stmw 27,0x4c(1); stw 0,0x64(1); stw 12,0x48(1); mr 31,3; mr 27,4; lwz 11,0x88(31); mr 29,6; mr 28,9; cmpwi 11,0; beq 0f; li 3,0; b 21f; 0:; li 0,1; stw 7,0x8c(31); stw 0,0x88(31); cmpwi 4,8,0; sth 11,0x48(31); sth 11,0x4a(31); beq cr4,2f; lis 4,-32697; addi 3,1,24; addi 4,4,24012; addi 30,31,44; crxor 6,6,6; bl _s80175B40_0; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; mr 3,30; bl _s80175B40_1; b 4f; 2:; lis 4,-32697; addi 3,1,28; addi 4,4,24012; addi 30,31,44; crxor 6,6,6; bl _s80175B40_2; lwz 9,0x1c(1); li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; mr 3,30; bl _s80175B40_3; 4:; beq cr4,6f; lis 4,-32697; mr 5,29; addi 4,4,24012; addi 3,1,32; crxor 6,6,6; bl _s80175B40_4; addi 30,31,40; lwz 9,0x20(1); li 4,0; cmpwi 9,0; beq 5f; lwz 4,0x0(9); 5:; mr 3,30; bl _s80175B40_5; b 8f; 6:; lis 4,-32697; mr 5,29; addi 4,4,24012; addi 3,1,36; crxor 6,6,6; bl _s80175B40_6; addi 30,31,40; lwz 9,0x24(1); li 4,0; cmpwi 9,0; beq 7f; lwz 4,0x0(9); 7:; mr 3,30; bl _s80175B40_7; 8:; cmpwi 28,0; bne 10f; lis 4,-32697; lis 5,-32706; addi 4,4,24012; addi 5,5,8820; addi 3,1,40; addi 30,31,48; crxor 6,6,6; bl _s80175B40_8; lwz 9,0x28(1); li 4,0; cmpwi 9,0; beq 9f; lwz 4,0x0(9); 9:; mr 3,30; bl _s80175B40_9; li 0,1; b 12f; 10:; lis 4,-32697; mr 5,28; addi 4,4,24012; addi 3,1,44; crxor 6,6,6; bl _s80175B40_10; addi 30,31,48; lwz 9,0x2c(1); li 4,0; cmpwi 9,0; beq 11f; lwz 4,0x0(9); 11:; mr 3,30; bl _s80175B40_11; li 0,0; 12:; stw 0,0x24(31); lis 30,-32706; addi 3,31,52; addi 4,30,8816; bl _s80175B40_12; addi 4,30,8816; addi 3,31,56; bl _s80175B40_13; li 11,1; li 9,0; li 0,3; stw 9,0xc(31); stw 0,0x8(31); cmpwi 27,0; stw 11,0x0(31); stw 9,0x4(31); stw 11,0x10(31); stw 11,0x14(31); bne 13f; stw 11,0x4c(31); b 14f; 13:; li 0,2; stw 0,0x4c(31); 14:; lis 9,-32706; lis 11,-32709; addi 9,9,8832; addi 30,11,3884; lwz 7,0x0(9); lwz 8,0x4(9); addi 4,1,48; stw 31,0x10(1); cmpwi 4,31,0; stw 7,0x30(1); stw 8,0x34(1); beq cr4,15f; addi 3,1,8; li 5,8; bl _s80175B40_14; b 16f; 15:; stw 31,0x8(1); 16:; stw 30,0x14(1); lis 9,-32706; addi 11,1,8; lwz 4,0x8(1); addi 9,9,8840; lwz 5,0x4(11); lwz 6,0x8(11); addi 10,31,80; lwz 0,0xc(11); mr 30,11; lwz 7,0x0(9); lwz 8,0x4(9); stw 4,0x50(31); lis 9,-32709; stw 0,0xc(10); addi 29,9,4004; stw 5,0x4(10); addi 9,1,56; stw 6,0x8(10); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq cr4,17f; mr 4,9; mr 3,30; li 5,8; bl _s80175B40_15; b 18f; 17:; stw 31,0x8(1); 18:; stw 29,0x14(1); lis 9,-32706; lwz 6,0x8(1); addi 9,9,8848; lwz 5,0x8(30); addi 11,31,96; lwz 10,0x4(30); addi 4,1,64; lwz 0,0xc(30); stw 6,0x60(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32709; stw 10,0x4(11); addi 29,9,4004; stw 5,0x8(11); stw 7,0x40(1); stw 8,0x44(1); stw 31,0x10(1); beq cr4,19f; mr 3,30; li 5,8; bl _s80175B40_16; b 20f; 19:; stw 31,0x8(1); 20:; stw 29,0x14(1); addi 11,31,112; lwz 7,0x8(1); lis 9,-32706; lwz 8,0xc(30); addi 9,9,8856; lwz 10,0x4(30); mr 3,31; lwz 0,0x8(30); stw 7,0x70(31); stw 8,0xc(11); stw 10,0x4(11); stw 0,0x8(11); stw 9,0x80(31); bl _s80175B40_17; li 3,1; 21:; lwz 0,0x64(1); lwz 12,0x48(1); mtspr 8,0; lmw 27,0x4c(1); mtcrf 8,12; addi 1,1,96"
extern "C" void _s80175B40_0();
extern "C" void _s80175B40_1();
extern "C" void _s80175B40_2();
extern "C" void _s80175B40_3();
extern "C" void _s80175B40_4();
extern "C" void _s80175B40_5();
extern "C" void _s80175B40_6();
extern "C" void _s80175B40_7();
extern "C" void _s80175B40_8();
extern "C" void _s80175B40_9();
extern "C" void _s80175B40_10();
extern "C" void _s80175B40_11();
extern "C" void _s80175B40_12();
extern "C" void _s80175B40_13();
extern "C" void _s80175B40_14();
extern "C" void _s80175B40_15();
extern "C" void _s80175B40_16();
extern "C" void _s80175B40_17();
extern "C" void f_80175B40() {}
