// 0x8006AD80 SAnimator2::getWalkRunSkillID(AnimRef (424 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0x108(31); cmpwi 0,2; bne 0f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x218(9); lwz 9,0x21c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 5f; lwz 3,0x4(31); mr 5,30; li 4,18; b 9f; 0:; cmpwi 0,3; bne 1f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x218(9); lwz 9,0x21c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 5f; b 8f; 1:; cmpwi 0,1; beq 2f; cmpwi 0,8; bne 4f; 2:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x218(9); lwz 9,0x21c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 3f; lwz 3,0x4(31); mr 5,30; li 4,73; bl _s8006AD80_0; b 11f; 3:; lwz 3,0x4(31); mr 5,30; li 4,21; bl _s8006AD80_1; b 11f; 4:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x218(9); lwz 9,0x21c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 6f; 5:; lwz 3,0x4(31); mr 5,30; li 4,74; bl _s8006AD80_2; b 11f; 6:; lbz 0,0x5f9(31); cmpwi 0,5; beq 7f; cmpwi 0,9; beq 8f; b 10f; 7:; lwz 3,0x4(31); mr 5,30; li 4,18; b 9f; 8:; lwz 3,0x4(31); mr 5,30; li 4,59; 9:; bl _s8006AD80_3; lwz 9,0x0(30); lis 3,-32693; addi 3,3,11064; lwz 4,0x0(9); bl _s8006AD80_4; cmpwi 3,0; bne 11f; lwz 3,0x4(31); mr 5,30; li 4,20; bl _s8006AD80_5; b 11f; 10:; lwz 3,0x4(31); mr 5,30; li 4,20; bl _s8006AD80_6; 11:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8006AD80_0();
extern "C" void _s8006AD80_1();
extern "C" void _s8006AD80_2();
extern "C" void _s8006AD80_3();
extern "C" void _s8006AD80_4();
extern "C" void _s8006AD80_5();
extern "C" void _s8006AD80_6();

struct SAnimator2 {
    void getWalkRunSkillID();
};

void SAnimator2::getWalkRunSkillID() {
}
