// 0x801F6CA0 INVTarget::GetSelectedShoppingItem(int, (488 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 30,4; mr 29,6; mr 28,5; bl _s801F6CA0_0; lwz 9,0x178(31); rlwinm 3,3,3,0,28; lwzx 11,9,3; stw 11,0x0(29); cmpwi 11,9; lwz 9,0x178(31); add 9,9,3; lwz 0,0x4(9); mulli 0,0,12; add 10,0,30; beq 0f; blt 7f; cmpwi 11,10; beq 3f; cmpwi 11,11; beq 4f; b 7f; 0:; cmpwi 7,10,0; bne cr7,1f; li 0,-1; stw 10,0x8(1); stw 0,0xc(1); li 3,1; lwz 9,0x8(1); lwz 10,0xc(1); stw 9,0x0(28); stw 10,0x4(28); b 12f; 1:; lwz 9,0x164(31); lwz 11,0x0(9); lwz 0,0x4(9); subf 0,11,0; srawi 3,0,3; cmpw 10,3; bge 8f; blt cr7,8f; addi 0,10,-1; cmplw 0,3; blt 2f; lis 3,-32704; addi 3,3,-26048; bl _s801F6CA0_1; bl _s801F6CA0_2; 2:; rlwinm 9,0,3,0,28; b 6f; 3:; lwz 9,0x168(31); lwz 11,0x0(9); lwz 0,0x4(9); subf 0,11,0; srawi 0,0,3; cmpw 10,0; bge 8f; cmpwi 10,0; blt 8f; cmplw 10,0; blt 5f; lis 3,-32704; addi 3,3,-26048; bl _s801F6CA0_3; bl _s801F6CA0_4; 4:; lwz 9,0x16c(31); lwz 11,0x0(9); lwz 0,0x4(9); subf 0,11,0; srawi 0,0,3; cmpw 10,0; bge 8f; cmpwi 10,0; blt 8f; cmplw 10,0; blt 5f; lis 3,-32704; addi 3,3,-26048; bl _s801F6CA0_5; bl _s801F6CA0_6; 5:; rlwinm 9,10,3,0,28; 6:; add 9,11,9; lwz 11,0x0(9); lwz 12,0x4(9); stw 11,0x0(28); stw 12,0x4(28); b 11f; 7:; lwz 0,0x0(29); cmplwi 0,14; bgt 8f; rlwinm 0,0,2,0,29; addi 9,31,320; lwzx 11,9,0; lwz 8,0x0(11); lwz 0,0x4(11); subf 0,8,0; srawi 0,0,2; cmpw 10,0; bge 8f; cmpwi 10,0; bge 9f; 8:; li 3,0; b 12f; 9:; cmplw 10,0; blt 10f; lis 3,-32704; addi 3,3,-26048; bl _s801F6CA0_7; bl _s801F6CA0_8; 10:; rlwinm 9,10,2,0,29; lwzx 0,8,9; stw 0,0x0(28); 11:; li 3,1; 12:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s801F6CA0_0();
extern "C" void _s801F6CA0_1();
extern "C" void _s801F6CA0_2();
extern "C" void _s801F6CA0_3();
extern "C" void _s801F6CA0_4();
extern "C" void _s801F6CA0_5();
extern "C" void _s801F6CA0_6();
extern "C" void _s801F6CA0_7();
extern "C" void _s801F6CA0_8();
extern "C" void f_801F6CA0() {}
