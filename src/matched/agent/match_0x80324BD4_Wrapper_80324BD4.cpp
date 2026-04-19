/* EFlashManager::GetHeap(void) at 0x80324BD4 (32B) */
// 0x80324BD4 (32 bytes)
class EAHeap;
extern EAHeap* VMHeap();
class EFlashManager {
public:
    EAHeap* GetHeap();
};
EAHeap* EFlashManager::GetHeap() {
    return VMHeap();
}
