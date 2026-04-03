// TreeTableEntryQuickData::Release(void)
// Address: 0x8022BA50 | Size: 92 bytes

extern int TreeTableEntryQuickData_vtable[];

extern void TTEQRelease_cleanup(void* self);
extern void TTEQRelease_release(void* self, int flag);
extern void* TTEQRelease_getsize(void);
extern void TTEQRelease_free(void* size, void* self);

void TreeTableEntryQuickData_Release(void* self, int flags) {
    *(int**)self = TreeTableEntryQuickData_vtable;
    TTEQRelease_cleanup(self);
    TTEQRelease_release(self, 0);
    if (flags & 1) {
        void* sz = TTEQRelease_getsize();
        TTEQRelease_free(sz, self);
    }
}
