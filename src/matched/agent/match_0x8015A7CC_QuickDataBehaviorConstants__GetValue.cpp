// QuickDataBehaviorConstants::GetValue(int) const - 0x8015A7CC (36B)
// Indexed short lookup with stride 8 via m_data->m_entries[idx].value.

struct Entry {
    short value;
    char _pad[6];
};

struct DataStruct {
    char _pad[4];
    Entry* m_entries;
};

class QuickDataBehaviorConstants {
public:
    char _pad[24];
    DataStruct* m_data;
    short GetValue(int idx) const;
};

short QuickDataBehaviorConstants::GetValue(int idx) const
{
    if (m_data == 0) return 0;
    unsigned int base = (unsigned int)m_data->m_entries;
    unsigned int off = (unsigned int)(idx << 3);
    return *(const short*)(base + off);
}
