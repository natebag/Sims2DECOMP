/* Neighbor::GetEnemyCount(void) - 60 bytes */

struct Neighbor {
    char m_pad[0x1E];
    short m_enemyCount;
    char m_pad2[4];
    int m_dirty;

    short GetEnemyCount(void);
    void RecalculateRelationshipData(void);
};

short Neighbor::GetEnemyCount(void) {
    if (m_dirty != 0)
        RecalculateRelationshipData();
    return m_enemyCount;
}
