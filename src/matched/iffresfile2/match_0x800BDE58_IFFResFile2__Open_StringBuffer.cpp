// 0x800BDE58 IFFResFile2::Open(StringBuffer (1036 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-256(1); mfspr 0,8; stmw 27,0xec(1); stw 0,0x104(1); mr 28,3; mr 31,4; lwz 9,0xc(28); lha 3,0x60(9); lwz 0,0x64(9); add 3,28,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; li 3,-47; b 18f; 0:; li 27,0; addi 30,28,16; mr 4,31; mr 3,30; bl _s800BDE58_0; mr 29,30; mr. 31,3; bne 7f; li 0,64; mr 3,29; stw 0,0xe0(1); li 4,0; bl _s800BDE58_1; mr. 31,3; bne 6f; addi 30,1,88; mr 3,29; mr 4,30; addi 5,1,224; bl _s800BDE58_2; mr. 31,3; bne 6f; lis 9,-32702; li 11,0; lbz 9,0x408c(9); cmpwi 9,42; beq 1f; lbz 0,0x58(1); b 2f; 1:; addi 11,11,1; cmpwi 11,63; bgt 3f; lis 9,-32702; addi 9,9,16524; lbzx 9,9,11; cmpwi 9,42; beq 1b; lbzx 0,30,11; 2:; cmpw 9,0; beq 1b; li 31,-93; 3:; cmpwi 31,0; bne 6f; lbz 9,0x61(1); lbz 11,0x63(1); addi 9,9,-48; rlwinm 9,9,8,0,23; addi 11,11,-48; or 9,9,11; extsh 9,9; cmpwi 9,512; beq 5f; cmpwi 9,517; bne 4f; lbz 11,0x94(1); lbz 0,0x95(1); lbz 9,0x96(1); rlwinm 27,11,24,0,7; rlwinm 0,0,16,0,15; lbz 11,0x97(1); or 27,27,0; rlwinm 9,9,8,0,23; or 27,27,9; or 27,27,11; stw 27,0x140(28); b 5f; 4:; li 31,-93; 5:; cmpwi 31,0; beq 7f; 6:; mr 3,29; bl _s800BDE58_3; 7:; cmpwi 31,0; mr 3,31; bne 18f; li 3,20; bl _s800BDE58_4; stw 3,0x138(28); cmpwi 27,0; stw 31,0x0(3); stw 31,0x4(3); stw 31,0xc(3); stw 31,0x10(3); beq 11f; mr 3,28; addi 4,1,8; mr 5,27; bl _s800BDE58_5; cmpwi 3,0; bne 10f; lhz 0,0x12(1); andi. 9,0,4; bne 10f; lwz 9,0x8(1); lis 0,29299; ori 0,0,28016; cmpw 9,0; bne 10f; lwz 3,0x138(28); lis 4,29299; ori 4,4,28016; bl _s800BDE58_6; lha 0,0x10(1); mr 30,3; addi 4,1,160; addi 3,1,152; stw 0,0x4(30); li 5,64; lhz 0,0x12(1); stw 27,0x0(30); sth 0,0x8(30); bl _s800BDE58_7; addi 3,1,152; addi 4,1,20; li 5,-1; bl _s800BDE58_8; addi 4,1,152; addi 3,30,16; bl _s800BDE58_9; stw 31,0xc(30); mr 3,28; mr 4,30; li 5,0; lwz 6,0x8(1); bl _s800BDE58_10; lwz 29,0xc(30); cmpwi 3,0; bne 9f; cmpwi 29,0; beq 9f; stw 31,0xc(30); lis 5,29299; mr 4,29; ori 5,5,28016; lwz 3,0x138(28); li 6,0; bl _s800BDE58_11; lwz 0,0x8(29); cmpwi 0,0; beq 8f; bl _s800BDE58_12; lwz 4,0x4(29); bl _s800BDE58_13; 8:; bl _s800BDE58_14; mr 4,29; bl _s800BDE58_15; lwz 3,0x138(28); lis 4,29299; ori 4,4,28016; li 5,0; li 6,0; bl _s800BDE58_16; cmpwi 3,0; beq 11f; lwz 3,0x138(28); li 27,0; bl _s800BDE58_17; b 11f; 9:; li 27,0; b 11f; 10:; li 27,0; li 31,-47; 11:; cmpwi 31,0; beq 12f; mr 3,31; b 18f; 12:; cmpwi 27,0; bne 17f; lis 27,16383; li 29,64; ori 27,27,65460; b 16f; 13:; lhz 0,0x12(1); andi. 31,0,4; beq 14f; lwz 9,0x138(28); lwz 0,0x10(9); add 0,0,11; stw 0,0x10(9); b 15f; 14:; lwz 3,0x138(28); lwz 4,0x8(1); bl _s800BDE58_18; mr. 30,3; beq 15f; lha 0,0x10(1); addi 4,1,96; addi 3,1,88; li 5,64; stw 0,0x4(30); lhz 9,0x12(1); sth 9,0x8(30); lhz 0,0x12(1); stw 29,0x0(30); sth 0,0xa(30); bl _s800BDE58_19; addi 3,1,88; addi 4,1,20; li 5,-1; bl _s800BDE58_20; addi 3,30,16; addi 4,1,88; bl _s800BDE58_21; stw 31,0xc(30); 15:; lwz 0,0xc(1); add 29,29,0; 16:; mr 3,28; addi 4,1,8; mr 5,29; bl _s800BDE58_22; cmpwi 3,0; bne 17f; lwz 11,0xc(1); addi 0,11,-76; cmplw 0,27; ble 13b; 17:; lwz 3,0x138(28); lis 4,16968; ori 4,4,16726; bl _s800BDE58_23; lwz 3,0x138(28); lis 4,21586; ori 4,4,17733; bl _s800BDE58_24; lwz 3,0x138(28); lis 4,20559; ori 4,4,21321; bl _s800BDE58_25; lwz 3,0x138(28); lis 4,21584; ori 4,4,21072; bl _s800BDE58_26; lwz 3,0x138(28); lis 4,29299; ori 4,4,28016; bl _s800BDE58_27; li 0,0; li 3,0; stw 0,0x144(28); 18:; lwz 0,0x104(1); mtspr 8,0; lmw 27,0xec(1); addi 1,1,256"

extern "C" void _s800BDE58_0();
extern "C" void _s800BDE58_1();
extern "C" void _s800BDE58_2();
extern "C" void _s800BDE58_3();
extern "C" void _s800BDE58_4();
extern "C" void _s800BDE58_5();
extern "C" void _s800BDE58_6();
extern "C" void _s800BDE58_7();
extern "C" void _s800BDE58_8();
extern "C" void _s800BDE58_9();
extern "C" void _s800BDE58_10();
extern "C" void _s800BDE58_11();
extern "C" void _s800BDE58_12();
extern "C" void _s800BDE58_13();
extern "C" void _s800BDE58_14();
extern "C" void _s800BDE58_15();
extern "C" void _s800BDE58_16();
extern "C" void _s800BDE58_17();
extern "C" void _s800BDE58_18();
extern "C" void _s800BDE58_19();
extern "C" void _s800BDE58_20();
extern "C" void _s800BDE58_21();
extern "C" void _s800BDE58_22();
extern "C" void _s800BDE58_23();
extern "C" void _s800BDE58_24();
extern "C" void _s800BDE58_25();
extern "C" void _s800BDE58_26();
extern "C" void _s800BDE58_27();

struct IFFResFile2 {
    void Open_StringBuffer();
};

void IFFResFile2::Open_StringBuffer() {
}
