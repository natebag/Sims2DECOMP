/* Behavior::GetOwner(void) at 0x800AD118 (8B) */

struct Behavior {
    char pad[0x04];
    void* m_owner;

    void* GetOwner(void);
};

void* Behavior::GetOwner(void) {
    return m_owner;
}
