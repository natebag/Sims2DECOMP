/* Neighbor::GetFriendCount(void) - 60 bytes */

struct Neighbor {
    char m_pad[0x1C];
    short m_friendCount;
    short m_enemyCount;
    short m_reputationValue;
    char m_pad2[2];
    int m_dirty;

    short GetFriendCount(void);
    void RecalculateRelationshipData(void);
};

short Neighbor::GetFriendCount(void) {
    if (m_dirty != 0)
        RecalculateRelationshipData();
    return m_friendCount;
}
