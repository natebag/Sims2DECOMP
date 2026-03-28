// 0x802D858C (8 bytes)
class EThread {
public:
    int GetStack();
};

int EThread::GetStack() {
    return *(int*)((char*)this + 0x31C);
}
