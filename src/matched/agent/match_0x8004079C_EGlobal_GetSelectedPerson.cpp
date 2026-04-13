/* EGlobal::GetSelectedPerson(int) - 0x8004079C (16 bytes) */

struct EGlobal {
    char pad[0xBC];
    int m_selectedPersons[4];
};

int EGlobal_GetSelectedPerson(EGlobal* self, int index) {
    return self->m_selectedPersons[index];
}
