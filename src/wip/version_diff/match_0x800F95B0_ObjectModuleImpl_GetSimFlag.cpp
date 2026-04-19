// 0x800F95B0 (40B) ObjectModuleImpl::GetSimFlag(int, ObjectModule::SimFlag)

struct ObjectModuleImpl {
    char pad[28];
    unsigned int* m_arr;
    bool GetSimFlag(int idx, unsigned short flag);
};

bool ObjectModuleImpl::GetSimFlag(int idx, unsigned short flag) {
    int i = idx - 1;
    unsigned int v = m_arr[i];
    unsigned int mask = (unsigned int)flag << 16;
    if (v & mask) return 1;
    return 0;
}
