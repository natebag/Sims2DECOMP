// 0x80035314 ESim::GetPerson (8B)

struct ESim_GetPerson {
    char pad[0x3D0];
    int m_val;
    int GetPerson();
};

int ESim_GetPerson::GetPerson() {
    return m_val;
}
