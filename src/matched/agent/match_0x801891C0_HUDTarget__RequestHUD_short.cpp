// 0x801891C0 HUDTarget::RequestHUD(short, (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 31,3; mr 30,4; lhz 0,0xc8(31); mr 28,5; mr 29,6; cmpw 0,30; bne 0f; lhz 0,0xca(31); li 3,1; cmpw 0,28; beq 4f; 0:; mr 3,31; bl _s801891C0_0; cmpwi 30,0; beq 1f; stw 29,0x104(31); b 2f; 1:; stw 30,0x104(31); 2:; rlwinm 0,30,0,16,31; sth 30,0xc8(31); cmpwi 0,0; li 0,0; beq 3f; mr 0,28; 3:; addi 28,1,8; lis 30,-32705; lwz 5,0x104(31); addi 4,30,-19956; sth 0,0xca(31); mr 3,28; crxor 6,6,6; bl _s801891C0_1; addi 29,1,16; lhz 5,0xc8(31); addi 4,30,-19956; mr 3,29; crxor 6,6,6; bl _s801891C0_2; lwz 3,-25136(13); lis 4,-32705; addi 4,4,-19472; mr 8,28; mr 9,29; li 5,0; li 6,0; li 7,2; crxor 6,6,6; bl _s801891C0_3; li 3,1; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"
extern "C" void _s801891C0_0();
extern "C" void _s801891C0_1();
extern "C" void _s801891C0_2();
extern "C" void _s801891C0_3();
extern "C" void f_801891C0() {}
