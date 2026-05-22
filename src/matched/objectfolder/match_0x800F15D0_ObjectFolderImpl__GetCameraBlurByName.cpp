// 0x800F15D0 ObjectFolderImpl::GetCameraBlurByName(char*) (88B)
// ASMPROC_swap_adj: a=lwz b=lis which=0

class ERQuickdata {
public:
    void* getTable(char* name);
    void* getRow(void* table, char* name);
};

extern char s_cameraBlurTableName[];   // 0x803DB508

class ObjectFolderImpl {
public:
    char pad_000[1680];
    ERQuickdata* m_qd;
    void* GetCameraBlurByName(char* name);
};

extern char s_cameraBlurName_alt[16];   // 0x803DB508 sized for HA/LO

void* ObjectFolderImpl::GetCameraBlurByName(char* name) {
    void* row;
    void* table = m_qd->getTable(s_cameraBlurName_alt);
    row = m_qd->getRow(table, name);
    if (row != 0) return row;
    return 0;
}
