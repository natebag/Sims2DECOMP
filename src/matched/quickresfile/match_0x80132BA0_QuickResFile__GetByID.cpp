// 0x80132BA0 (8B) QuickResFile::GetByID — stub returning NULL

class QuickResFile {
public:
    void* GetByID(int, short, void (*)(void*, int));
};

void* QuickResFile::GetByID(int, short, void (*)(void*, int)) {
    return 0;
}
