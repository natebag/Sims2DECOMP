// 0x801AD8A0 E2ETarget::OnRightKeyPressed(char (476 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-272(1); mfspr 0,8; stw 31,0x10c(1); stw 0,0x114(1); mr 31,3; lwz 0,0xa8(31); cmpwi 0,2; bne 0f; bl _s801AD8A0_0; lis 9,-32705; lis 4,-32705; lfs f0,-1744(9); addi 4,4,-2240; addi 3,1,8; fadds f1,f1,f0; creqv 6,6,6; bl _s801AD8A0_1; lwz 9,0x80(31); addi 5,1,8; lwz 4,-30576(13); b 5f; 0:; cmpwi 0,3; bne 1f; bl _s801AD8A0_2; lis 9,-32705; lis 4,-32705; lfs f0,-1740(9); addi 4,4,-2240; addi 3,1,8; fadds f1,f1,f0; creqv 6,6,6; bl _s801AD8A0_3; lwz 9,0x80(31); addi 5,1,8; lwz 4,-30568(13); b 5f; 1:; cmpwi 0,4; bne 2f; bl _s801AD8A0_4; lis 9,-32705; lis 4,-32705; lfs f0,-1740(9); addi 4,4,-2240; addi 3,1,8; fadds f1,f1,f0; creqv 6,6,6; bl _s801AD8A0_5; lwz 9,0x80(31); addi 5,1,8; lwz 4,-30572(13); b 5f; 2:; cmpwi 0,5; bne 3f; bl _s801AD8A0_6; lis 9,-32705; lis 4,-32705; lfs f0,-1740(9); addi 4,4,-2240; addi 3,1,8; fadds f1,f1,f0; creqv 6,6,6; bl _s801AD8A0_7; lwz 9,0x80(31); addi 5,1,8; lwz 4,-30564(13); b 5f; 3:; cmpwi 0,6; bne 4f; lwz 5,0xbc(31); lis 4,-32705; addi 4,4,-8800; addi 3,1,8; addi 5,5,1; crxor 6,6,6; bl _s801AD8A0_8; lwz 9,0x80(31); addi 5,1,8; lwz 4,-30532(13); b 5f; 4:; cmpwi 0,7; bne 6f; lwz 5,0xc4(31); lis 4,-32705; addi 4,4,-8800; addi 3,1,8; addi 5,5,1; crxor 6,6,6; bl _s801AD8A0_9; lwz 9,0x80(31); addi 5,1,8; lwz 4,-30528(13); 5:; lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; b 7f; 6:; cmpwi 0,8; bne 7f; lwz 5,0xc0(31); lis 4,-32705; addi 4,4,-8800; addi 3,1,8; addi 5,5,1; crxor 6,6,6; bl _s801AD8A0_10; lwz 9,0x80(31); addi 5,1,8; lwz 4,-30536(13); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; 7:; lwz 0,0x114(1); mtspr 8,0; lwz 31,0x10c(1); addi 1,1,272"
extern "C" void _s801AD8A0_0();
extern "C" void _s801AD8A0_1();
extern "C" void _s801AD8A0_2();
extern "C" void _s801AD8A0_3();
extern "C" void _s801AD8A0_4();
extern "C" void _s801AD8A0_5();
extern "C" void _s801AD8A0_6();
extern "C" void _s801AD8A0_7();
extern "C" void _s801AD8A0_8();
extern "C" void _s801AD8A0_9();
extern "C" void _s801AD8A0_10();
extern "C" void f_801AD8A0() {}
