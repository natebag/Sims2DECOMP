// FLAGS: -fno-schedule-insns
// 0x803235E0 EControllerManager::GetPlayerMapped(unsigned) (16B)
// slwi r4,r4,2; addi r3,r3,16; lwzx r3,r3,r4; blr  -- m_playerMap[i] (inline array @0x10)
struct EControllerManager {
    char pad[0x10];
    unsigned m_playerMap[8];    // 0x10
    unsigned GetPlayerMapped(unsigned i);
};

unsigned EControllerManager::GetPlayerMapped(unsigned i) {
    return m_playerMap[i];
}
