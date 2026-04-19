/* EAmbientScoreManager::GetHeap(void) at 0x80322BA0 (32B) */
// 0x80322BA0 (32 bytes)
class EAHeap;
extern EAHeap* VMHeap();
class EAmbientScoreManager {
public:
    EAHeap* GetHeap();
};
EAHeap* EAmbientScoreManager::GetHeap() {
    return VMHeap();
}
