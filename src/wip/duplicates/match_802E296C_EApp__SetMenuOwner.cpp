// 0x802E296C (8 bytes)
class EApp {
public:
    void SetMenuOwner(int p);
};

void EApp::SetMenuOwner(int p) {
    *(int*)((char*)this + 0x46C) = p;
}
