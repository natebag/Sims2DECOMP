/* EShaderManager::GetHeap(void) at 0x803281DC (32B) */
// 0x803281DC (32 bytes)
class EAHeap;
extern EAHeap* VMHeap();
class EShaderManager {
public:
    EAHeap* GetHeap();
};
EAHeap* EShaderManager::GetHeap() {
    return VMHeap();
}
