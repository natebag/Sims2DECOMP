// 0x801E7090 (8 bytes)
class M2MTarget {
public:
    int GetPlayerNum();
};

int M2MTarget::GetPlayerNum() {
    return *(int*)((char*)this + 0x190);
}
