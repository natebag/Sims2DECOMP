/* ESoundEventManager::GetHeap(void) at 0x80328374 (32B) */
// 0x80328374 (32 bytes)

class EAHeap;
extern EAHeap* AudioHeap();

class ESoundEventManager {
public:
    EAHeap* GetHeap();
};

EAHeap* ESoundEventManager::GetHeap() {
    return AudioHeap();
}
