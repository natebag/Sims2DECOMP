// 0x801A3EB4 BBHTarget::UpdateBuildBuyHUD(void) (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-544(1); mfspr 0,8; stmw 29,0x214(1); stw 0,0x224(1); lis 9,-32697; mr 29,3; lwz 0,0x5e88(9); cmpwi 0,0; beq 1f; lwz 11,-21496(13); li 4,0; lwz 9,0x0(11); lwz 0,0xa4(9); lha 3,0xa0(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,-30764(13); mr 31,3; cmpw 0,31; beq 0f; addi 30,1,8; li 5,256; addi 4,30,8; mr 3,30; bl _s801A3EB4_0; mr 4,30; mr 3,31; li 5,0; bl _s801A3EB4_1; mr 3,30; bl _s801A3EB4_2; mr 4,3; lis 3,-32705; addi 3,3,-8360; bl _s801A3EB4_3; 0:; lwz 0,-30764(13); cmpw 31,0; beq 1f; addi 3,1,8; stw 31,-30764(13); bl _s801A3EB4_4; lis 4,-32705; addi 3,1,8; addi 4,4,-8348; li 6,0; li 5,12; bl _s801A3EB4_5; addi 3,1,8; li 4,2; bl _s801A3EB4_6; 1:; lwz 0,0x84(29); cmpwi 0,0; beq 2f; lwz 0,0x90(29); cmpwi 0,0; beq 2f; lwz 3,0xa4(29); bl _s801A3EB4_7; 2:; lwz 0,0x224(1); mtspr 8,0; lmw 29,0x214(1); addi 1,1,544"
extern "C" void _s801A3EB4_0();
extern "C" void _s801A3EB4_1();
extern "C" void _s801A3EB4_2();
extern "C" void _s801A3EB4_3();
extern "C" void _s801A3EB4_4();
extern "C" void _s801A3EB4_5();
extern "C" void _s801A3EB4_6();
extern "C" void _s801A3EB4_7();
extern "C" void f_801A3EB4() {}
