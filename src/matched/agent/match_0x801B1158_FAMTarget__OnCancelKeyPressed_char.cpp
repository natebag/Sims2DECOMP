// 0x801B1158 FAMTarget::OnCancelKeyPressed(char (644 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; mfcr 12; stmw 28,0x48(1); stw 0,0x5c(1); stw 12,0x44(1); mr 31,3; lwz 29,0x88(31); cmpwi 29,0; bne 9f; li 0,2; stw 29,0xd0(31); lis 28,-32697; lis 5,-32705; addi 4,28,24012; stw 0,0xc4(31); addi 5,5,-1340; addi 3,1,24; crxor 6,6,6; bl _s801B1158_0; addi 30,31,244; lwz 9,0x18(1); li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; mr 3,30; bl _s801B1158_1; addi 30,31,248; lis 5,-32705; lis 4,-32697; addi 4,4,24012; addi 5,5,-1344; addi 3,1,28; crxor 6,6,6; bl _s801B1158_2; lwz 9,0x1c(1); li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x0(9); 1:; mr 3,30; bl _s801B1158_3; addi 30,31,236; lis 5,-32705; addi 4,28,24012; addi 5,5,1716; addi 3,1,32; crxor 6,6,6; bl _s801B1158_4; lwz 9,0x20(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,30; cmpwi 4,31,0; bl _s801B1158_5; lis 4,-32705; addi 3,31,240; addi 4,4,-8284; bl _s801B1158_6; lis 9,-32705; stw 29,0xd8(31); addi 9,9,1736; lis 10,-32709; lwz 11,0x0(9); lwz 12,0x4(9); addi 4,1,40; addi 30,10,28880; stw 11,0x28(1); stw 12,0x2c(1); stw 29,0xe4(31); stw 31,0x10(1); beq cr4,3f; addi 3,1,8; li 5,8; bl _s801B1158_7; b 4f; 3:; stw 31,0x8(1); 4:; stw 30,0x14(1); lis 9,-32705; addi 11,1,8; lwz 4,0x8(1); addi 9,9,1744; lwz 5,0x4(11); lwz 6,0x8(11); addi 10,31,276; lwz 0,0xc(11); mr 30,11; lwz 7,0x0(9); lwz 8,0x4(9); stw 4,0x114(31); lis 9,-32709; stw 0,0xc(10); addi 29,9,28640; stw 5,0x4(10); addi 9,1,48; stw 6,0x8(10); stw 7,0x30(1); stw 8,0x34(1); stw 31,0x10(1); beq cr4,5f; mr 4,9; mr 3,30; li 5,8; bl _s801B1158_8; b 6f; 5:; stw 31,0x8(1); 6:; stw 29,0x14(1); lis 9,-32705; lwz 5,0x8(1); addi 9,9,-1960; lwz 4,0x8(30); addi 11,31,292; lwz 6,0x4(30); addi 0,31,196; lwz 10,0xc(30); mr 29,0; lwz 7,0x0(9); lwz 8,0x4(9); cmpwi 0,0; stw 5,0x124(31); lis 9,-32709; stw 10,0xc(11); addi 28,9,14552; stw 6,0x4(11); addi 9,1,56; stw 4,0x8(11); stw 7,0x38(1); stw 8,0x3c(1); stw 0,0x10(1); beq 7f; mr 4,9; mr 3,30; li 5,8; bl _s801B1158_9; b 8f; 7:; stw 29,0x8(1); 8:; stw 28,0x14(1); addi 9,31,308; lwz 8,0x8(1); mr 3,29; lwz 0,0xc(30); lwz 11,0x4(30); lwz 10,0x8(30); stw 8,0x134(31); stw 0,0xc(9); stw 11,0x4(9); stw 10,0x8(9); bl _s801B1158_10; b 10f; 9:; mr 3,31; bl _s801B1158_11; 10:; lwz 0,0x5c(1); lwz 12,0x44(1); mtspr 8,0; lmw 28,0x48(1); mtcrf 8,12; addi 1,1,88"
extern "C" void _s801B1158_0();
extern "C" void _s801B1158_1();
extern "C" void _s801B1158_2();
extern "C" void _s801B1158_3();
extern "C" void _s801B1158_4();
extern "C" void _s801B1158_5();
extern "C" void _s801B1158_6();
extern "C" void _s801B1158_7();
extern "C" void _s801B1158_8();
extern "C" void _s801B1158_9();
extern "C" void _s801B1158_10();
extern "C" void _s801B1158_11();
extern "C" void f_801B1158() {}
