/* EBinaryManager::GetHeap(void) at 0x803230A4 (32B) */
// 0x803230A4 (32 bytes)
class EAHeap;
extern EAHeap* VMHeap();
class EBinaryManager {
public:
    EAHeap* GetHeap();
};
EAHeap* EBinaryManager::GetHeap() {
    return VMHeap();
}
