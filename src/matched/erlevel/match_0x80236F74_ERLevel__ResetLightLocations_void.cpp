// 0x80236F74 ERLevel::ResetLightLocations(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); addis 3,3,3; lwz 30,-24204(3); cmpwi 30,0; beq 4f; 0:; lwz 31,0x0(30); lwz 0,0x1c(31); cmpwi 0,0; beq 1f; lwz 3,0x28(31); li 4,1; addi 5,1,8; addi 6,1,10; mtspr 8,0; blrl; b 2f; 1:; sth 0,0x8(1); sth 0,0xa(1); 2:; lwz 0,0x20(31); cmpwi 0,0; beq 3f; lwz 3,0x24(31); li 4,1; addi 5,1,8; addi 6,1,10; mtspr 8,0; blrl; 3:; lwz 30,0x8(30); cmpwi 30,0; bne 0b; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

struct ERLevel {
    void ResetLightLocations();
};

void ERLevel::ResetLightLocations() {
}
