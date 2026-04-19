/* ETextureManager::GetHeap(void) at 0x80328658 (32B) */
// 0x80328658 (32 bytes)
class EAHeap;
extern EAHeap* TextureHeap();
class ETextureManager {
public:
    EAHeap* GetHeap();
};
EAHeap* ETextureManager::GetHeap() {
    return TextureHeap();
}
