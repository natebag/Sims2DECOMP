/* EAudioSampleManager::GetHeap(void) at 0x8036C33C (32B) */
// 0x8036C33C (32 bytes)
class EAHeap;
extern EAHeap* VMHeap();
class EAudioSampleManager {
public:
    EAHeap* GetHeap();
};
EAHeap* EAudioSampleManager::GetHeap() {
    return VMHeap();
}
