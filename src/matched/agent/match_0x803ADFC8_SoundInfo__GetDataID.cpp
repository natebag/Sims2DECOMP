// 0x803ADFC8 (52B) SoundInfo::GetDataID() const
// Returns ObjectDataID m_dataId by value via copy ctor (no RVO).

class ObjectDataID {
public:
    unsigned int m_ns;
    unsigned short m_res;
    ObjectDataID(const ObjectDataID&);
};

class SoundInfo {
public:
    char _pad[80];
    ObjectDataID m_dataId;
    ObjectDataID GetDataID() const;
};

ObjectDataID SoundInfo::GetDataID() const
{
    return m_dataId;
}
