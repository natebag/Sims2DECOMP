// 0x802C6C74 (8 bytes)
class EFileSystem {
public:
    class FileCreator {
    public:
        int GetCreatorCB();
    };
};

int EFileSystem::FileCreator::GetCreatorCB() {
    return *(int*)((char*)this + 0x0);
}
