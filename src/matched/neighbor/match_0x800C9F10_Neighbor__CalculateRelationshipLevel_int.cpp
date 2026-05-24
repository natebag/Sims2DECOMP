// 0x800C9F10 Neighbor::CalculateRelationshipLevel(int, (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 0,-31964(13); mr 31,3; mr 30,4; cmpwi 0,0; bne 0f; bl _s800C9F10_0; li 0,1; stw 0,-31964(13); 0:; lis 9,-32696; lwz 0,0x62b0(9); cmpw 31,0; blt 1f; lis 9,-32696; lwz 0,0x62d8(9); cmpw 31,0; bgt 1f; mr 3,30; li 4,5; bl _s800C9F10_1; lwz 0,-24332(13); cmpw 3,0; blt 1f; li 3,9; b 5f; 1:; lis 9,-32696; lwz 0,0x62ac(9); cmpw 31,0; blt 2f; lis 9,-32696; lwz 0,0x62d4(9); cmpw 31,0; bgt 2f; mr 3,30; li 4,6; bl _s800C9F10_2; lwz 0,-24336(13); cmpw 3,0; blt 2f; li 3,8; b 5f; 2:; li 0,6; lis 9,-32696; mtspr 9,0; lis 11,-32696; addi 9,9,25228; addi 11,11,25268; li 3,2; li 10,8; 3:; cmpwi 3,5; beq 4f; lwzx 0,10,9; cmpw 31,0; blt 4f; lwzx 0,10,11; cmpw 31,0; ble 5f; 4:; addi 10,10,4; addi 3,3,1; bdnz 3b; li 3,4; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800C9F10_0();
extern "C" void _s800C9F10_1();
extern "C" void _s800C9F10_2();

struct Neighbor {
    void CalculateRelationshipLevel();
};

void Neighbor::CalculateRelationshipLevel() {
}
