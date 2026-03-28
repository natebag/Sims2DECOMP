/* ObjectModuleImpl::GetSelectedPerson(int) - 36 bytes */

static void* s_selectionManager;

void* GetSelectedPerson(void* mgr, int index);

class ObjectModuleImpl {
public:
    void* GetSelectedPerson(int index);
};

void* ObjectModuleImpl::GetSelectedPerson(int index) {
    return ::GetSelectedPerson(s_selectionManager, index);
}
