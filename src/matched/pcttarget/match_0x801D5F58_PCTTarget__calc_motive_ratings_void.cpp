// 0x801D5F58 PCTTarget::calc_motive_ratings(void) (484 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 26,0x28(1); stw 0,0x44(1); mr 28,3; li 4,0; li 5,12; addi 3,28,204; bl _s801D5F58_0; li 4,0; li 5,12; addi 3,28,216; bl _s801D5F58_1; lwz 4,0xb8(28); mr 3,28; bl _s801D5F58_2; lwz 0,0xc0(28); cmplw 3,0; bge 0f; mulli 3,3,24; lwz 9,0xbc(28); add. 11,9,3; beq 0f; lwzx 0,9,3; cmpwi 0,1; bne 0f; lwz 27,0x14(11); li 3,0; cmpwi 27,0; beq 7f; mr 3,27; bl _s801D5F58_3; mr. 27,3; bne 1f; 0:; li 3,0; b 7f; 1:; addi 30,1,8; li 29,0; stw 29,0x4(30); li 3,24; bl _s801D5F58_4; mr 26,30; stw 3,0x4(30); li 31,0; stw 29,0x8(30); li 4,0; stb 29,0xc(30); stw 29,0x0(3); lwz 11,0x4(30); stw 29,0x4(11); lwz 9,0x4(30); stw 9,0x8(9); lwz 11,0x4(30); stw 11,0xc(11); 2:; mr 3,27; bl _s801D5F58_5; mr 30,3; mr 3,31; bl _s801D5F58_6; cmpwi 3,0; beq 3f; cmpwi 30,0; beq 3f; li 30,99; 3:; stw 31,0x24(1); mr 4,26; stw 30,0x20(1); addi 3,1,24; addi 5,1,32; addi 31,31,1; bl _s801D5F58_7; mr 4,31; cmpwi 31,13; ble 2b; lwz 9,0x4(26); addi 29,28,216; li 31,0; li 11,0; lwz 0,0x8(9); addi 30,28,204; stw 0,0x18(1); mr 10,0; 4:; lwz 9,0x14(10); rlwinm 0,11,2,0,29; rlwinm 11,31,2,0,29; mr 3,10; stwx 9,30,0; addi 31,31,1; lwz 0,0x10(10); stwx 0,29,11; bl _s801D5F58_8; mr 11,31; mr 10,3; cmpwi 11,2; ble 4b; lwz 0,0x8(26); cmpwi 0,0; beq 5f; lwz 9,0x4(26); mr 3,26; lwz 4,0x4(9); bl _s801D5F58_9; lwz 9,0x4(26); li 0,0; stw 9,0x8(9); lwz 11,0x4(26); stw 0,0x4(11); lwz 9,0x4(26); stw 9,0xc(9); stw 0,0x8(26); 5:; lwz 3,0x4(26); cmpwi 3,0; beq 6f; li 4,24; bl _s801D5F58_10; 6:; li 3,1; 7:; lwz 0,0x44(1); mtspr 8,0; lmw 26,0x28(1); addi 1,1,64"

extern "C" void _s801D5F58_0();
extern "C" void _s801D5F58_1();
extern "C" void _s801D5F58_2();
extern "C" void _s801D5F58_3();
extern "C" void _s801D5F58_4();
extern "C" void _s801D5F58_5();
extern "C" void _s801D5F58_6();
extern "C" void _s801D5F58_7();
extern "C" void _s801D5F58_8();
extern "C" void _s801D5F58_9();
extern "C" void _s801D5F58_10();

struct PCTTarget {
    void calc_motive_ratings();
};

void PCTTarget::calc_motive_ratings() {
}
