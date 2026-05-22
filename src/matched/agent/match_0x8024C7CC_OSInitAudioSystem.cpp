// 0x8024C7CC __OSInitAudioSystem (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-48(1); stmw 25,0x14(1); bl _s8024C7CC_0; lis 4,-32512; li 5,128; addi 3,3,-128; bl _s8024C7CC_1; lis 3,-32700; addi 4,3,-20672; lis 3,-32512; li 5,128; bl _s8024C7CC_2; lis 3,-32512; li 4,128; bl _s8024C7CC_3; lis 3,-13312; addi 3,3,20480; li 0,67; sth 0,0x12(3); addi 31,3,10; li 0,2220; sth 0,0xa(3); lhz 0,0xa(3); ori 0,0,1; sth 0,0xa(3); 0:; lhz 0,0x0(31); rlwinm. 0,0,0,31,31; bne 0b; li 0,0; lis 4,-13312; sth 0,0x5000(4); 1:; addi 30,4,20480; lhzu 3,0x4(30); addi 29,4,20480; lhzu 0,0x6(29); rlwimi 0,3,16,0,15; rlwinm. 0,0,0,0,0; bne 1b; lis 3,-13312; lis 0,256; addi 27,3,20480; stwu 0,0x20(27); li 0,0; addi 26,3,20480; stwu 0,0x24(26); li 0,32; addi 25,3,20480; stwu 0,0x28(25); lhz 3,0x0(31); b 3f; 2:; lhz 3,0x0(31); 3:; rlwinm. 0,3,0,26,26; beq 2b; sth 3,0x0(31); bl _s8024C7CC_4; mr 28,3; 4:; bl _s8024C7CC_5; subf 0,28,3; cmpwi 0,2194; blt 4b; lis 0,256; stw 0,0x0(27); li 3,0; li 0,32; stw 3,0x0(26); stw 0,0x0(25); lhz 3,0x0(31); b 6f; 5:; lhz 3,0x0(31); 6:; rlwinm. 0,3,0,26,26; beq 5b; sth 3,0x0(31); lhz 0,0x0(31); rlwinm 0,0,0,21,19; sth 0,0x0(31); 7:; lhz 0,0x0(31); rlwinm. 0,0,0,21,21; bne 7b; lhz 0,0x0(31); rlwinm 0,0,0,30,28; sth 0,0x0(31); lhz 0,0x0(30); b 9f; 8:; lhz 0,0x0(30); 9:; rlwinm 5,0,0,16,31; rlwinm. 0,0,0,16,16; beq 8b; lhz 0,0x0(31); lhz 4,0x0(29); ori 0,0,4; sth 0,0x0(31); li 0,2220; sth 0,0x0(31); lhz 0,0x0(31); ori 0,0,1; sth 0,0x0(31); 10:; lhz 0,0x0(31); rlwinm. 0,0,0,31,31; bne 10b; bl _s8024C7CC_6; addi 4,3,-128; lis 3,-32512; li 5,128; bl _s8024C7CC_7; lmw 25,0x14(1); lwz 0,0x34(1); addi 1,1,48; mtspr 8,0"
extern "C" void _s8024C7CC_0();
extern "C" void _s8024C7CC_1();
extern "C" void _s8024C7CC_2();
extern "C" void _s8024C7CC_3();
extern "C" void _s8024C7CC_4();
extern "C" void _s8024C7CC_5();
extern "C" void _s8024C7CC_6();
extern "C" void _s8024C7CC_7();
extern "C" void f_8024C7CC() {}
