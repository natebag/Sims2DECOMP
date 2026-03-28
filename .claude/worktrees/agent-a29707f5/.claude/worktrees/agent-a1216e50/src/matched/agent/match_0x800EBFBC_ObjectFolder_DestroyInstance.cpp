/* ObjectFolder::DestroyInstance(ObjectFolder *) - 0x800EBFBC (64 bytes) */

struct ObjectFolder {
    virtual ~ObjectFolder();
    static void DestroyInstance(ObjectFolder *p);
};

void ObjectFolder::DestroyInstance(ObjectFolder *p)
{
    if (p) {
        delete p;
    }
}
