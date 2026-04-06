// FLAGS: -msdata=eabi -G 8
// 0x8007CE20 CTGFileImpl::~CTGFileImpl (100b)
extern int CTGFileImpl_VTable[];
extern void FileClose(void*);
extern void CTGFileImpl_FlushCache(void*);
extern void CTGFile_dtor(void*, int);

struct CTGFileImpl {
    int* vtable;
    char pad[268];
    void* file;
};

void CTGFileImpl_dtor(CTGFileImpl* self, int flags) {
    self->vtable = CTGFileImpl_VTable;
    if (self->file != 0) {
        FileClose(self->file);
    }
    self->file = 0;
    CTGFileImpl_FlushCache(self);
    CTGFile_dtor(self, flags);
}
