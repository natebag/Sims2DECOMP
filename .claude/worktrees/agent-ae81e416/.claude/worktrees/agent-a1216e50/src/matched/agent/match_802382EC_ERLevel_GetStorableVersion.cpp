// 0x802382EC (12 bytes) - ERLevel::GetStorableVersion(void) const
// addis r3, r3, 3; lwz r3, -24168(r3); blr  =>  return m_storableVersion; (offset 0x2A198)

class ERLevel;

struct ERLevel_GSV {
    char pad[0x2A198];
    int m_storableVersion;
    int GetStorableVersion() const;
};
int ERLevel_GSV::GetStorableVersion() const {
    return m_storableVersion;
}
