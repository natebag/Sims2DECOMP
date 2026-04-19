/* EQuickdataManager::GetHeap(void) at 0x8032526C (32B) */
// 0x8032526C (32 bytes)
class EAHeap;
extern EAHeap* VMHeap();
class EQuickdataManager {
public:
    EAHeap* GetHeap();
};
EAHeap* EQuickdataManager::GetHeap() {
    return VMHeap();
}
