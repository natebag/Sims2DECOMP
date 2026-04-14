// 0x800AD118 (8 bytes)
class Behavior {
public:
    void *pad;
    void *m_owner;

    void *GetOwner(void);
};

void *Behavior::GetOwner(void) {
    return m_owner;
}
