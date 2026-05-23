// 0x80065DE8 SAnimator2::procBoneParticleEvt(AnimParticleData (524 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 24,0x10(1); stw 0,0x34(1); mr 31,3; mr 25,5; mr. 28,4; beq 8f; lwz 0,0x61c(31); addi 29,31,1488; lwz 26,0x4(28); lwz 27,0x0(28); andi. 9,0,128; beq 0f; addi 29,31,1500; 0:; li 30,0; mr 3,29; stw 30,0x8(1); mr 4,27; addi 5,1,8; bl _s80065DE8_0; cmpwi 3,0; bne 3f; li 3,12; li 24,0; bl _s80065DE8_1; mr 30,3; bl _s80065DE8_2; stw 30,0x8(1); mr 5,30; mr 4,27; li 6,0; mr 3,29; bl _s80065DE8_3; bl _s80065DE8_4; li 7,0; li 4,128; li 5,16; li 6,0; bl _s80065DE8_5; lwz 4,0x4(31); mr 5,28; mr 6,25; bl _s80065DE8_6; lwz 11,0x4(31); mr 30,3; lwz 9,0x4(11); lha 3,0x118(9); lwz 0,0x11c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x330(9); lwz 9,0x334(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 2f; 1:; li 24,1; 2:; stw 24,0x48(30); mr 4,26; mr 5,30; li 6,0; lwz 3,0x8(1); bl _s80065DE8_7; b 8f; 3:; lwz 3,0x8(1); mr 4,26; stw 30,0xc(1); addi 5,1,12; bl _s80065DE8_8; mr. 4,3; beq 5f; lwz 3,0x8(1); bl _s80065DE8_9; lwz 9,0xc(1); stw 30,0x78(9); lwz 3,0xc(1); cmpwi 3,0; beq 4f; li 4,3; bl _s80065DE8_10; 4:; stw 30,0xc(1); b 8f; 5:; bl _s80065DE8_11; li 29,0; li 7,0; li 4,128; li 5,16; li 6,0; bl _s80065DE8_12; lwz 4,0x4(31); mr 5,28; mr 6,25; bl _s80065DE8_13; mr 30,3; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x118(9); lwz 9,0x11c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 6f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x330(9); lwz 9,0x334(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 7f; 6:; li 29,1; 7:; stw 29,0x48(30); mr 4,26; mr 5,30; li 6,0; lwz 3,0x8(1); bl _s80065DE8_14; 8:; lwz 0,0x34(1); mtspr 8,0; lmw 24,0x10(1); addi 1,1,48"

extern "C" void _s80065DE8_0();
extern "C" void _s80065DE8_1();
extern "C" void _s80065DE8_2();
extern "C" void _s80065DE8_3();
extern "C" void _s80065DE8_4();
extern "C" void _s80065DE8_5();
extern "C" void _s80065DE8_6();
extern "C" void _s80065DE8_7();
extern "C" void _s80065DE8_8();
extern "C" void _s80065DE8_9();
extern "C" void _s80065DE8_10();
extern "C" void _s80065DE8_11();
extern "C" void _s80065DE8_12();
extern "C" void _s80065DE8_13();
extern "C" void _s80065DE8_14();

struct SAnimator2 {
    void procBoneParticleEvt_AnimParticleData();
};

void SAnimator2::procBoneParticleEvt_AnimParticleData() {
}
