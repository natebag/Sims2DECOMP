/* QuickDataBehaviorConstants::GetValue(int) const - 0x8015A7CC - 36 bytes */
/* [VERSION_DIFF] lhax RA/RB operand swap: DOL=lhax r3,r11,r9 but ProDG v3.93 always generates lhax r3,r9,r11 (offset in RA). Semantics identical. */

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
    return *(short *)((char *)m_cachedData->m_entries + index * 8);
}
