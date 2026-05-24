// 0x800C9E30 Neighbor::RelCountsAsRel(tRelationshipType, (224 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,5; beq 2f; bgt 1f; cmpwi 4,2; beq 3f; bgt 0f; cmpwi 4,1; beq 2f; b 10f; 0:; cmpwi 4,3; beq 4f; cmpwi 4,4; beq 5f; b 10f; 1:; cmpwi 4,7; beq 7f; blt 6f; cmpwi 4,8; beq 8f; cmpwi 4,9; beq 9f; b 10f; 2:; li 3,0; blr; 3:; xori 3,3,2; subfic 0,3,0; adde 3,0,3; blr; 4:; addi 3,3,-2; subfic 3,3,1; li 3,0; adde 3,3,3; blr; 5:; xori 3,3,4; subfic 0,3,0; adde 3,0,3; blr; 6:; addi 3,3,-6; subfic 3,3,3; li 3,0; adde 3,3,3; blr; 7:; xori 3,3,7; subfic 0,3,0; adde 3,0,3; blr; 8:; xori 3,3,8; subfic 0,3,0; adde 3,0,3; blr; 9:; xori 3,3,9; subfic 0,3,0; adde 3,0,3; blr; 10:; li 3,0"

struct Neighbor {
    void RelCountsAsRel_tRelationshipType();
};

void Neighbor::RelCountsAsRel_tRelationshipType() {
}
