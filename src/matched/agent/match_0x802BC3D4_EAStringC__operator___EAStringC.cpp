// 0x802BC3D4 EAStringC::operator+=(EAStringC (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 28,4; lwz 9,0x0(30); lhz 29,0x2(9); cmpwi 29,0; bne 1f; lwz 11,0x0(28); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x0(30); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802BC3D4_0; 0:; lwz 0,0x0(28); mr 3,30; stw 0,0x0(30); b 3f; 1:; lwz 9,0x0(28); lhz 31,0x2(9); cmpwi 31,0; beq 2f; add 4,29,31; mr 3,30; mr 8,4; li 5,0; mr 6,29; li 7,0; bl _s802BC3D4_1; lwz 3,0x0(30); addi 5,31,1; lwz 4,0x0(28); addi 3,3,8; add 3,3,29; addi 4,4,8; crxor 6,6,6; bl _s802BC3D4_2; 2:; mr 3,30; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s802BC3D4_0();
extern "C" void _s802BC3D4_1();
extern "C" void _s802BC3D4_2();
extern "C" void f_802BC3D4() {}
