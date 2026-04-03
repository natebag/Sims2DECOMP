// 0x80035338 (8 bytes)
class ESim {
public:
    int GetSimModel();
};

int ESim::GetSimModel() {
    return *(int*)((char*)this + 0x63C);
}
