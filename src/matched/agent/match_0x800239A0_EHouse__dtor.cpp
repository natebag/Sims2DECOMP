/* EHouse::~EHouse(void) at 0x800239A0 (76B) */

struct EInstance {
    void Destroy(int flags);
};

void __builtin_delete(void *);

struct EHouse {
    char pad[0x64];
    EInstance m_instance;
    void Cleanup(void);
    void dtor(int flags);
};

void EHouse::dtor(int flags) {
    Cleanup();
    m_instance.Destroy(2);
    if (flags & 1) {
        __builtin_delete(this);
    }
}
