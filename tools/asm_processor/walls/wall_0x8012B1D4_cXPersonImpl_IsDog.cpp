// asm-processor input: 0x8012B1D4 cXPersonImpl::IsDog (48B).
// Baseline-only — directive will land once we see the diff against DOL.
// MI vcall through a two-word vtable slot (short thisOff at vt+0x150,
// function ptr at vt+0x154). Target is a 48B pattern; may be crackable
// via source-level structure without an asm-processor pass.

struct cXPersonImpl {
    char pad[4];
    void* m_field_004;
    int IsDog();
};

int cXPersonImpl::IsDog() {
    char* obj = (char*)m_field_004;
    int vtable = *(int*)(obj + 4);
    short offset = *(short*)(vtable + 0x150);
    void* func = *(void**)(vtable + 0x154);
    char* adjusted = obj + offset;
    return ((int (*)(char*))func)(adjusted);
}
