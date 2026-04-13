// 0x800F95D8 ObjectModuleImpl::GetIdleStatus (24B)

struct ObjectModuleImpl_GIS {
    char pad[0x1C];
    int* m_idleTable;
    short GetIdleStatus(int index);
};

short ObjectModuleImpl_GIS::GetIdleStatus(int index) {
    short* p = (short*)((char*)m_idleTable + (index - 1) * 4);
    return p[1];
}
