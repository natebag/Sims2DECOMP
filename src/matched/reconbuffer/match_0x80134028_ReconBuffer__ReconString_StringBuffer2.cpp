// 0x80134028 ReconBuffer::ReconString(StringBuffer2 (580 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 28,4; lwz 0,0x14(29); cmpwi 0,0; beq 1f; lwz 9,0x20(29); lwz 0,0xc(29); addi 31,9,1; stw 31,0x20(29); cmpwi 0,2; beq 11f; cmpwi 0,1; bne 0f; lwz 29,0x1c(29); mr 3,28; lwz 30,0x0(29); lha 0,0xa0(30); addi 30,30,160; add 29,29,0; bl _s80134028_0; lwz 0,0x4(30); mr 5,3; mr 3,29; mr 4,31; li 6,-1; mtspr 8,0; blrl; b 11f; 0:; lwz 11,0x1c(29); mr 4,31; li 5,-1; lwz 9,0x0(11); lha 3,0x80(9); lwz 0,0x84(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 3,28; bl _s80134028_1; b 11f; 1:; lwz 0,0x18(29); cmpwi 0,0; beq 2f; mr 3,29; bl _s80134028_2; 2:; lwz 9,0x8(29); andi. 0,9,1; beq 3f; addi 0,9,1; rlwinm 0,0,0,0,30; stw 0,0x8(29); 3:; lwz 30,0xc(29); cmpwi 30,2; beq 9f; cmpwi 30,0; bne 8f; lwz 9,0x0(29); li 0,0; lwz 11,0x8(29); ori 0,0,65534; lhzx 10,9,11; add 4,9,11; cmpw 10,0; bne 4f; addi 4,4,2; mr 3,28; bl _s80134028_3; b 9f; 4:; li 0,0; ori 0,0,65279; cmpw 10,0; bne 7f; addi 4,4,2; mr 3,28; bl _s80134028_4; li 31,0; mr 3,28; bl _s80134028_5; mr 27,3; cmpw 30,27; bge 6f; 5:; mr 3,28; bl _s80134028_6; mr 30,3; mr 3,28; bl _s80134028_7; add 11,31,31; lhzx 9,11,3; addi 31,31,1; cmpw 31,27; rlwinm 0,9,8,16,23; rlwinm 9,9,24,8,31; or 0,0,9; sthx 0,11,30; blt 5b; 6:; lwz 9,0x8(29); addi 0,27,2; add 0,0,0; add 9,9,0; stw 9,0x8(29); b 10f; 7:; mr 3,28; bl _s80134028_8; mr 3,28; bl _s80134028_9; lwz 9,0x8(29); addi 9,9,1; add 9,9,3; stw 9,0x8(29); b 10f; 8:; cmpwi 30,1; bne 10f; lwz 9,0x8(29); li 0,-2; lwz 30,0x0(29); mr 3,28; sthx 0,30,9; add 30,30,9; bl _s80134028_10; addi 30,30,2; mr 4,3; mr 3,30; bl _s80134028_11; 9:; mr 3,28; bl _s80134028_12; lwz 0,0x8(29); addi 3,3,2; add 3,3,3; add 0,0,3; stw 0,0x8(29); 10:; lwz 9,0x8(29); andi. 0,9,1; beq 11f; addi 0,9,1; stw 0,0x8(29); 11:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s80134028_0();
extern "C" void _s80134028_1();
extern "C" void _s80134028_2();
extern "C" void _s80134028_3();
extern "C" void _s80134028_4();
extern "C" void _s80134028_5();
extern "C" void _s80134028_6();
extern "C" void _s80134028_7();
extern "C" void _s80134028_8();
extern "C" void _s80134028_9();
extern "C" void _s80134028_10();
extern "C" void _s80134028_11();
extern "C" void _s80134028_12();

struct ReconBuffer {
    void ReconString_StringBuffer2();
};

void ReconBuffer::ReconString_StringBuffer2() {
}
