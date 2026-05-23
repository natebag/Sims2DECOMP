/* ObjectFolderImpl::Load(iResFile *) at 0x800F12CC (48B) */

void ReconLoadObject_OFI(void* obj, void* file, int tag, short ver, void* out);

struct ObjectFolderImpl_Load {
    void Load(void* file);
};

void ObjectFolderImpl_Load::Load(void* file) {
    ReconLoadObject_OFI(this, file, 0x54415454, 1, 0);
}
