/* Neighbor::GetReputationValue(void) - 60 bytes */

struct Neighbor {
    char m_pad[0x20];
    short m_reputationValue;
    char m_pad2[2];
    int m_dirty;

    short GetReputationValue(void);
    void RecalculateRelationshipData(void);
};

short Neighbor::GetReputationValue(void) {
    if (m_dirty != 0)
        RecalculateRelationshipData();
    return m_reputationValue;
}
