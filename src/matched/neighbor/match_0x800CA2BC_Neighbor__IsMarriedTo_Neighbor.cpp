// 0x800CA2BC Neighbor::IsMarriedTo(Neighbor (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr. 30,4; beq 0f; lwz 3,0x10(31); lha 4,0x4(30); lwz 9,0x0(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,3; ble 0f; lwz 3,0x10(31); li 5,3; lha 4,0x4(30); lwz 9,0x0(3); lha 0,0x40(9); lwz 9,0x44(9); add 3,3,0; mtspr 8,9; blrl; andi. 0,3,16; li 3,1; bne 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

struct Neighbor {
    void IsMarriedTo_Neighbor();
};

void Neighbor::IsMarriedTo_Neighbor() {
}
