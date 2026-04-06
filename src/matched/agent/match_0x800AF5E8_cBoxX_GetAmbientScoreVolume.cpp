// 0x800AF5E8 cBoxX::GetAmbientScoreVolume (52b)

extern int GetAmbientScoreVolumeTarget(void*);

struct cBoxX {
    char pad[0x64];
    void* m_ambient;
};

int cBoxX_GetAmbientScoreVolume(cBoxX* self) {
    void* p = self->m_ambient;
    if (!p) return 0;
    return GetAmbientScoreVolumeTarget(p);
}
