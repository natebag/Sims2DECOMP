// 0x8002F264 ERoom::ProcessCell(TNodeList<ERoomWall (632 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 20,0x10(1); stw 0,0x44(1); mr 27,9; mr 20,3; mr 21,4; mr 31,5; mr 29,6; mr 26,8; mr 23,10; mr 4,7; stw 7,0x8(1); mr 3,27; lwz 22,0x48(1); lwz 24,0x4c(1); lwz 28,0x50(1); bl _s8002F264_0; mr. 25,3; beq 1f; lwz 4,0x8(1); mr 3,27; bl _s8002F264_1; cmpwi 3,2; beq 0f; cmpwi 3,12; beq 0f; cmpwi 3,13; beq 0f; cmpwi 3,14; bne 1f; 0:; li 30,1; b 2f; 1:; li 30,0; 2:; cmpwi 25,0; beq 10f; cmpwi 30,0; bne 11f; lwz 0,0x0(31); cmpwi 0,0; bne 3f; cmpwi 28,0; bne 4f; b 6f; 3:; lis 9,-32702; rlwinm 0,23,2,0,29; addi 9,9,14888; mr 3,27; lwzx 0,9,0; mr 4,29; mtspr 8,0; blrl; cmpwi 3,0; beq 8f; cmpwi 28,0; beq 5f; 4:; li 3,64; bl _s8002F264_2; lwz 4,0x8(1); mr 5,26; mr 6,29; mr 7,28; bl _s8002F264_3; mr 4,3; stw 4,0x0(31); mr 3,21; bl _s8002F264_4; b 7f; 5:; lwz 11,0x0(31); cmpwi 11,0; beq 6f; lwz 9,0x3c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 6:; stw 30,0x0(31); li 3,64; bl _s8002F264_5; lwz 4,0x8(1); mr 5,26; mr 6,29; li 7,0; bl _s8002F264_6; stw 3,0x0(31); 7:; lwz 9,0x0(22); addi 9,9,1; stw 9,0x0(22); lwz 11,0x0(24); addi 11,11,1; stw 11,0x0(24); b 17f; 8:; cmpwi 28,0; beq 9f; lwz 3,0x0(31); mr 4,29; lwz 6,0x8(1); mr 5,27; mr 7,26; mr 8,28; bl _s8002F264_7; 9:; lwz 9,0x0(24); addi 9,9,1; stw 9,0x0(24); b 17f; 10:; cmpwi 30,0; beq 15f; 11:; cmpwi 28,0; beq 12f; lwz 4,0x8(1); addi 0,4,-1; cmplwi 0,1; ble 14f; mr 3,27; bl _s8002F264_8; mr 30,3; li 3,64; bl _s8002F264_9; addi 4,1,8; mr 5,29; mr 6,30; bl _s8002F264_10; mr 4,3; addi 3,20,100; bl _s8002F264_11; b 14f; 12:; lwz 11,0x0(31); cmpwi 11,0; beq 13f; lwz 9,0x3c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; 13:; stw 28,0x0(31); 14:; li 0,0; stw 0,0x0(31); b 17f; 15:; lwz 11,0x0(31); cmpwi 11,0; beq 17f; cmpwi 28,0; bne 16f; lwz 9,0x3c(11); lha 3,0x10(9); lwz 0,0x14(9); add 3,11,3; mtspr 8,0; blrl; stw 30,0x0(31); 16:; stw 30,0x0(31); 17:; lwz 0,0x44(1); mtspr 8,0; lmw 20,0x10(1); addi 1,1,64"

extern "C" void _s8002F264_0();
extern "C" void _s8002F264_1();
extern "C" void _s8002F264_2();
extern "C" void _s8002F264_3();
extern "C" void _s8002F264_4();
extern "C" void _s8002F264_5();
extern "C" void _s8002F264_6();
extern "C" void _s8002F264_7();
extern "C" void _s8002F264_8();
extern "C" void _s8002F264_9();
extern "C" void _s8002F264_10();
extern "C" void _s8002F264_11();

struct ERoom {
    void ProcessCell_TNodeList_ERoomWall();
};

void ERoom::ProcessCell_TNodeList_ERoomWall() {
}
