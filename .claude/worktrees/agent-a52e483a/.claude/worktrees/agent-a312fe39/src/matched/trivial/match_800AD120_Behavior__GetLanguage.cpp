// 0x800AD120 (8 bytes)
class Behavior {
public:
    int GetLanguage();
};

int Behavior::GetLanguage() {
    return *(int*)((char*)this + 0x8);
}
