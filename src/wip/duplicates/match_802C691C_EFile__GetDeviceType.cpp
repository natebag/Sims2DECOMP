// 0x802C691C (8 bytes)
class EFile {
public:
    int GetDeviceType();
};

int EFile::GetDeviceType() {
    return *(int*)((char*)this + 0x10);
}
