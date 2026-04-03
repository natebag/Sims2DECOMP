// 0x802D8684 (8 bytes)
class EThread {
public:
    int GetThreadName();
};

int EThread::GetThreadName() {
    return *(int*)((char*)this + 0x32C);
}
