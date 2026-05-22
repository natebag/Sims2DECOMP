// 0x802568E0 EXIDma (236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-64(1); stmw 25,0x24(1); addi 27,3,0; addi 28,4,0; addi 29,5,0; addi 30,6,0; addi 25,7,0; rlwinm 4,3,6,0,25; lis 3,-32694; addi 0,3,-22064; add 26,0,4; bl _s802568E0_0; mr 31,3; lwz 0,0xc(26); rlwinm. 0,0,0,30,31; bne 0f; lwz 0,0xc(26); rlwinm. 0,0,0,29,29; bne 1f; 0:; mr 3,31; bl _s802568E0_1; li 3,0; b 3f; 1:; stw 25,0x4(26); lwz 0,0x4(26); cmplwi 0,0; beq 2f; addi 3,27,0; li 4,0; li 5,1; li 6,0; bl _s802568E0_2; lis 3,32; mulli 0,27,3; srw 3,3,0; bl _s802568E0_3; 2:; lwz 0,0xc(26); ori 0,0,1; stw 0,0xc(26); rlwinm 4,28,0,6,26; lis 3,-13312; addi 0,3,26624; mulli 3,27,20; add 3,0,3; stw 4,0x4(3); stw 29,0x8(3); rlwinm 0,30,2,0,29; ori 0,0,3; stw 0,0xc(3); mr 3,31; bl _s802568E0_4; li 3,1; 3:; lwz 0,0x44(1); lmw 25,0x24(1); addi 1,1,64; mtspr 8,0"
extern "C" void _s802568E0_0();
extern "C" void _s802568E0_1();
extern "C" void _s802568E0_2();
extern "C" void _s802568E0_3();
extern "C" void _s802568E0_4();
extern "C" void f_802568E0() {}
