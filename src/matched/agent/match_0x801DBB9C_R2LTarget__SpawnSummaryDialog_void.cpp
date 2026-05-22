// 0x801DBB9C R2LTarget::SpawnSummaryDialog(void) (676 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; mfcr 12; stmw 28,0x48(1); stw 0,0x5c(1); stw 12,0x44(1); mr 31,3; lwz 0,0x94(31); cmpwi 0,0; li 0,2; bne 0f; li 0,1; 0:; stw 0,0x108(31); li 29,1; lis 28,-32697; stw 29,0xbc(31); lis 5,-32705; stw 29,0xd8(31); addi 4,28,24012; addi 5,5,-1988; addi 3,1,24; crxor 6,6,6; bl _s801DBB9C_0; addi 30,31,236; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; mr 3,30; bl _s801DBB9C_1; addi 30,31,228; lis 5,-32705; lis 4,-32697; addi 4,4,24012; addi 5,5,20504; addi 3,1,28; crxor 6,6,6; bl _s801DBB9C_2; lwz 9,0x1c(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,30; bl _s801DBB9C_3; addi 30,31,232; lis 5,-32705; addi 4,28,24012; addi 5,5,20528; addi 3,1,32; crxor 6,6,6; bl _s801DBB9C_4; lwz 9,0x20(1); li 4,0; cmpwi 9,0; beq 3f; lwz 4,0x0(9); 3:; mr 3,30; cmpwi 4,31,0; bl _s801DBB9C_5; lis 30,-32705; addi 4,30,-8284; addi 3,31,240; bl _s801DBB9C_6; addi 4,30,-8284; addi 3,31,244; bl _s801DBB9C_7; lis 9,-32705; li 11,0; addi 9,9,20544; li 0,3; lwz 7,0x0(9); lwz 8,0x4(9); addi 4,1,40; stw 0,0xc4(31); lis 9,-32708; stw 29,0xd0(31); addi 30,9,-25040; stw 11,0xe0(31); stw 7,0x28(1); stw 8,0x2c(1); stw 29,0xbc(31); stw 11,0xc0(31); stw 29,0xcc(31); stw 11,0xc8(31); stw 31,0x10(1); beq cr4,4f; addi 3,1,8; li 5,8; bl _s801DBB9C_8; b 5f; 4:; stw 31,0x8(1); 5:; stw 30,0x14(1); lis 9,-32705; addi 11,1,8; lwz 4,0x8(1); addi 9,9,20552; lwz 5,0x4(11); lwz 6,0x8(11); addi 10,31,268; lwz 0,0xc(11); mr 30,11; lwz 7,0x0(9); lwz 8,0x4(9); stw 4,0x10c(31); lis 9,-32708; stw 0,0xc(10); addi 29,9,-25280; stw 5,0x4(10); addi 9,1,48; stw 6,0x8(10); stw 7,0x30(1); stw 8,0x34(1); stw 31,0x10(1); beq cr4,6f; mr 4,9; mr 3,30; li 5,8; bl _s801DBB9C_9; b 7f; 6:; stw 31,0x8(1); 7:; stw 29,0x14(1); lis 9,-32705; lwz 6,0x8(1); addi 9,9,20560; lwz 5,0x8(30); addi 11,31,284; lwz 10,0x4(30); addi 4,1,56; lwz 0,0xc(30); stw 6,0x11c(31); lwz 7,0x0(9); lwz 8,0x4(9); stw 0,0xc(11); lis 9,-32708; stw 10,0x4(11); addi 29,9,-25280; stw 5,0x8(11); stw 7,0x38(1); stw 8,0x3c(1); stw 31,0x10(1); beq cr4,8f; mr 3,30; li 5,8; bl _s801DBB9C_10; b 9f; 8:; stw 31,0x8(1); 9:; stw 29,0x14(1); addi 9,31,300; lwz 8,0x8(1); li 7,1; lwz 10,0xc(30); addi 3,31,188; lwz 0,0x4(30); lwz 11,0x8(30); stw 8,0x12c(31); stw 10,0xc(9); stw 0,0x4(9); stw 11,0x8(9); stw 7,0xb8(31); bl _s801DBB9C_11; lwz 0,0x5c(1); lwz 12,0x44(1); mtspr 8,0; lmw 28,0x48(1); mtcrf 8,12; addi 1,1,88"
extern "C" void _s801DBB9C_0();
extern "C" void _s801DBB9C_1();
extern "C" void _s801DBB9C_2();
extern "C" void _s801DBB9C_3();
extern "C" void _s801DBB9C_4();
extern "C" void _s801DBB9C_5();
extern "C" void _s801DBB9C_6();
extern "C" void _s801DBB9C_7();
extern "C" void _s801DBB9C_8();
extern "C" void _s801DBB9C_9();
extern "C" void _s801DBB9C_10();
extern "C" void _s801DBB9C_11();
extern "C" void f_801DBB9C() {}
