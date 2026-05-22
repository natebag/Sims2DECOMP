// 0x801960F8 CASTarget::SpawnOKDialog(unsigned (564 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; mfcr 12; stmw 28,0x40(1); stw 0,0x54(1); stw 12,0x3c(1); mr 31,3; mr 29,4; mr 28,5; li 4,0; addi 30,31,5068; bl _s801960F8_0; li 0,1; lis 4,-32697; lis 5,-32705; addi 4,4,24012; stw 0,0x139c(31); addi 5,5,-15276; stw 0,0x13a8(31); addi 3,1,24; crxor 6,6,6; bl _s801960F8_1; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; cmpwi 4,31,0; bl _s801960F8_2; mr 4,29; addi 3,31,5060; bl _s801960F8_3; mr 4,28; addi 3,31,5064; bl _s801960F8_4; lis 9,-32705; li 0,0; addi 9,9,-15272; stw 0,0x13bc(31); lwz 7,0x0(9); lwz 8,0x4(9); lis 11,-32709; addi 4,1,32; addi 30,11,14432; stw 7,0x20(1); stw 8,0x24(1); stw 31,0x10(1); beq cr4,1f; addi 3,1,8; li 5,8; bl _s801960F8_5; b 2f; 1:; stw 31,0x8(1); 2:; stw 30,0x14(1); lis 9,-32705; addi 11,1,8; lwz 4,0x8(1); addi 9,9,-15292; lwz 5,0x4(11); lwz 6,0x8(11); addi 10,31,5100; lwz 0,0xc(11); mr 30,11; lwz 7,0x0(9); lwz 8,0x4(9); stw 4,0x13ec(31); lis 9,-32709; stw 0,0xc(10); addi 29,9,14192; stw 5,0x4(10); addi 9,1,40; stw 6,0x8(10); stw 7,0x28(1); stw 8,0x2c(1); stw 31,0x10(1); beq cr4,3f; mr 4,9; mr 3,30; li 5,8; bl _s801960F8_6; b 4f; 3:; stw 31,0x8(1); 4:; stw 29,0x14(1); lis 9,-32705; lwz 5,0x8(1); addi 9,9,-15284; lwz 4,0x8(30); addi 11,31,5116; lwz 6,0x4(30); addi 0,31,5020; lwz 10,0xc(30); mr 29,0; lwz 7,0x0(9); lwz 8,0x4(9); cmpwi 0,0; stw 5,0x13fc(31); lis 9,-32709; stw 10,0xc(11); addi 28,9,14552; stw 6,0x4(11); addi 9,1,48; stw 4,0x8(11); stw 7,0x30(1); stw 8,0x34(1); stw 0,0x10(1); beq 5f; mr 4,9; mr 3,30; li 5,8; bl _s801960F8_7; b 6f; 5:; stw 29,0x8(1); 6:; stw 28,0x14(1); addi 9,31,5132; lwz 0,0x8(1); lwz 11,0xc(30); lwz 10,0x4(30); lwz 8,0x8(30); stw 0,0x140c(31); stw 11,0xc(9); stw 10,0x4(9); stw 8,0x8(9); lwz 0,0x1360(31); cmpwi 0,0; bne 7f; li 0,1; b 8f; 7:; cmpwi 0,1; bne 9f; li 0,2; 8:; stw 0,0x13e8(31); 9:; mr 3,29; bl _s801960F8_8; lwz 0,0x54(1); lwz 12,0x3c(1); mtspr 8,0; lmw 28,0x40(1); mtcrf 8,12; addi 1,1,80"
extern "C" void _s801960F8_0();
extern "C" void _s801960F8_1();
extern "C" void _s801960F8_2();
extern "C" void _s801960F8_3();
extern "C" void _s801960F8_4();
extern "C" void _s801960F8_5();
extern "C" void _s801960F8_6();
extern "C" void _s801960F8_7();
extern "C" void _s801960F8_8();
extern "C" void f_801960F8() {}
