// 0x80125ADC cXPersonImpl::AddAction(Interaction (904 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 21,0xc(1); stw 0,0x3c(1); mr 28,4; mr 26,3; mr 3,28; bl _s80125ADC_0; mr. 31,3; beq 10f; lwz 9,0x0(31); lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; mr 3,26; mr 4,28; bl _s80125ADC_1; b 23f; 0:; lwz 9,0x0(31); addi 27,26,304; lha 3,0x68(9); lwz 0,0x6c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; lwz 0,0x2ac(27); lwz 11,0x2a8(27); subf. 9,11,0; beq 1f; addi 0,9,-1; lis 9,-13108; add 0,11,0; ori 9,9,52429; mulhwu 9,0,9; rlwinm 9,9,29,3,31; mulli 9,9,10; subf 0,9,0; mulli 0,0,68; add 31,27,0; mr 3,31; bl _s80125ADC_2; mr 30,3; mr 3,28; bl _s80125ADC_3; cmpw 30,3; bne 1f; lwz 9,0x14(31); lwz 0,0x14(28); cmpw 9,0; beq 10f; 1:; lwz 24,0x28(28); mr 3,28; bl _s80125ADC_4; li 22,0; lwz 0,0x3c(28); andi. 9,0,2; bne 2f; andi. 9,0,32; bne 2f; andi. 9,0,32768; beq 3f; 2:; li 22,1; 3:; lwz 0,0x3c(28); andi. 9,0,2; beq 4f; andi. 9,0,64; beq 4f; lwz 11,0x4(26); lwz 9,0x4(11); lha 3,0xe8(9); lwz 0,0xec(9); add 3,11,3; mtspr 8,0; blrl; bl _s80125ADC_5; mr 4,3; mr 3,28; bl _s80125ADC_6; 4:; mr 3,27; bl _s80125ADC_7; mr 23,3; cmpwi 23,5; ble 12f; li 21,1; cmpwi 22,0; bne 9f; lwz 0,0x534(26); li 25,0; li 9,0; cmpwi 0,0; beq 5f; li 9,1; 5:; mr 31,9; lwz 0,0x2ac(27); lwz 9,0x2a8(27); subf 0,9,0; cmplw 31,0; bge 8f; lis 29,-13108; mr 30,27; ori 29,29,52429; 6:; lwz 0,0x2a8(30); add 0,0,31; mulhwu 9,0,29; rlwinm 9,9,29,3,31; mulli 9,9,10; subf 0,9,0; mulli 0,0,68; add 4,30,0; lwz 9,0x28(4); cmpw 9,24; bge 7f; lwz 0,0x3c(4); andi. 9,0,1024; bne 7f; mr 3,27; bl _s80125ADC_8; cmpwi 3,0; beq 7f; addi 25,25,1; 7:; lwz 9,0x2ac(30); addi 31,31,1; lwz 0,0x2a8(30); subf 9,0,9; cmplw 31,9; blt 6b; 8:; subf 0,25,23; cmpwi 0,5; bgt 9f; li 21,0; 9:; cmpwi 21,0; beq 12f; lwz 0,0x3c(28); andi. 9,0,1024; bne 11f; 10:; li 3,0; b 23f; 11:; ori 0,0,16; stw 0,0x3c(28); 12:; lwz 0,0x3c(28); andi. 9,0,32768; beq 13f; mr 3,27; mr 4,28; li 5,0; bl _s80125ADC_9; b 23f; 13:; cmpwi 22,0; beq 15f; lwz 0,0x534(26); li 5,0; cmpwi 0,0; beq 14f; li 5,1; 14:; mr 3,27; mr 4,28; bl _s80125ADC_10; b 23f; 15:; lwz 0,0x534(26); li 9,0; cmpwi 0,0; beq 16f; li 9,1; 16:; mr 31,9; lwz 0,0x2ac(27); lwz 9,0x2a8(27); subf 0,9,0; cmplw 31,0; bge 20f; lis 29,-13108; mr 30,27; ori 29,29,52429; 17:; lwz 0,0x2a8(30); add 0,0,31; mulhwu 9,0,29; rlwinm 9,9,29,3,31; mulli 9,9,10; subf 0,9,0; mulli 0,0,68; add 4,30,0; lwz 9,0x28(4); cmpw 9,24; bge 18f; lwz 0,0x3c(4); andi. 9,0,1024; bne 18f; mr 3,26; bl _s80125ADC_11; b 19f; 18:; addi 31,31,1; 19:; lwz 0,0x2ac(30); lwz 9,0x2a8(30); subf 0,9,0; cmplw 31,0; blt 17b; 20:; lwz 3,-31696(13); cmpwi 3,0; beq 22f; lwz 9,0x4(26); lwz 0,-31692(13); cmpw 9,0; bne 22f; lwz 0,0x3c(28); andi. 9,0,64; beq 21f; bl _s80125ADC_12; mr 4,3; mr 3,28; bl _s80125ADC_13; 21:; lwz 3,-31696(13); mr 4,28; bl _s80125ADC_14; 22:; mr 3,27; mr 4,28; bl _s80125ADC_15; 23:; lwz 0,0x3c(1); mtspr 8,0; lmw 21,0xc(1); addi 1,1,56"

extern "C" void _s80125ADC_0();
extern "C" void _s80125ADC_1();
extern "C" void _s80125ADC_2();
extern "C" void _s80125ADC_3();
extern "C" void _s80125ADC_4();
extern "C" void _s80125ADC_5();
extern "C" void _s80125ADC_6();
extern "C" void _s80125ADC_7();
extern "C" void _s80125ADC_8();
extern "C" void _s80125ADC_9();
extern "C" void _s80125ADC_10();
extern "C" void _s80125ADC_11();
extern "C" void _s80125ADC_12();
extern "C" void _s80125ADC_13();
extern "C" void _s80125ADC_14();
extern "C" void _s80125ADC_15();

struct cXPersonImpl {
    void AddAction_Interaction();
};

void cXPersonImpl::AddAction_Interaction() {
}
