/* ObjectFolderImpl::GetObjectsDatabase(void) - 8 bytes */

class ObjectFolderImpl {
public:
    char pad[0x690];
    void* m_objectsDatabase;

    void* GetObjectsDatabase(void);
};

void* ObjectFolderImpl::GetObjectsDatabase(void) {
    return m_objectsDatabase;
}
