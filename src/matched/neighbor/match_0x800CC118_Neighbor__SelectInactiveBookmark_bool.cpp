// 0x800CC118 Neighbor::SelectInactiveBookmark(bool, (616 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-136(1); mfspr 0,8; stmw 20,0x58(1); stw 0,0x8c(1); mr 29,3; mr 21,4; addi 22,29,408; mr 23,5; li 28,0; addi 24,1,8; li 20,0; 0:; mulli 11,28,12; rlwinm 0,28,2,0,29; lwz 9,0x194(29); mr 25,0; stwx 20,24,0; li 10,1; add 3,11,9; mr 30,11; lwz 0,0x4(3); cmpwi 0,0; bne 1f; li 10,0; 1:; cmpwi 10,0; beq 10f; bl _s800CC118_0; cmpwi 3,0; bne 10f; lwz 4,0x194(29); mr 3,29; add 4,4,30; bl _s800CC118_1; lha 0,-21222(13); cmpw 3,0; bne 10f; lwz 3,0x194(29); addi 27,28,1; add 3,3,30; bl _s800CC118_2; cmpw 21,3; bne 12f; cmpwi 23,0; beq 2f; lwz 3,0x194(29); add 3,3,30; bl _s800CC118_3; cmpwi 3,0; beq 12f; 2:; lwz 3,0x194(29); add 3,3,30; bl _s800CC118_4; cmpwi 3,0; bne 3f; lwz 3,0x194(29); addi 27,28,1; add 3,3,30; bl _s800CC118_5; cmpwi 3,0; bne 8f; 3:; mr 31,22; addi 27,28,1; addi 28,31,24; li 26,0; 4:; lwz 4,0x0(31); addi 31,31,4; cmpwi 4,0; beq 6f; lwz 0,0x4(4); li 9,1; cmpwi 0,0; bne 5f; li 9,0; 5:; cmpwi 9,0; beq 6f; lwz 3,0x194(29); add 3,3,30; bl _s800CC118_6; cmpwi 3,0; bne 9f; 6:; cmplw 31,28; ble 4b; 7:; cmpwi 26,0; bne 12f; 8:; lwz 4,0x194(29); mr 3,29; add 4,4,30; bl _s800CC118_7; lwz 0,0x194(29); stwx 3,24,25; add 3,0,30; bl _s800CC118_8; cmpwi 3,0; beq 12f; lwz 3,0x194(29); add 3,3,30; bl _s800CC118_9; cmpwi 3,0; bne 12f; lwzx 9,24,25; addi 9,9,1; stwx 9,24,25; b 12f; 9:; li 26,1; b 7b; 10:; lwz 9,0x194(29); li 11,1; add 3,30,9; lwz 0,0x4(3); cmpwi 0,0; bne 11f; li 11,0; 11:; cmpwi 11,0; addi 27,28,1; beq 12f; bl _s800CC118_10; 12:; mr 28,27; cmplwi 28,19; ble 0b; lis 9,-32697; li 27,0; addi 26,9,24012; 13:; lwz 3,0x120(26); addi 4,1,8; li 5,20; bl _s800CC118_11; mr 30,3; cmpwi 30,-1; bne 14f; li 27,1; b 16f; 14:; mulli 31,30,12; lwz 3,0x194(29); mr 4,29; li 5,1; add 3,3,31; bl _s800CC118_12; mr. 28,3; beq 15f; lwz 3,0x194(29); add 3,3,31; b 17f; 15:; lwz 3,0x194(29); add 3,3,31; bl _s800CC118_13; rlwinm 0,30,2,0,29; stwx 28,24,0; 16:; cmpwi 27,0; beq 13b; li 3,0; 17:; lwz 0,0x8c(1); mtspr 8,0; lmw 20,0x58(1); addi 1,1,136"

extern "C" void _s800CC118_0();
extern "C" void _s800CC118_1();
extern "C" void _s800CC118_2();
extern "C" void _s800CC118_3();
extern "C" void _s800CC118_4();
extern "C" void _s800CC118_5();
extern "C" void _s800CC118_6();
extern "C" void _s800CC118_7();
extern "C" void _s800CC118_8();
extern "C" void _s800CC118_9();
extern "C" void _s800CC118_10();
extern "C" void _s800CC118_11();
extern "C" void _s800CC118_12();
extern "C" void _s800CC118_13();

struct Neighbor {
    void SelectInactiveBookmark();
};

void Neighbor::SelectInactiveBookmark() {
}
