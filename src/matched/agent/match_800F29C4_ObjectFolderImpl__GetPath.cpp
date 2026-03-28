/* ObjectFolderImpl::GetPath(void) - 36 bytes */

struct BString {
    char* c_str(void);
};

class ObjectFolderImpl {
public:
    char pad[0x550];
    BString m_path;

    char* GetPath(void);
};

char* ObjectFolderImpl::GetPath(void) {
    return m_path.c_str();
}
