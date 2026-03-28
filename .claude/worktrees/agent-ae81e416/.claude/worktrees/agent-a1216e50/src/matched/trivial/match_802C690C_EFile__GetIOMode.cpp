// 0x802C690C (8 bytes)
class EFile {
public:
    int GetIOMode();
};

int EFile::GetIOMode() {
    return *(int*)((char*)this + 0x8);
}
