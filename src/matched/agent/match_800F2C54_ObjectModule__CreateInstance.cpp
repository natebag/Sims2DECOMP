/* ObjectModule::CreateInstance(void) - 40 bytes */

void* operator new(unsigned int size);

class ObjectModuleImpl;

ObjectModuleImpl* ObjectModuleImpl_ctor(void*);

class ObjectModule {
public:
    static ObjectModuleImpl* CreateInstance(void);
};

ObjectModuleImpl* ObjectModule::CreateInstance(void) {
    void* mem = operator new(0x20E0);
    return ObjectModuleImpl_ctor(mem);
}
