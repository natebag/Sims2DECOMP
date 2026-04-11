/* ObjectFolderImpl::Save(iResFile *) - 48 bytes */

struct iResFile;
struct ObjectFolderImpl;

int ReconSaveObject_ObjectFolderImpl(ObjectFolderImpl* obj, iResFile* file, int type, short ver, int flags);

class ObjectFolderImpl {
public:
    int Save(iResFile* file);
};

int ObjectFolderImpl::Save(iResFile* file) {
    return ReconSaveObject_ObjectFolderImpl(this, file, 0x54415454, 1, 0);
}
