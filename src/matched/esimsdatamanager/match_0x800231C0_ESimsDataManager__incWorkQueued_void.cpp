// 0x800231C0 ESimsDataManager::incWorkQueued(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; li 4,-1; stw 30,0x8(1); lwz 9,0x0(30); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0xd2c(30); lwz 10,0x8(1); addi 9,9,1; stw 9,0xd2c(30); lwz 11,0x0(10); lha 3,0x18(11); lwz 0,0x1c(11); add 3,10,3; mtspr 8,0; blrl; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

struct ESimsDataManager {
    void incWorkQueued();
};

void ESimsDataManager::incWorkQueued() {
}
