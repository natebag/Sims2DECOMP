// FLAGS: -fno-elide-constructors
// 0x80119050 cSamplePatch::CreateChannel (56b)
void* patch_ch_ctor(void*, void*);

void* CreateChannel_test(void* self) {
    void* mem = patch_new(8);
    return patch_ch_ctor(mem, self);
}
