/* ObjectModuleImpl::GetFolder(void) - 8 bytes */

static void* s_folder;

class ObjectModuleImpl {
public:
    void* GetFolder(void);
};

void* ObjectModuleImpl::GetFolder(void) {
    return s_folder;
}
