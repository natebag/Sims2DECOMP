/* EResourceManager::GetHeap(void) at 0x8032758C (32B) */
// 0x8032758C (32 bytes)
class EAHeap;
extern EAHeap* ResourceHeap();
class EResourceManager {
public:
    EAHeap* GetHeap();
};
EAHeap* EResourceManager::GetHeap() {
    return ResourceHeap();
}
