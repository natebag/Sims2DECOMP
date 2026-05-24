// 0x80125980 cXPersonImpl::RunImmediateAction(Interaction (336 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 25,0x2c(1); stw 0,0x4c(1); mr 28,4; mr 31,3; mr 3,28; bl _s80125980_0; mr 27,3; lwz 4,0x4(31); mr 5,27; addi 3,1,8; bl _s80125980_1; addi 3,1,8; mr 4,28; li 5,0; li 6,1; li 7,1; li 8,0; bl _s80125980_2; lwz 0,0x3c(28); andi. 9,0,8; beq 0f; lwz 26,-31696(13); cmpwi 26,0; beq 1f; 0:; addi 3,1,8; li 4,2; bl _s80125980_3; li 3,0; b 6f; 1:; lwz 0,0x4(31); lwz 11,0x28(28); stw 0,-31692(13); stw 28,-31696(13); lha 25,0x4a(31); sth 11,0x4a(31); lwz 9,0x0(31); lwz 11,0x4(27); lwz 29,0x0(9); lwz 0,0x37c(11); lha 3,0x378(11); mtspr 8,0; add 3,27,3; blrl; lwz 9,0x4(27); mr 30,3; lwz 0,0x32c(9); lha 3,0x328(9); mtspr 8,0; add 3,27,3; blrl; mr 5,3; lha 6,0x2c(28); mr 3,29; mr 4,30; addi 7,28,24; bl _s80125980_4; lha 0,0x4a(31); stw 26,-31696(13); cmpwi 0,-100; stw 26,-31692(13); bne 2f; sth 26,0x4a(31); b 3f; 2:; sth 25,0x4a(31); 3:; lwz 0,0x38(28); li 9,1; cmpwi 0,0; bne 4f; li 9,0; 4:; cmpwi 9,0; bne 5f; mr 3,28; bl _s80125980_5; 5:; addi 3,1,8; li 4,2; bl _s80125980_6; li 3,1; 6:; lwz 0,0x4c(1); mtspr 8,0; lmw 25,0x2c(1); addi 1,1,72"

extern "C" void _s80125980_0();
extern "C" void _s80125980_1();
extern "C" void _s80125980_2();
extern "C" void _s80125980_3();
extern "C" void _s80125980_4();
extern "C" void _s80125980_5();
extern "C" void _s80125980_6();

struct cXPersonImpl {
    void RunImmediateAction_Interaction();
};

void cXPersonImpl::RunImmediateAction_Interaction() {
}
