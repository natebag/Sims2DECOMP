// 0x80023230 ESimsDataManager::decWorkQueued(void) (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; li 4,-1; stw 31,0x8(1); lwz 9,0x0(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,31,3; mtspr 8,0; blrl; lwz 9,0xd2c(31); addi 9,9,-1; stw 9,0xd2c(31); cmpwi 9,0; bne 0f; stw 9,0xd20(31); 0:; lwz 3,0x8(1); lwz 9,0x0(3); lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"

struct ESimsDataManager {
    void decWorkQueued();
};

void ESimsDataManager::decWorkQueued() {
}
