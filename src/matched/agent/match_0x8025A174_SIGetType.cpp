// 0x8025A174 SIGetType (452 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-40(1); stmw 27,0x14(1); mr 27,3; bl _s8025A174_0; lis 4,-32700; rlwinm 5,27,2,0,29; addi 0,4,-15952; add 30,0,5; lwz 28,0x0(30); mr 29,3; bl _s8025A174_1; lis 5,-32694; rlwinm 6,27,3,0,28; addi 0,5,-21584; add 31,0,6; lwz 6,0x4(31); lis 5,-32700; addi 5,5,-15972; lwz 0,0x0(31); subfc 4,6,4; subfe 0,0,3; lwz 6,0x4(5); li 5,128; sraw 3,5,27; and. 3,6,3; beq 1f; cmplwi 28,8; beq 0f; bl _s8025A174_2; stw 4,0x4(31); stw 3,0x0(31); mr 3,29; bl _s8025A174_3; mr 3,28; b 5f; 0:; stw 5,0x0(30); li 28,128; b 4f; 1:; lis 3,-32768; lwz 6,0xf8(3); lis 5,4194; addi 5,5,19923; rlwinm 6,6,30,2,31; mulhwu 5,5,6; rlwinm 5,5,26,6,31; mulli 7,5,50; li 3,0; xoris 6,3,32768; xoris 5,0,32768; subfc 3,4,7; subfe 5,5,6; subfe 5,6,6; neg. 5,5; bne 2f; cmplwi 28,8; beq 2f; mr 3,29; bl _s8025A174_4; mr 3,28; b 5f; 2:; lis 3,-32768; lwz 6,0xf8(3); lis 5,4194; addi 5,5,19923; rlwinm 6,6,30,2,31; mulhwu 5,5,6; rlwinm 5,5,26,6,31; mulli 6,5,75; li 3,0; xoris 5,3,32768; xoris 3,0,32768; subfc 0,4,6; subfe 3,3,5; subfe 3,5,5; neg. 3,3; bne 3f; li 0,128; stw 0,0x0(30); b 4f; 3:; li 0,128; stw 0,0x0(30); li 28,128; 4:; bl _s8025A174_5; stw 4,0x4(31); lis 4,17180; lis 5,-32730; stw 3,0x0(31); lis 3,-32768; addi 8,5,-24868; lwz 0,0xf8(3); addi 4,4,-8573; addi 3,27,0; rlwinm 0,0,30,2,31; mulhwu 0,4,0; rlwinm 0,0,17,15,31; mulli 0,0,65; rlwinm 10,0,29,3,31; addi 6,30,0; addi 4,13,-23540; li 5,1; li 7,3; li 9,0; bl _s8025A174_6; mr 3,29; bl _s8025A174_7; mr 3,28; 5:; lmw 27,0x14(1); lwz 0,0x2c(1); addi 1,1,40; mtspr 8,0"
extern "C" void _s8025A174_0();
extern "C" void _s8025A174_1();
extern "C" void _s8025A174_2();
extern "C" void _s8025A174_3();
extern "C" void _s8025A174_4();
extern "C" void _s8025A174_5();
extern "C" void _s8025A174_6();
extern "C" void _s8025A174_7();
extern "C" void f_8025A174() {}
