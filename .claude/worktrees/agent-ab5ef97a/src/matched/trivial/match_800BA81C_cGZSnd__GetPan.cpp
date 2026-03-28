// 0x800BA81C (8 bytes)
class cGZSnd {
public:
    int GetPan();
};

int cGZSnd::GetPan() {
    return *(int*)((char*)this + 0x24);
}
