/* TreeTableEntryQuickData::GetAttenuationValue(bool) const - 0x8015E78C - 36 bytes */
/* Wrapper: loads m_data and calls TreeTableEntry::GetAttenuationValue */

struct TreeTableEntry {
    float GetAttenuationValue(int useCustom) const;
};

class TreeTableEntryQuickData {
public:
    int m_pad0;
    TreeTableEntry* m_data;

    float GetAttenuationValue(int useCustom) const;
};

float TreeTableEntryQuickData::GetAttenuationValue(int useCustom) const {
    return m_data->GetAttenuationValue(useCustom);
}