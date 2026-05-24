// 0x800E318C cXObjectImpl::IsInteractionTile(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x1a8(9); lwz 9,0x1ac(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 2f; lwz 9,0x88(31); lha 11,0x8a(9); cmpwi 11,2; beq 2f; lha 0,0x12(9); cmpwi 0,2; beq 0f; lha 0,0x14(9); cmpwi 0,0; beq 0f; lha 0,0x10(9); cmpwi 0,0; bge 1f; 0:; li 3,1; b 3f; 1:; cmpwi 11,1; beq 2f; lwz 3,0x4(31); li 4,8; lwz 9,0x4(3); lha 0,0x1d0(9); lwz 9,0x1d4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 3,1; bne 3f; 2:; li 3,0; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

struct cXObjectImpl {
    void IsInteractionTile();
};

void cXObjectImpl::IsInteractionTile() {
}
