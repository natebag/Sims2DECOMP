// 0x802724C0 _escape(EAStringC (380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 28,0x20(1); stw 0,0x34(1); lis 9,-32704; mr 30,3; lbz 0,0x1ba0(9); addi 3,1,9; li 4,0; li 5,5; stb 0,0x8(1); crxor 6,6,6; bl _s802724C0_0; lis 11,-32700; lis 10,-32704; lhz 9,-6476(11); addi 0,11,-6476; lhz 8,0x1ba4(10); addi 3,1,16; addi 9,9,1; stw 0,0x10(1); sth 9,-6476(11); sth 8,0x18(1); lwz 9,0x0(30); lhz 0,0x2(9); rlwinm 4,0,1,0,30; add 4,4,0; bl _s802724C0_1; lhz 0,0x18(1); lwz 9,0x0(30); rlwinm 0,0,0,16,23; sth 0,0x18(1); addi 31,9,9; lbz 5,0x8(9); cmpwi 5,0; beq 4f; lis 9,-32704; lis 28,-32704; addi 29,9,-935; 0:; andi. 0,5,128; bne 1f; lbzx 0,5,29; andi. 9,0,7; bne 2f; 1:; addi 4,28,7080; addi 3,1,8; crxor 6,6,6; bl _s802724C0_2; addi 3,1,16; addi 4,1,8; bl _s802724C0_3; b 3f; 2:; lbz 0,0x19(1); rlwinm 9,5,8,0,23; addi 3,1,16; addi 4,1,24; or 0,0,9; sth 0,0x18(1); bl _s802724C0_4; 3:; lbz 5,0x0(31); addi 31,31,1; cmpwi 5,0; bne 0b; 4:; lwz 11,0x10(1); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(30); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 5f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802724C0_5; 5:; lwz 4,0x10(1); stw 4,0x0(30); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 6f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802724C0_6; 6:; lwz 0,0x34(1); mtspr 8,0; lmw 28,0x20(1); addi 1,1,48"
extern "C" void _s802724C0_0();
extern "C" void _s802724C0_1();
extern "C" void _s802724C0_2();
extern "C" void _s802724C0_3();
extern "C" void _s802724C0_4();
extern "C" void _s802724C0_5();
extern "C" void _s802724C0_6();
extern "C" void f_802724C0() {}
