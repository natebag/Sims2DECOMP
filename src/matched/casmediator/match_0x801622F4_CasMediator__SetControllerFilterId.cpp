// 0x801622F4 CasMediator::SetControllerFilterId(int, unsigned int) (24B)
//
// Field name aligned with GetControllerFilterId (0x8016230C) — both files now
// share the same `m_controllerFilters[2]` layout at offset 0x20 (was
// m_filterIds vs m_filters drift).
//
// Per-player controller-input filter (2 slots = 2 players supported in CAS).
// Index out-of-range is a no-op rather than UB.

class CasMediator {
public:
    char pad[0x20];
    unsigned int m_controllerFilters[2];

    void SetControllerFilterId(int value, unsigned int index);
};

void CasMediator::SetControllerFilterId(int value, unsigned int index) {
    if (index > 1) return;
    m_controllerFilters[index] = value;
}
