// 0x80143398 SpriteSlot::ActivateForTicks(int) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0x10(31); cmpwi 0,0; beq 0f; lwz 0,0x48(31); andi. 9,0,16; bne 0f; lwz 0,0x18(31); cmpwi 0,0; bne 0f; lwz 0,0x1c(31); cmpwi 0,0; bne 0f; lwz 11,0x64(31); cmpwi 11,0; beq 0f; lwz 9,0x4(11); lha 3,0x368(9); lwz 0,0x36c(9); add 3,11,3; mtspr 8,0; blrl; 0:; li 0,0; stw 30,0x10(31); stw 0,0x38(31); cmpwi 30,-1; bne 1f; stw 0,0x14(31); b 2f; 1:; stw 30,0x14(31); 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

struct SpriteSlot {
    void ActivateForTicks();
};

void SpriteSlot::ActivateForTicks() {
}
