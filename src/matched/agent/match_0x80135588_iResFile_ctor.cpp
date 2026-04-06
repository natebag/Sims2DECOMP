// 0x80135588 iResFile::iResFile (80b)
extern int g_vtable_iResFile[8];
void iResFile_initBase(void*);
void iResFile_setType(void*, int);

void* iResFile_ctor(void* self) {
    *(void**)((char*)self + 12) = (void*)g_vtable_iResFile;
    *(int*)((char*)self + 8) = 0;
    iResFile_initBase(self);
    iResFile_setType(self, 0);
    return self;
}
