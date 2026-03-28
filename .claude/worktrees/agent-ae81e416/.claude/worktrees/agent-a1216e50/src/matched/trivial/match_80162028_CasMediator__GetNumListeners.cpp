// 0x80162028 (8 bytes)
class CasMediator {
public:
    int GetNumListeners();
};

int CasMediator::GetNumListeners() {
    return *(int*)((char*)this + 0x8);
}
