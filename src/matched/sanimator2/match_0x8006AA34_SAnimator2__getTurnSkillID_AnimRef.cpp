// 0x8006AA34 SAnimator2::getTurnSkillID(AnimRef (612 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x18(3); cmpwi 0,1; beq 0f; cmpwi 0,8; beq 0f; lwz 9,0x2c(3); addi 9,9,-9; cmplwi 9,5; bgt 10f; 0:; cmpwi 5,0; beq 24f; bgt 1f; cmpwi 5,-3; beq 7f; bgt 6f; cmpwi 5,-5; beq 9f; cmpwi 5,-4; beq 8f; b 24f; 1:; cmpwi 5,3; beq 3f; blt 2f; cmpwi 5,4; beq 4f; cmpwi 5,5; beq 5f; b 24f; 2:; mr 5,4; lwz 3,0x4(3); li 4,29; bl _s8006AA34_0; b 24f; 3:; mr 5,4; lwz 3,0x4(3); li 4,31; bl _s8006AA34_1; b 24f; 4:; mr 5,4; lwz 3,0x4(3); li 4,33; bl _s8006AA34_2; b 24f; 5:; mr 5,4; lwz 3,0x4(3); li 4,35; bl _s8006AA34_3; b 24f; 6:; mr 5,4; lwz 3,0x4(3); li 4,30; bl _s8006AA34_4; b 24f; 7:; mr 5,4; lwz 3,0x4(3); li 4,32; bl _s8006AA34_5; b 24f; 8:; mr 5,4; lwz 3,0x4(3); li 4,34; bl _s8006AA34_6; b 24f; 9:; mr 5,4; lwz 3,0x4(3); li 4,36; bl _s8006AA34_7; b 24f; 10:; cmpwi 5,0; beq 24f; bgt 12f; cmpwi 5,-3; beq 21f; bgt 11f; cmpwi 5,-5; beq 23f; cmpwi 5,-4; beq 22f; b 24f; 11:; cmpwi 5,-2; beq 20f; cmpwi 5,-1; beq 19f; b 24f; 12:; cmpwi 5,3; beq 16f; bgt 13f; cmpwi 5,1; beq 14f; cmpwi 5,2; beq 15f; b 24f; 13:; cmpwi 5,4; beq 17f; cmpwi 5,5; beq 18f; b 24f; 14:; mr 5,4; lwz 3,0x4(3); li 4,14; bl _s8006AA34_8; b 24f; 15:; mr 5,4; lwz 3,0x4(3); li 4,8; bl _s8006AA34_9; b 24f; 16:; mr 5,4; lwz 3,0x4(3); li 4,6; bl _s8006AA34_10; b 24f; 17:; mr 5,4; lwz 3,0x4(3); li 4,17; bl _s8006AA34_11; b 24f; 18:; mr 5,4; lwz 3,0x4(3); li 4,4; bl _s8006AA34_12; b 24f; 19:; mr 5,4; lwz 3,0x4(3); li 4,13; bl _s8006AA34_13; b 24f; 20:; mr 5,4; lwz 3,0x4(3); li 4,9; bl _s8006AA34_14; b 24f; 21:; mr 5,4; lwz 3,0x4(3); li 4,7; bl _s8006AA34_15; b 24f; 22:; mr 5,4; lwz 3,0x4(3); li 4,16; bl _s8006AA34_16; b 24f; 23:; mr 5,4; lwz 3,0x4(3); li 4,5; bl _s8006AA34_17; 24:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s8006AA34_0();
extern "C" void _s8006AA34_1();
extern "C" void _s8006AA34_2();
extern "C" void _s8006AA34_3();
extern "C" void _s8006AA34_4();
extern "C" void _s8006AA34_5();
extern "C" void _s8006AA34_6();
extern "C" void _s8006AA34_7();
extern "C" void _s8006AA34_8();
extern "C" void _s8006AA34_9();
extern "C" void _s8006AA34_10();
extern "C" void _s8006AA34_11();
extern "C" void _s8006AA34_12();
extern "C" void _s8006AA34_13();
extern "C" void _s8006AA34_14();
extern "C" void _s8006AA34_15();
extern "C" void _s8006AA34_16();
extern "C" void _s8006AA34_17();

struct SAnimator2 {
    void getTurnSkillID();
};

void SAnimator2::getTurnSkillID() {
}
