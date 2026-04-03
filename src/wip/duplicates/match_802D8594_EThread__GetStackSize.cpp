// 0x802D8594 (8 bytes)
class EThread {
public:
    int GetStackSize();
};

int EThread::GetStackSize() {
    return *(int*)((char*)this + 0x320);
}
