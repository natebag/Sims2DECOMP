// 0x802D7A00 (8 bytes)
class ESemaphore {
public:
    int GetMaxCount();
};

int ESemaphore::GetMaxCount() {
    return *(int*)((char*)this + 0x8);
}
