// 0x801FEE80 PDATarget::HandleButtonHelpMessage(int, (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 28,4; mr 31,3; mr. 4,5; beq 5f; lis 29,-32697; addi 3,29,24012; bl _s801FEE80_0; mr. 30,3; beq 5f; lwz 9,0x4(30); addi 3,31,176; li 4,0; cmpwi 9,0; beq 0f; lwz 4,0x0(9); 0:; bl _s801FEE80_1; lwz 3,0x8(30); addi 0,31,172; li 4,0; cmpwi 3,0; beq 1f; lwz 4,0x0(3); 1:; mr 3,0; addi 30,31,180; bl _s801FEE80_2; lis 5,-32704; addi 4,29,24012; addi 5,5,-19712; addi 3,1,8; crxor 6,6,6; bl _s801FEE80_3; lwz 9,0x8(1); li 4,0; cmpwi 9,0; beq 2f; lwz 4,0x0(9); 2:; mr 3,30; bl _s801FEE80_4; lis 30,-32704; addi 4,30,-32388; addi 3,31,184; bl _s801FEE80_5; addi 4,30,-32388; addi 3,31,188; bl _s801FEE80_6; li 11,1; li 9,0; li 0,3; stw 9,0x90(31); stw 0,0x8c(31); cmpwi 28,0; stw 11,0x84(31); stw 9,0x88(31); stw 11,0x94(31); stw 11,0x98(31); bne 3f; stw 11,0xd0(31); b 4f; 3:; li 0,2; stw 0,0xd0(31); 4:; li 0,1; stw 0,0x168(31); stw 0,0xa8(31); 5:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s801FEE80_0();
extern "C" void _s801FEE80_1();
extern "C" void _s801FEE80_2();
extern "C" void _s801FEE80_3();
extern "C" void _s801FEE80_4();
extern "C" void _s801FEE80_5();
extern "C" void _s801FEE80_6();
extern "C" void f_801FEE80() {}
