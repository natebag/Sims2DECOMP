// FLAGS: -fno-schedule-insns
// 0x80324534 EControllerManager::IndexToBit(int) (12B)
// li r0,1; slw r3,r0,r3; blr  -- static: 1 << index
struct EControllerManager {
    static int IndexToBit(int index);
};

int EControllerManager::IndexToBit(int index) {
    return 1 << index;
}
