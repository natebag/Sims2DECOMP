/* EAnimManager::GetHeap(void) at 0x80322D24 (32B) */
// 0x80322D24 (32 bytes)
class EAHeap;
extern EAHeap* VMHeap();
class EAnimManager {
public:
    EAHeap* GetHeap();
};
EAHeap* EAnimManager::GetHeap() {
    return VMHeap();
}
