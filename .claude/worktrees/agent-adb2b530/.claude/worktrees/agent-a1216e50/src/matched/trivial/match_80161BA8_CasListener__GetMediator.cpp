// 0x80161BA8 (8 bytes)
class CasListener {
public:
    int GetMediator();
};

int CasListener::GetMediator() {
    return *(int*)((char*)this + 0x0);
}
