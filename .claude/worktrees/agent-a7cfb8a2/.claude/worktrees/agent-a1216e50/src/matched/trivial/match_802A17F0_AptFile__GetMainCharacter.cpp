// 0x802A17F0 (8 bytes)
class AptFile {
public:
    int GetMainCharacter();
};

int AptFile::GetMainCharacter() {
    return *(int*)((char*)this + 0x10);
}
