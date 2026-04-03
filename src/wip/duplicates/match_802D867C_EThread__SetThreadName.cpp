// 0x802D867C (8 bytes)
class EThread {
public:
    void SetThreadName(int p);
};

void EThread::SetThreadName(int p) {
    *(int*)((char*)this + 0x32C) = p;
}
