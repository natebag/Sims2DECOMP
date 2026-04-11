// FLAGS: -fno-elide-constructors
// 0x80118E84 cSamplePatch::~cSamplePatch (64b)
void patch_delete(void*);
void cSamplePatch_dtor(void* self, int mode) {
    patch_cleanup(self);
    if (mode & 1) {
        patch_delete(self);
    }
}
