// 0x802BC898 (24B) EAStringC::IsEnoughSize(unsigned int) const
// Reads halfword at *(this+0) + 4 (header capacity), compares param against it.
// `subfc + subfe + neg` is the SN bool-from-compare idiom returning 1 when param < capacity.

struct StringHeader {
    char _pad[4];
    unsigned short m_capacity;  // offset 4
};

class EAStringC {
public:
    StringHeader* m_data;  // offset 0
    bool IsEnoughSize(unsigned int n) const;
};

bool EAStringC::IsEnoughSize(unsigned int n) const {
    return n < m_data->m_capacity;
}
