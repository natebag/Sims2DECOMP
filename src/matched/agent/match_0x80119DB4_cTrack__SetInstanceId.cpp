// 0x80119DB4 cTrack::SetInstanceId(int) (12B)
struct cTrack_SId {
    int _pad0;
    int m_instanceId;
    int SetInstanceId(int id);
};
int cTrack_SId::SetInstanceId(int id) { m_instanceId = id; return 1; }
