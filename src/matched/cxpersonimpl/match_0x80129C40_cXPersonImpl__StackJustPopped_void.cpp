// 0x80129C40 cXPersonImpl::StackJustPopped(void) (652 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 28,3; lis 27,-21846; lwz 11,0x0(28); addi 26,28,1056; ori 27,27,43691; li 30,0; lwz 9,0x0(11); lwz 10,0x0(9); lwz 11,0x18(10); lwz 0,0x64(11); lha 3,0x60(11); mtspr 8,0; add 3,10,3; blrl; lwz 31,0x4(26); mr 9,3; lwz 0,0x420(28); subf 0,0,31; mullw 0,0,27; rlwinm. 11,0,30,2,31; beq 11f; addi 25,31,-12; lwz 3,0x4(25); addi 0,3,-1; cmpw 9,0; bne 6f; lwz 30,-12(31); li 4,62; mr 29,26; addi 30,30,40; mr 3,30; bl _s80129C40_0; lhz 5,0x0(3); li 4,62; mr 3,30; addi 5,5,-1; extsh 5,5; bl _s80129C40_1; lwz 30,0x420(28); lwz 0,0x4(26); cmpw 30,0; beq 3f; 0:; lwz 0,0x8(30); cmpwi 0,0; beq 2f; lwz 0,0x534(28); cmpwi 0,0; beq 2f; lwz 9,0x0(30); addi 3,28,304; li 4,0; cmpwi 9,0; beq 1f; lwz 4,0x4(9); 1:; li 5,0; bl _s80129C40_2; 2:; lwz 0,0x4(29); addi 30,30,12; cmpw 30,0; bne 0b; 3:; lwz 9,0x4(29); cmpw 31,9; beq 5f; mr 8,31; lis 0,-21846; subf 9,8,9; ori 0,0,43691; mullw 9,9,0; mr 10,25; srawi. 7,9,2; ble 5f; 4:; lwz 0,0x0(8); addic. 7,7,-1; lwz 9,0x4(8); lwz 11,0x8(8); stw 0,0x0(10); addi 8,8,12; stw 9,0x4(10); stw 11,0x8(10); addi 10,10,12; bgt 4b; 5:; lwz 9,0x4(29); li 30,1; addi 9,9,-12; stw 9,0x4(29); b 9f; 6:; cmpw 9,3; mr 29,26; bge 9f; lwz 30,-12(31); li 4,62; addi 30,30,40; mr 3,30; bl _s80129C40_3; lhz 5,0x0(3); li 4,62; mr 3,30; addi 5,5,-1; extsh 5,5; bl _s80129C40_4; lwz 0,0x4(29); cmpw 31,0; beq 8f; mr 10,31; mr 8,25; subf 0,10,0; mullw 0,0,27; srawi. 7,0,2; ble 8f; 7:; lwz 0,0x0(10); addic. 7,7,-1; lwz 9,0x4(10); lwz 11,0x8(10); stw 0,0x0(8); addi 10,10,12; stw 9,0x4(8); stw 11,0x8(8); addi 8,8,12; bgt 7b; 8:; lwz 9,0x4(26); li 30,1; addi 9,9,-12; stw 9,0x4(26); 9:; lwz 0,0x4(29); lis 9,-21846; lwz 11,0x420(28); ori 9,9,43691; subf 0,11,0; mullw 0,0,9; rlwinm. 9,0,30,2,31; bne 10f; mr 3,28; bl _s80129C40_5; b 11f; 10:; cmpwi 30,0; beq 11f; addi 10,28,304; lwz 11,0x2a8(10); lwz 0,0x2ac(10); cmpw 0,11; beq 11f; lis 9,-13108; ori 9,9,52429; mulhwu 9,11,9; rlwinm 9,9,29,3,31; mulli 9,9,10; subf 9,9,11; mulli 9,9,68; add 9,10,9; lwz 0,0x3c(9); andi. 9,0,32768; beq 11f; mr 3,28; bl _s80129C40_6; 11:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s80129C40_0();
extern "C" void _s80129C40_1();
extern "C" void _s80129C40_2();
extern "C" void _s80129C40_3();
extern "C" void _s80129C40_4();
extern "C" void _s80129C40_5();
extern "C" void _s80129C40_6();

struct cXPersonImpl {
    void StackJustPopped();
};

void cXPersonImpl::StackJustPopped() {
}
