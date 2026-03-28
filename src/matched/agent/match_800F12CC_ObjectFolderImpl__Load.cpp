/* ObjectFolderImpl::Load(iResFile *) - 48 bytes */

struct iResFile;
struct ObjectFolderImpl;

int ReconLoadObject_ObjectFolderImpl(ObjectFolderImpl* obj, iResFile* file, int type, short ver, int flags);

class ObjectFolderImpl {
public:
    int Load(iResFile* file);
};

int ObjectFolderImpl::Load(iResFile* file) {
    return ReconLoadObject_ObjectFolderImpl(this, file, 0x54415454, 1, 0);
}
