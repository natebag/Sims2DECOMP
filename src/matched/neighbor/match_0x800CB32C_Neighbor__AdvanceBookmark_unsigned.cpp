// 0x800CB32C Neighbor::AdvanceBookmark(unsigned (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 27,0x34(1); stw 0,0x4c(1); mr 27,4; mr 30,3; mulli 9,27,12; lwz 11,0x194(30); addi 7,1,8; li 28,0; lwzx 10,9,11; add 9,9,11; lwz 8,0x4(9); mr 3,9; lwz 0,0x8(9); stw 10,0x8(1); stw 0,0x8(7); stw 8,0x4(7); bl _s800CB32C_0; b 2f; 0:; addi 31,1,24; addi 4,1,8; mr 3,31; mr 5,28; bl _s800CB32C_1; mr 3,30; mr 4,31; bl _s800CB32C_2; cmpwi 3,-1; bne 1f; mr 3,31; mr 4,30; li 5,1; bl _s800CB32C_3; cmpwi 3,0; beq 1f; mr 3,31; bl _s800CB32C_4; addi 4,1,40; addi 5,1,44; bl _s800CB32C_5; lwz 4,0x28(1); mr 3,30; lwz 5,0x2c(1); bl _s800CB32C_6; mr. 29,3; blt 1f; mulli 8,29,12; lwz 7,0x194(30); add 10,8,7; lwz 11,0x18(1); mr 4,30; lwz 0,0x8(31); lwz 9,0x4(31); stwx 11,8,7; stw 0,0x8(10); stw 9,0x4(10); lwz 3,0x194(30); add 3,3,8; bl _s800CB32C_7; cmpwi 3,0; beq 1f; mr 4,29; mr 3,30; bl _s800CB32C_8; 1:; addi 0,28,1; extsh 28,0; 2:; addi 3,1,8; bl _s800CB32C_9; cmpw 28,3; blt 0b; mulli 9,27,12; lwz 11,0x194(30); li 10,1; add 9,9,11; lwz 0,0x4(9); cmpwi 0,0; bne 3f; li 10,0; 3:; cmpwi 10,0; bne 4f; mr 3,30; mr 4,27; bl _s800CB32C_10; 4:; lwz 0,0x4c(1); mtspr 8,0; lmw 27,0x34(1); addi 1,1,72"

extern "C" void _s800CB32C_0();
extern "C" void _s800CB32C_1();
extern "C" void _s800CB32C_2();
extern "C" void _s800CB32C_3();
extern "C" void _s800CB32C_4();
extern "C" void _s800CB32C_5();
extern "C" void _s800CB32C_6();
extern "C" void _s800CB32C_7();
extern "C" void _s800CB32C_8();
extern "C" void _s800CB32C_9();
extern "C" void _s800CB32C_10();

struct Neighbor {
    void AdvanceBookmark();
};

void Neighbor::AdvanceBookmark() {
}
