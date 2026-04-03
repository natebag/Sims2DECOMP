// 0x80161BA0 (8 bytes)
class CasListener {
public:
    void SetMediator(int p);
};

void CasListener::SetMediator(int p) {
    *(int*)((char*)this + 0x0) = p;
}
