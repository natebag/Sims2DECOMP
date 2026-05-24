// 0x8020109C RELTarget::SetupRelationshipInformation(void) (576 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 22,0x20(1); stw 0,0x4c(1); mr 27,3; lis 9,-32697; lwz 3,0x9c(27); addi 9,9,24012; addi 9,9,188; li 11,0; rlwinm 0,3,2,0,29; lwzx 31,9,0; stw 11,0x88(27); cmpwi 31,0; beq 7f; addi 29,1,8; stw 11,0x8(1); stw 11,0x4(29); addi 9,29,8; stw 11,0x4(9); mr 4,31; mr 5,29; mr 22,29; bl _s8020109C_0; li 25,0; lwz 10,0x0(31); li 26,0; lwz 30,-21476(13); lwz 9,0x4(10); lwz 11,0x0(30); lha 3,0x310(9); lwz 9,0x314(9); addi 28,11,192; add 3,10,3; lha 0,0xc0(11); mtspr 8,9; add 30,30,0; blrl; lwz 0,0x4(28); lwz 4,0x1c(3); mtspr 8,0; mr 3,30; blrl; lwz 9,0x8(1); mr 23,3; lwz 0,0x4(29); subf 0,9,0; srawi. 9,0,2; ble 5f; li 24,0; 0:; lwz 10,-21476(13); li 4,19; lwz 9,0x8(1); lwz 11,0x0(10); lwzx 31,9,24; lwz 0,0x124(11); lha 3,0x120(11); mtspr 8,0; add 3,10,3; blrl; mr 29,3; lwz 30,0x0(29); mr 3,31; lha 0,0x58(30); addi 30,30,88; add 29,29,0; bl _s8020109C_1; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr. 30,3; bne 4f; li 3,32; bl _s8020109C_2; mr 28,3; stw 30,0x10(28); addi 3,28,20; stw 30,0x0(28); stw 30,0x4(28); stw 30,0x8(28); stw 30,0xc(28); bl _s8020109C_3; addi 3,28,24; bl _s8020109C_4; lwz 0,0x84(27); cmpwi 0,0; beq 1f; stw 28,0x4(25); stw 25,0x0(28); b 2f; 1:; stw 28,0x84(27); 2:; mr 25,28; lwz 9,0x88(27); mr 3,23; mr 4,31; addi 5,28,28; addi 9,9,1; stw 9,0x88(27); bl _s8020109C_5; mr. 3,3; bne 3f; stw 3,0x1c(28); 3:; mr 3,31; addi 30,28,20; bl _s8020109C_6; addi 29,28,24; stw 3,0x8(28); lwz 3,0xc(31); bl _s8020109C_7; mr 4,3; mr 3,30; bl _s8020109C_8; lwz 3,0xc(31); bl _s8020109C_9; mr 4,3; mr 3,29; bl _s8020109C_10; stw 31,0xc(28); 4:; lwz 0,0x4(22); addi 26,26,1; lwz 9,0x8(1); addi 24,24,4; subf 0,9,0; srawi 0,0,2; cmpw 26,0; blt 0b; 5:; lwz 3,0x8(1); cmpwi 3,0; beq 7f; lwz 0,0xc(22); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 6f; bl _s8020109C_11; b 7f; 6:; bl _s8020109C_12; 7:; lwz 0,0x4c(1); mtspr 8,0; lmw 22,0x20(1); addi 1,1,72"

extern "C" void _s8020109C_0();
extern "C" void _s8020109C_1();
extern "C" void _s8020109C_2();
extern "C" void _s8020109C_3();
extern "C" void _s8020109C_4();
extern "C" void _s8020109C_5();
extern "C" void _s8020109C_6();
extern "C" void _s8020109C_7();
extern "C" void _s8020109C_8();
extern "C" void _s8020109C_9();
extern "C" void _s8020109C_10();
extern "C" void _s8020109C_11();
extern "C" void _s8020109C_12();

struct RELTarget {
    void SetupRelationshipInformation();
};

void RELTarget::SetupRelationshipInformation() {
}
