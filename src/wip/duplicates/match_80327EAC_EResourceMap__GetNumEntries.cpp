// 0x80327EAC (8 bytes)
class EResourceMap {
public:
    int GetNumEntries();
};

int EResourceMap::GetNumEntries() {
    return *(int*)((char*)this + 0x4);
}
