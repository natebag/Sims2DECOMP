/* cTrack::SetInstanceId(int) - 0x80119DB4 - 12 bytes */
/* stw r4, 4(r3); li r3, 1; blr */

class cTrack {
public:
    char _pad[0x4];
    int m_instanceId;

    int SetInstanceId(int id);
};

int cTrack::SetInstanceId(int id) {
    m_instanceId = id;
    return 1;
}
