// 0x800C0064 IFFResFile2::NewBlockHeader(IFFHeader (592 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-192(1); mfspr 0,8; stmw 26,0xa8(1); stw 0,0xc4(1); mr 28,3; li 0,1; lwz 9,0x140(28); mr 31,4; mr 30,5; mr 27,6; stw 0,0x144(28); cmpwi 9,0; beq 0f; addi 4,28,16; li 5,0; bl _s800C0064_0; mr. 29,3; bne 10f; 0:; lwz 0,0x13c(28); addi 30,30,76; cmpwi 0,0; bgt 1f; li 0,64; 1:; stw 0,0x0(27); neg 26,30; b 8f; 2:; lwz 0,0x0(27); stw 0,0x13c(28); lhz 9,0xa(31); andi. 0,9,4; beq 7f; li 29,0; b 4f; 3:; lwz 9,0x4(31); li 29,1; lwz 0,0xc(1); add 9,9,0; stw 9,0x4(31); 4:; lwz 0,0x0(27); mr 3,28; lwz 5,0x4(31); addi 4,1,8; add 5,0,5; bl _s800C0064_1; cmpwi 3,0; bne 5f; lhz 0,0x12(1); andi. 9,0,4; bne 3b; 5:; cmpwi 29,0; beq 6f; lwz 5,0x0(27); mr 3,28; mr 4,31; bl _s800C0064_2; mr. 29,3; bne 10f; 6:; lwz 9,0x4(31); cmpw 9,30; beq 9f; addi 0,30,76; cmpw 9,0; blt 7f; lwz 5,0x0(27); lis 0,22616; subf 9,30,9; ori 0,0,22616; li 11,4; stw 0,0x8(1); stw 9,0xc(1); add 5,5,30; sth 11,0x12(1); mr 3,28; addi 4,1,8; bl _s800C0064_3; mr. 29,3; bne 10f; stw 30,0x4(31); mr 4,31; mr 3,28; lwz 5,0x0(27); bl _s800C0064_4; mr. 29,3; bne 10f; lwz 9,0x138(28); li 3,0; lwz 0,0x10(9); add 0,0,26; stw 0,0x10(9); b 11f; 7:; lwz 0,0x0(27); lwz 9,0x4(31); add 0,0,9; stw 0,0x0(27); 8:; lwz 5,0x0(27); mr 3,28; mr 4,31; bl _s800C0064_5; cmpwi 3,0; beq 2b; addi 3,28,16; addi 4,1,160; bl _s800C0064_6; mr. 29,3; bne 10f; lwz 9,0x0(27); lis 0,22616; ori 0,0,22616; li 11,4; stw 9,0x13c(28); addi 4,1,96; stw 30,0x4(31); addi 3,1,88; stw 0,0x0(31); li 5,64; sth 11,0xa(31); addi 30,31,12; bl _s800C0064_7; addi 3,1,88; li 4,0; li 5,-1; bl _s800C0064_8; addi 3,1,88; bl _s800C0064_9; addi 3,1,88; bl _s800C0064_10; mr 4,3; li 5,63; mr 3,30; bl _s800C0064_11; stb 29,0x4b(31); mr 3,28; mr 4,31; lwz 5,0x0(27); bl _s800C0064_12; b 11f; 9:; lwz 9,0x138(28); li 3,0; lwz 0,0x10(9); subf 0,30,0; stw 0,0x10(9); b 11f; 10:; mr 3,29; 11:; lwz 0,0xc4(1); mtspr 8,0; lmw 26,0xa8(1); addi 1,1,192"

extern "C" void _s800C0064_0();
extern "C" void _s800C0064_1();
extern "C" void _s800C0064_2();
extern "C" void _s800C0064_3();
extern "C" void _s800C0064_4();
extern "C" void _s800C0064_5();
extern "C" void _s800C0064_6();
extern "C" void _s800C0064_7();
extern "C" void _s800C0064_8();
extern "C" void _s800C0064_9();
extern "C" void _s800C0064_10();
extern "C" void _s800C0064_11();
extern "C" void _s800C0064_12();

struct IFFResFile2 {
    void NewBlockHeader_IFFHeader();
};

void IFFResFile2::NewBlockHeader_IFFHeader() {
}
