typedef unsigned char u8;

extern void lockCarryArmNodes(u8* self, int flags, u8* global);
extern u8* g_lockCarryGlobal;

void SAnimator2_lockHandsUpCarryNodes(u8* self) {
    volatile u8* data = *(volatile u8**)(self + 8);
    volatile u8* ptr = *(volatile u8**)((u8*)data + 0x358);
    (void)ptr;
    lockCarryArmNodes((u8*)data + 0x334, 0x800, g_lockCarryGlobal);
}
