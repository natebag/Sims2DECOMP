/* ObjectFolderImpl::Save(iResFile *) at 0x800F129C (48B) */

void ReconSaveObject_OFI(void* obj, void* file, int tag, short ver, int flags);

struct ObjectFolderImpl_Save {
    void Save(void* file);
};

void ObjectFolderImpl_Save::Save(void* file) {
    ReconSaveObject_OFI(this, file, 0x54415454, 1, 0);
}
