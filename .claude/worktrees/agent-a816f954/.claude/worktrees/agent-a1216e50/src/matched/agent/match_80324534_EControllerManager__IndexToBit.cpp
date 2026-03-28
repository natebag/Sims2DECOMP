/* 0x80324534 (12 bytes) - EControllerManager::IndexToBit(int) */
class EControllerManager { public: static int IndexToBit(int idx); };
int EControllerManager::IndexToBit(int idx) { return 1 << idx; }
