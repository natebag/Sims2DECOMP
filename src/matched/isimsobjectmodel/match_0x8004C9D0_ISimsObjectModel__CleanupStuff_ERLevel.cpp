// 0x8004C9D0 ISimsObjectModel::CleanupStuff(ERLevel (524 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 29,3; mr 27,4; lwz 4,0x3bc(29); cmpwi 4,0; beq 0f; mr 3,27; bl _s8004C9D0_0; 0:; lwz 4,0x3c0(29); cmpwi 4,0; beq 1f; mr 3,27; bl _s8004C9D0_1; 1:; addi 9,29,1124; addi 26,29,1088; lwz 0,0x4(9); mr 28,9; cmpwi 0,0; ble 3f; mr 31,0; li 30,0; 2:; lwz 9,0x464(29); mr 3,27; lwzx 4,9,30; addi 30,30,4; bl _s8004C9D0_2; addic. 31,31,-1; bne 2b; 3:; mr 3,28; bl _s8004C9D0_3; lwz 0,0x44c(29); cmpwi 0,0; beq 5f; cmpw 0,29; beq 5f; lwz 9,0x0(29); lha 3,0x1a0(9); lwz 0,0x1a4(9); add 3,29,3; mtspr 8,0; blrl; mr 4,3; mr 3,27; bl _s8004C9D0_4; lwz 11,0x44c(29); cmpwi 11,0; beq 4f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 4:; li 0,0; stw 0,0x44c(29); 5:; lwz 11,0x3bc(29); cmpwi 11,0; beq 6f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 6:; lwz 11,0x3c0(29); li 31,0; stw 31,0x3bc(29); cmpwi 11,0; beq 7f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 7:; stw 31,0x3c0(29); lwz 9,0x4(26); b 10f; 8:; lwz 0,0x8(26); lwz 3,0x0(9); cmpwi 0,0; lwz 31,0x4(9); beq 9f; cmpwi 3,0; beq 9f; li 4,3; bl _s8004C9D0_5; 9:; mr 9,31; 10:; li 0,1; cmpwi 9,0; bne 11f; li 0,0; 11:; cmpwi 0,0; bne 8b; mr 3,26; bl _s8004C9D0_6; lwz 4,0x460(29); cmpwi 4,0; beq 12f; mr 3,27; bl _s8004C9D0_7; lwz 11,0x460(29); cmpwi 11,0; beq 12f; lwz 9,0x0(11); li 4,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,11,3; mtspr 8,0; blrl; 12:; lwz 4,0x4b4(29); li 31,0; stw 31,0x460(29); cmpwi 4,0; beq 13f; lis 3,-32693; addi 3,3,11064; bl _s8004C9D0_8; stw 31,0x4b4(29); 13:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s8004C9D0_0();
extern "C" void _s8004C9D0_1();
extern "C" void _s8004C9D0_2();
extern "C" void _s8004C9D0_3();
extern "C" void _s8004C9D0_4();
extern "C" void _s8004C9D0_5();
extern "C" void _s8004C9D0_6();
extern "C" void _s8004C9D0_7();
extern "C" void _s8004C9D0_8();

struct ISimsObjectModel {
    void CleanupStuff_ERLevel();
};

void ISimsObjectModel::CleanupStuff_ERLevel() {
}
