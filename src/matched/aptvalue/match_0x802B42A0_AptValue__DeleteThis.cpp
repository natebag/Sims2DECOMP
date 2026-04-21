// 0x802B42A0 (64B) AptValue::DeleteThis(void)

struct AptValue {
    char pad[8];
    void* m_vtable;

    void DeleteThis();
};

void AptValue::DeleteThis() {
    if (this == 0) return;
    void* vt = m_vtable;
    short thisOff = *(short*)((char*)vt + 120);
    void (*fn)(void*, int) = *(void (**)(void*, int))((char*)vt + 124);
    fn((char*)this + thisOff, 3);
}
