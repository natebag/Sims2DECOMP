/* ObjectModuleImpl::GetSim(void) - 8 bytes */

static void* s_sim;

class ObjectModuleImpl {
public:
    void* GetSim(void);
};

void* ObjectModuleImpl::GetSim(void) {
    return s_sim;
}
