// ISimInstance::New(void)
// Address: 0x80056800 | Size: 40 bytes
// Allocates 968 bytes, calls ISimInstance() constructor, returns pointer

class ISimInstance {
public:
    static ISimInstance *New(void);
    ISimInstance(void);
    void *operator new(unsigned int size);
    void *operator new(unsigned int size, void *ptr) { (void)size; return ptr; }
};

ISimInstance *ISimInstance::New(void) {
    void *mem = ISimInstance::operator new(968);
    ISimInstance *p = new(mem) ISimInstance();
    return p;
}
