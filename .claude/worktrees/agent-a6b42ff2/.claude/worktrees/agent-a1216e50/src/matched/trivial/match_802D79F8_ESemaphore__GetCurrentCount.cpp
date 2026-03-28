// 0x802D79F8 (8 bytes)
class ESemaphore {
public:
    int GetCurrentCount();
};

int ESemaphore::GetCurrentCount() {
    return *(int*)((char*)this + 0xC);
}
