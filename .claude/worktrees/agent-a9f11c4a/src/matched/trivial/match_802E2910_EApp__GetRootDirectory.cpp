// 0x802E2910 (8 bytes)
class EApp {
public:
    int GetRootDirectory();
};

int EApp::GetRootDirectory() {
    return *(int*)((char*)(*(int*)((char*)this + 0x470)) + 0x0);
}
