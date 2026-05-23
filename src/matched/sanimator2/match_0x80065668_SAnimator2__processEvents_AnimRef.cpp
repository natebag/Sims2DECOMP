// 0x80065668 SAnimator2::processEvents(AnimRef (432 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 25,0x1c(1); stw 0,0x3c(1); mr 29,3; lwz 4,0x0(4); lis 3,-32693; mr 28,5; mr 27,6; mr 25,7; mr 30,8; addi 3,3,11064; bl _s80065668_0; li 26,0; mr 31,3; addi 3,1,8; bl _s80065668_1; cmpwi 31,0; beq 0f; addi 9,31,136; addi 3,1,8; mr 4,9; lwz 26,0x4(9); bl _s80065668_2; 0:; cmpwi 30,1; bne 1f; lwz 0,0x61c(29); ori 0,0,128; b 2f; 1:; lwz 0,0x61c(29); rlwinm 0,0,0,25,23; 2:; stw 0,0x61c(29); cmpwi 25,0; bne 8f; li 30,0; cmpw 30,26; bge 15f; add 25,28,27; cmpwi 27,0; mfcr 27; li 31,0; 3:; lwz 11,0x8(1); li 9,0; add 4,11,31; lwz 0,0x4(4); cmpwi 0,5; bne 4f; li 9,150; 4:; lwzx 0,11,31; subf. 0,9,0; bge 5f; li 0,0; 5:; cmpw 0,28; blt 7f; mtcrf 128,27; blt 6f; cmpw 0,25; bge 7f; 6:; mr 3,29; mr 5,30; bl _s80065668_3; 7:; addi 30,30,1; addi 31,31,12; cmpw 30,26; blt 3b; b 15f; 8:; li 0,0; cmpwi 31,0; beq 9f; lwz 0,0x14(31); 9:; subf 28,28,0; addic. 31,26,-1; blt 15f; mulli 30,31,12; subf 26,27,28; cmpwi 27,0; mfcr 27; 10:; lwz 11,0x8(1); li 9,0; add 4,11,30; lwz 0,0x4(4); cmpwi 0,5; bne 11f; li 9,150; 11:; lwzx 0,11,30; subf. 0,9,0; bge 12f; li 0,0; 12:; cmpw 0,28; bgt 14f; mtcrf 128,27; blt 13f; cmpw 0,26; ble 14f; 13:; mr 3,29; mr 5,31; bl _s80065668_4; 14:; addi 30,30,-12; addic. 31,31,-1; bge 10b; 15:; addi 3,1,8; li 4,2; bl _s80065668_5; lwz 0,0x3c(1); mtspr 8,0; lmw 25,0x1c(1); addi 1,1,56"

extern "C" void _s80065668_0();
extern "C" void _s80065668_1();
extern "C" void _s80065668_2();
extern "C" void _s80065668_3();
extern "C" void _s80065668_4();
extern "C" void _s80065668_5();

struct SAnimator2 {
    void processEvents();
};

void SAnimator2::processEvents() {
}
