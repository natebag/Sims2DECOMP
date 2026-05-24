// 0x800CA0E8 Neighbor::CountRelationshipsOfType(tRelationshipType) (288 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 24,4; li 25,0; bl _s800CA0E8_0; li 28,0; mr 31,3; lwz 9,0x0(31); lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; mr 26,3; cmpw 25,26; bge 3f; 0:; lwz 9,0x0(31); mr 4,28; li 27,0; lwz 0,0x64(9); lha 3,0x60(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x0(31); mr 30,3; mr 4,30; lha 3,0x20(9); lwz 0,0x24(9); add 3,31,3; mtspr 8,0; blrl; mr 29,3; cmpwi 29,2; ble 1f; lwz 9,0x0(31); mr 4,30; li 5,2; lha 3,0x40(9); lwz 0,0x44(9); add 3,31,3; mtspr 8,0; blrl; mr 27,3; 1:; cmpwi 29,0; ble 2f; lwz 9,0x0(31); li 5,0; mr 4,30; lha 3,0x40(9); lwz 0,0x44(9); add 3,31,3; mtspr 8,0; blrl; mr 4,27; bl _s800CA0E8_1; mr 4,24; bl _s800CA0E8_2; cmpwi 3,0; beq 2f; addi 25,25,1; 2:; addi 28,28,1; cmpw 28,26; blt 0b; 3:; mr 3,25; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"

extern "C" void _s800CA0E8_0();
extern "C" void _s800CA0E8_1();
extern "C" void _s800CA0E8_2();

struct Neighbor {
    void CountRelationshipsOfType_tRelationshipType();
};

void Neighbor::CountRelationshipsOfType_tRelationshipType() {
}
