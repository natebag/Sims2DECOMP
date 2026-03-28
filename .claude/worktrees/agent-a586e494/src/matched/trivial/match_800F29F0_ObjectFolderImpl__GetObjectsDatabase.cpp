// 0x800F29F0 (8 bytes)
class ObjectFolderImpl {
public:
    int GetObjectsDatabase();
};

int ObjectFolderImpl::GetObjectsDatabase() {
    return *(int*)((char*)this + 0x690);
}
