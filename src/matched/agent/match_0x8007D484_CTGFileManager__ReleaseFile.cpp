// 0x8007D484 CTGFileManager::ReleaseFile(CTGFile*) (64B)
struct CTGFileManager;

struct VTable {
    char pad[8];
    short m_adj;
    short m_pad;
    void (*m_fn)(void*, int);
};

struct CTGFile {
    VTable* m_vt;
};

void CTGFileManager__ReleaseFile(CTGFileManager* self, CTGFile* file) {
    if (file == 0) return;
    VTable* vt = file->m_vt;
    vt->m_fn((char*)file + vt->m_adj, 3);
}
