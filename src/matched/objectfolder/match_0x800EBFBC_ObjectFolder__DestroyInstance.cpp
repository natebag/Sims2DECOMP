// 0x800EBFBC ObjectFolder::DestroyInstance (64B)

struct ObjectFolder {
    virtual ~ObjectFolder();
    static void DestroyInstance(ObjectFolder *p);
};

void ObjectFolder::DestroyInstance(ObjectFolder *p) {
    if (p) {
        delete p;
    }
}
