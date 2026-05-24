// 0x800CA024 Neighbor::CalculateRelationshipLevel(Neighbor (196 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 30,4; li 28,0; bl _s800CA024_0; lwz 9,0x0(3); lha 4,0x4(30); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; mr 29,3; cmpwi 29,2; ble 0f; mr 3,31; bl _s800CA024_1; lwz 9,0x0(3); li 5,2; lha 4,0x4(30); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; mr 28,3; 0:; cmpwi 29,0; li 3,4; ble 1f; mr 3,31; bl _s800CA024_2; lwz 9,0x0(3); li 5,0; lha 4,0x4(30); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; mr 4,28; bl _s800CA024_3; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s800CA024_0();
extern "C" void _s800CA024_1();
extern "C" void _s800CA024_2();
extern "C" void _s800CA024_3();

struct Neighbor {
    void CalculateRelationshipLevel_Neighbor();
};

void Neighbor::CalculateRelationshipLevel_Neighbor() {
}
