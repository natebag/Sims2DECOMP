// 0x80035314 (8 bytes) — lwz r3, 0x3D0(r3); blr

class ESim {
public:
    char _pad[0x3D0];
    void* m_person;

    void* GetPerson();
};

void* ESim::GetPerson() {
    return m_person;
}
