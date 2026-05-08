/* QuickDataBehaviorConstants::GetValue(int) const - 0x8015A7CC - 36 bytes */

struct BCQuickEntry {
    short m_value;
    char _pad[6];
};

struct BCQuickData {
    char _pad[4];
    BCQuickEntry *m_entries;
};

struct QuickDataBehaviorConstants {
    char _pad[0x18];
    BCQuickData *m_cachedData;

    short GetValue(int index) const;
};

short QuickDataBehaviorConstants::GetValue(int index) const {
    if (m_cachedData == 0) return 0;
    return m_cachedData->m_entries[index].m_value;
}
