/* PlayerFamilyImpl::GetStatValue(int) const - 0x8012D140 (32 bytes) */

class PlayerFamilyImpl {
public:
    char pad[3240];
    short m_stats[25];

    short GetStatValue(int idx) const;
};

short PlayerFamilyImpl::GetStatValue(int idx) const {
    if ((unsigned)idx > 24) return 0;
    return m_stats[idx];
}
