// 0x800F29E8 (8 bytes)
class ObjectFolderImpl {
public:
    int GetBehaviorFinder();
};

int ObjectFolderImpl::GetBehaviorFinder() {
    return (int)((char*)this + 0x4);
}
