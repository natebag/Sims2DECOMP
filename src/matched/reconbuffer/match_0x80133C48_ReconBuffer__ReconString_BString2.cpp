// 0x80133C48 ReconBuffer::ReconString(BString2 (648 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 29,3; mr 28,4; lwz 0,0x14(29); cmpwi 0,0; beq 2f; lwz 9,0x20(29); lwz 0,0xc(29); addi 31,9,1; stw 31,0x20(29); cmpwi 0,2; beq 12f; cmpwi 0,1; bne 0f; lwz 29,0x1c(29); mr 3,28; lwz 30,0x0(29); lha 0,0xa0(30); addi 30,30,160; add 29,29,0; bl _s80133C48_0; lwz 0,0x4(30); mr 5,3; mr 3,29; mr 4,31; li 6,-1; mtspr 8,0; blrl; b 12f; 0:; lwz 3,0x1c(29); mr 4,31; li 5,-1; lwz 9,0x0(3); lha 0,0x80(9); lwz 9,0x84(9); add 3,3,0; mtspr 8,9; blrl; mr. 4,3; bne 1f; lis 9,-32706; addi 4,9,-12184; 1:; mr 3,28; bl _s80133C48_1; b 12f; 2:; lwz 0,0x18(29); cmpwi 0,0; beq 3f; mr 3,29; bl _s80133C48_2; 3:; lwz 9,0x8(29); andi. 0,9,1; beq 4f; addi 0,9,1; rlwinm 0,0,0,0,30; stw 0,0x8(29); 4:; lwz 31,0xc(29); cmpwi 31,2; beq 10f; cmpwi 31,0; bne 8f; lwz 0,0x0(29); lwz 9,0x8(29); mr 11,0; add 4,0,9; andi. 0,4,1; bne 7f; lhzx 9,11,9; li 0,0; ori 0,0,65534; cmpw 9,0; bne 5f; addi 4,4,2; mr 3,28; bl _s80133C48_3; b 10f; 5:; li 0,0; ori 0,0,65279; cmpw 9,0; bne 7f; addi 4,4,2; mr 3,28; bl _s80133C48_4; li 30,0; mr 3,28; bl _s80133C48_5; mr 27,3; lwz 9,0x8(29); addi 0,27,2; cmplw 31,27; add 0,0,0; add 9,9,0; stw 9,0x8(29); bge 11f; addi 31,1,8; 6:; mr 4,30; mr 3,28; bl _s80133C48_6; lhz 9,0x0(3); mr 4,30; mr 3,28; addi 30,30,1; sth 9,0x8(1); lbz 0,0x1(31); lbz 9,0x8(1); stb 0,0x8(1); stb 9,0x1(31); bl _s80133C48_7; lhz 0,0x8(1); cmplw 30,27; sth 0,0x0(3); blt 6b; b 11f; 7:; lwz 4,0x8(29); mr 3,28; add 4,11,4; bl _s80133C48_8; mr 3,28; bl _s80133C48_9; lwz 9,0x8(29); addi 9,9,1; add 9,9,3; stw 9,0x8(29); b 11f; 8:; cmpwi 31,1; bne 11f; lwz 9,0x8(29); andi. 0,9,1; beq 9f; addi 0,9,1; stw 0,0x8(29); 9:; lwz 9,0x8(29); li 0,-2; lwz 30,0x0(29); mr 3,28; sthx 0,30,9; add 30,30,9; bl _s80133C48_10; addi 30,30,2; mr 4,3; mr 3,30; bl _s80133C48_11; 10:; mr 3,28; bl _s80133C48_12; lwz 0,0x8(29); addi 3,3,2; add 3,3,3; add 0,0,3; stw 0,0x8(29); 11:; lwz 9,0x8(29); andi. 0,9,1; beq 12f; addi 0,9,1; stw 0,0x8(29); 12:; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"

extern "C" void _s80133C48_0();
extern "C" void _s80133C48_1();
extern "C" void _s80133C48_2();
extern "C" void _s80133C48_3();
extern "C" void _s80133C48_4();
extern "C" void _s80133C48_5();
extern "C" void _s80133C48_6();
extern "C" void _s80133C48_7();
extern "C" void _s80133C48_8();
extern "C" void _s80133C48_9();
extern "C" void _s80133C48_10();
extern "C" void _s80133C48_11();
extern "C" void _s80133C48_12();

struct ReconBuffer {
    void ReconString_BString2();
};

void ReconBuffer::ReconString_BString2() {
}
