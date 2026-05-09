// PRAGMA_STUB: ERAnim::Refresh(EFile *)
// 0x80367F3C ERAnim::Refresh (40b)

extern void ERAnim_RefreshImpl(void*, void*);

void ERAnim_Refresh(void* self, void* file) {
    if (file) {
        ERAnim_RefreshImpl(self, file);
    }
}
