/* CasMediator::GetControllerFilterId(unsigned int) const - 0x8016230C (32 bytes) */

class CasMediator {
public:
    char pad[32];
    unsigned int m_filters[2];

    unsigned int GetControllerFilterId(unsigned int idx) const;
};

unsigned int CasMediator::GetControllerFilterId(unsigned int idx) const {
    if (idx > 1) return 0;
    return m_filters[idx];
}
