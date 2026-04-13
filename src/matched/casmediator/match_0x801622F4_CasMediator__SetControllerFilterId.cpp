// 0x801622F4 CasMediator::SetControllerFilterId (24B)

struct CasMediator {
    char pad[0x20];
    int m_filterIds[2];

    void SetControllerFilterId(int value, unsigned int index);
};

void CasMediator::SetControllerFilterId(int value, unsigned int index) {
    if (index > 1) return;
    m_filterIds[index] = value;
}
