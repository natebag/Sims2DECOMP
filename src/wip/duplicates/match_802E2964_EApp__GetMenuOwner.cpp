// 0x802E2964 (8 bytes)
class EApp {
public:
    int GetMenuOwner();
};

int EApp::GetMenuOwner() {
    return *(int*)((char*)this + 0x46C);
}
