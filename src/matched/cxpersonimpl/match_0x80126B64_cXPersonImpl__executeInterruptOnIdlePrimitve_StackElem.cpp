// 0x80126B64 cXPersonImpl::executeInterruptOnIdlePrimitve(StackElem (756 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 25,0x2c(1); stw 0,0x4c(1); mr 31,3; mr 26,4; lwz 30,0x0(31); mr 25,5; mr 29,6; li 4,8; addi 30,30,40; mr 3,30; bl _s80126B64_0; lha 5,0x0(3); li 4,8; mr 3,30; ori 5,5,64; bl _s80126B64_1; addi 10,31,304; lwz 11,0x2a8(10); lwz 0,0x2ac(10); cmpw 0,11; beq 1f; lwz 0,0x8(26); cmpwi 0,1; bne 0f; lis 9,-13108; ori 9,9,52429; mulhwu 9,11,9; rlwinm 9,9,29,3,31; mulli 9,9,10; subf 9,9,11; mulli 9,9,68; add 9,10,9; lwz 0,0x3c(9); andi. 9,0,2; beq 1f; 0:; addi 11,31,304; lis 0,-13108; lwz 9,0x2a8(11); ori 0,0,52429; mr 28,11; mulhwu 0,9,0; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 9,0,9; mulli 9,9,68; add 30,11,9; lwz 0,0x3c(30); andi. 9,0,32768; bne 3f; cmpwi 29,0; bne 2f; 1:; li 3,0; li 4,1; b 11f; 2:; lwz 0,0x534(31); cmpwi 0,0; beq 3f; lwz 9,0x0(31); li 0,1; stw 0,-24512(13); li 10,82; lwz 11,0x0(9); li 4,82; sth 10,0x34(11); lwz 9,0x0(31); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x110(11); lwz 0,0x114(11); add 3,10,3; mtspr 8,0; blrl; li 3,-1; li 4,-1; b 11f; 3:; mr 3,30; bl _s80126B64_2; mr. 11,3; beq 4f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr 29,3; b 5f; 4:; li 29,0; 5:; cmpwi 29,0; bne 6f; li 4,0; mr 3,28; bl _s80126B64_3; b 8f; 6:; mr 4,30; mr 3,28; bl _s80126B64_4; lwz 4,0x4(31); mr 27,3; lwz 5,0x4(29); addi 3,1,8; bl _s80126B64_5; addi 3,1,8; mr 4,30; li 5,0; li 6,1; li 7,1; li 8,0; bl _s80126B64_6; lwz 0,0x3c(30); andi. 9,0,8; beq 7f; lha 6,0x2c(30); cmpwi 6,0; beq 7f; lwz 3,0x4(31); addi 5,30,24; lwz 4,0x4(29); li 7,0; lwz 9,0x4(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 9f; 7:; mr 3,31; mr 4,30; bl _s80126B64_7; addi 3,1,8; li 4,2; bl _s80126B64_8; 8:; li 3,0; li 4,2; b 11f; 9:; lwz 0,0x3c(30); andi. 9,0,2; bne 10f; cmpwi 27,0; bne 10f; mr 4,30; mr 3,28; bl _s80126B64_9; cmpw 27,3; beq 10f; mr 3,28; li 4,0; bl _s80126B64_10; 10:; li 30,1; mr 3,31; stw 30,0x534(31); bl _s80126B64_11; li 0,0; sth 0,0x0(25); stw 30,0x8(26); lwz 9,0x0(31); lwz 11,0x0(9); lwz 10,0x0(11); lwz 9,0x18(10); lwz 0,0x4c(9); lha 3,0x48(9); mtspr 8,0; add 3,10,3; blrl; lhz 0,0x64(29); li 4,8; sth 0,0x4(3); lwz 30,0x0(31); addi 30,30,40; mr 3,30; bl _s80126B64_12; lha 5,0x0(3); li 4,8; mr 3,30; ori 5,5,64; bl _s80126B64_13; addi 3,1,8; li 4,2; bl _s80126B64_14; li 3,0; li 4,3; 11:; lwz 0,0x4c(1); mtspr 8,0; lmw 25,0x2c(1); addi 1,1,72"

extern "C" void _s80126B64_0();
extern "C" void _s80126B64_1();
extern "C" void _s80126B64_2();
extern "C" void _s80126B64_3();
extern "C" void _s80126B64_4();
extern "C" void _s80126B64_5();
extern "C" void _s80126B64_6();
extern "C" void _s80126B64_7();
extern "C" void _s80126B64_8();
extern "C" void _s80126B64_9();
extern "C" void _s80126B64_10();
extern "C" void _s80126B64_11();
extern "C" void _s80126B64_12();
extern "C" void _s80126B64_13();
extern "C" void _s80126B64_14();

struct cXPersonImpl {
    void executeInterruptOnIdlePrimitve_StackElem();
};

void cXPersonImpl::executeInterruptOnIdlePrimitve_StackElem() {
}
