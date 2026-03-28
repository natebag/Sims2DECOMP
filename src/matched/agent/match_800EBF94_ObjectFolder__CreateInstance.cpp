/* ObjectFolder::CreateInstance(void) - 40 bytes */

void* operator new(unsigned int size);

class ObjectFolderImpl;

ObjectFolderImpl* ObjectFolderImpl_ctor(void*);

class ObjectFolder {
public:
    static ObjectFolderImpl* CreateInstance(void);
};

ObjectFolderImpl* ObjectFolder::CreateInstance(void) {
    void* mem = operator new(0x6D4);
    return ObjectFolderImpl_ctor(mem);
}
