// 0x803235E0 EControllerManager::GetPlayerMapped(unsigned (16 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 4,4,2,0,29; addi 3,3,16; lwzx 3,3,4"

struct EControllerManager {
    void GetPlayerMapped();
};

void EControllerManager::GetPlayerMapped() {
}
