// 0x802532D0 __OSThreadInit (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32694; stw 0,0x4(1); li 0,2; li 4,16; stwu 1,-24(1); stw 31,0x14(1); stw 30,0x10(1); stw 29,0xc(1); li 29,0; stw 28,0x8(1); addi 28,3,-24616; addi 31,28,1048; sth 0,0x6e0(28); li 0,1; addi 3,31,744; sth 0,0x6e2(28); li 0,-1; stw 4,0x6ec(28); stw 4,0x6e8(28); stw 29,0x6e4(28); stw 0,0x6f0(28); stw 29,0x708(28); bl _s802532D0_0; stw 29,0x710(28); lis 30,-32768; addi 3,31,0; stw 29,0x70c(28); stw 31,0xd8(30); bl _s802532D0_1; mr 3,31; bl _s802532D0_2; lis 3,-32687; addi 0,3,5536; lis 3,-32688; stw 0,0x71c(28); addi 0,3,5536; stw 0,0x720(28); lis 3,-8530; addi 0,3,-17730; lwz 3,0x720(28); mr 4,31; stw 0,0x0(3); lwz 12,-27896(13); lwz 3,0xe4(30); mtspr 8,12; blrl; stw 31,0xe4(30); li 3,0; bl _s802532D0_3; stw 29,-23584(13); li 30,0; rlwinm 0,30,3,0,28; stw 29,-23580(13); add 29,28,0; 0:; mr 3,29; bl _s802532D0_4; addi 30,30,1; cmpwi 30,31; addi 29,29,8; ble 0b; lis 30,-32768; addi 3,30,220; bl _s802532D0_5; addi 4,30,220; lwzu 3,0x4(4); cmplwi 3,0; bne 1f; stw 31,0xdc(30); b 2f; 1:; stw 31,0x2fc(3); 2:; stw 3,0x300(31); li 30,0; addi 3,28,1840; stw 30,0x2fc(31); stw 31,0x0(4); bl _s802532D0_6; stw 30,-23576(13); lwz 0,0x1c(1); lwz 31,0x14(1); lwz 30,0x10(1); lwz 29,0xc(1); lwz 28,0x8(1); addi 1,1,24; mtspr 8,0"
extern "C" void _s802532D0_0();
extern "C" void _s802532D0_1();
extern "C" void _s802532D0_2();
extern "C" void _s802532D0_3();
extern "C" void _s802532D0_4();
extern "C" void _s802532D0_5();
extern "C" void _s802532D0_6();
extern "C" void f_802532D0() {}
