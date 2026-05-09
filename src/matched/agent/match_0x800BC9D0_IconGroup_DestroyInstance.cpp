// 0x800BC9D0 (64B) IconGroup::DestroyInstance(IconGroup*)
// Standard virtual-destructor delete pattern (lha/lwz thunk adjustment).

struct IconGroup {
    virtual ~IconGroup();
    static void DestroyInstance(IconGroup* p);
};

void IconGroup::DestroyInstance(IconGroup* p)
{
    if (p) {
        delete p;
    }
}
