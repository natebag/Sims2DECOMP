/* EModelManager::GetHeap(void) at 0x80324ED4 (32B) */
// 0x80324ED4 (32 bytes)
class EAHeap;
extern EAHeap* ModelHeap();
class EModelManager {
public:
    EAHeap* GetHeap();
};
EAHeap* EModelManager::GetHeap() {
    return ModelHeap();
}
