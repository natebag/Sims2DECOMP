/* ObjectModule::DestroyInstance(ObjectModule *) - 0x800F2C7C (64 bytes) */

struct ObjectModule {
    virtual ~ObjectModule();
    static void DestroyInstance(ObjectModule *p);
};

void ObjectModule::DestroyInstance(ObjectModule *p)
{
    if (p) {
        delete p;
    }
}
