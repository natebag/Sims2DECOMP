/* PDATarget::GetINVTarget(int) const at 0x8020375C (16B) */

struct PDATarget {
    char pad[0x134];
    int m_invTargets[1];

    int GetINVTarget(int index) const;
};

int PDATarget::GetINVTarget(int index) const {
    return m_invTargets[index];
}
