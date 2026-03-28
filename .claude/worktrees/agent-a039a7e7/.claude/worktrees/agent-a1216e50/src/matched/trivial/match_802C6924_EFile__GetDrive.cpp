// 0x802C6924 (8 bytes)
class EFile {
public:
    int GetDrive();
};

int EFile::GetDrive() {
    return (int)((char*)this + 0x18);
}
