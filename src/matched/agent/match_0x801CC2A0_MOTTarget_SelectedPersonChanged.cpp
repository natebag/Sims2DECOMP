/* MOTTarget::SelectedPersonChanged(cXPerson*) at 0x801CC2A0 (12B) */

struct MOTTarget {
    char pad[0x168];
    int m_selectedChanged;

    void SelectedPersonChanged(void* person);
};

void MOTTarget::SelectedPersonChanged(void* person) {
    m_selectedChanged = 1;
}
