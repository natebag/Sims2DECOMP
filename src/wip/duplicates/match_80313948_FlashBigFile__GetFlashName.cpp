// 0x80313948 (8 bytes)
class FlashBigFile {
public:
    int GetFlashName();
};

int FlashBigFile::GetFlashName() {
    return (int)((char*)(*(int*)((char*)this + 0x0)) + 0x18);
}
