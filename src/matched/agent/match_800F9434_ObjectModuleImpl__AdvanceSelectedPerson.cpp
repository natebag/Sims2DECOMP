/* ObjectModuleImpl::AdvanceSelectedPerson(int) - 40 bytes */

static void* s_selectionManager;

void AdvanceSelectedPerson(void* mgr, int dir);

class ObjectModuleImpl {
public:
    int AdvanceSelectedPerson(int dir);
};

int ObjectModuleImpl::AdvanceSelectedPerson(int dir) {
    ::AdvanceSelectedPerson(s_selectionManager, dir);
    return 0;
}
