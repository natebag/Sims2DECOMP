// 0x800F2C7C ObjectModule::DestroyInstance (64B)

struct ObjectModule {
    virtual ~ObjectModule();
    static void DestroyInstance(ObjectModule *p);
};

void ObjectModule::DestroyInstance(ObjectModule *p) {
    if (p) {
        delete p;
    }
}
