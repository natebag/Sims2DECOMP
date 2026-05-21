// 0x80119DC0 cTrack::InstanceId(void) (8B)
struct cTrack_IId {
    int _pad0;
    int m_instanceId;
    int InstanceId() const;
};
int cTrack_IId::InstanceId() const { return m_instanceId; }
