// 0x801C1AA0 M2MTarget::GetItemTextMemCardSelect(int, (328 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,3; cmpwi 4,1; mr 29,5; beq 3f; bgt 0f; cmpwi 4,0; beq 1f; b 7f; 0:; cmpwi 4,2; beq 5f; b 7f; 1:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,8992; addi 3,1,8; addi 30,31,312; crxor 6,6,6; bl _s801C1AA0_0; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,30; bl _s801C1AA0_1; li 30,0; b 8f; 3:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,9024; addi 3,1,12; addi 30,31,316; crxor 6,6,6; bl _s801C1AA0_2; lwz 9,0xc(1); li 4,0; cmpwi 9,0; beq 4f; lwz 4,0x0(9); 4:; mr 3,30; bl _s801C1AA0_3; li 30,4; b 8f; 5:; lis 4,-32697; addi 3,1,16; addi 4,4,24012; li 5,0; crxor 6,6,6; bl _s801C1AA0_4; addi 30,31,320; lwz 9,0x10(1); li 4,0; cmpwi 9,0; beq 6f; lwz 4,0x0(9); 6:; mr 3,30; bl _s801C1AA0_5; li 30,8; b 8f; 7:; rlwinm 30,4,2,0,29; lis 4,-32705; addi 3,30,312; addi 4,4,-8284; add 3,31,3; bl _s801C1AA0_6; 8:; addi 3,30,312; add 3,31,3; bl _s801C1AA0_7; mr 4,3; mr 3,29; bl _s801C1AA0_8; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s801C1AA0_0();
extern "C" void _s801C1AA0_1();
extern "C" void _s801C1AA0_2();
extern "C" void _s801C1AA0_3();
extern "C" void _s801C1AA0_4();
extern "C" void _s801C1AA0_5();
extern "C" void _s801C1AA0_6();
extern "C" void _s801C1AA0_7();
extern "C" void _s801C1AA0_8();
extern "C" void f_801C1AA0() {}
