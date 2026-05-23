// 0x8016230C CasMediator::GetControllerFilterId(unsigned int) const (32B)
//
// Field name aligned with SetControllerFilterId (0x801622F4) — both files now
// share the same `m_controllerFilters[2]` layout at offset 0x20 (was
// m_filters vs m_filterIds drift).
//
// Twin of SetControllerFilterId. Returns 0 for out-of-range index.

class CasMediator {
public:
    char pad[0x20];
    unsigned int m_controllerFilters[2];

    unsigned int GetControllerFilterId(unsigned int idx) const;
};

unsigned int CasMediator::GetControllerFilterId(unsigned int idx) const {
    if (idx > 1) return 0;
    return m_controllerFilters[idx];
}
