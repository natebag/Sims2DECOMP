// 0x80119DC0 (8B) cTrack::InstanceId(void)
// Getter for field at offset 0x4.

class cTrack {
public:
    char pad_000[0x4];
    int m_field_4;
    int InstanceId(void);
};

int cTrack::InstanceId(void) {
    return m_field_4;
}
