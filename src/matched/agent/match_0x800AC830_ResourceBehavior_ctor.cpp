/* ResourceBehavior::ResourceBehavior(void) - 0x800AC830 - 80 bytes */

struct Behavior {
    char _data[16];
    Behavior();
};

struct ResourceBehavior : public Behavior {
    int m_field16;
    int m_field20;
    int m_field24;
    int m_refCount;
    ResourceBehavior();
};

extern void *__vt__ResourceBehavior[];

ResourceBehavior::ResourceBehavior() : Behavior() {
    m_refCount = 0;
    m_field16 = 0;
    m_field20 = 0;
    *(void ***)this = __vt__ResourceBehavior;
    m_field24 = 0;
}
