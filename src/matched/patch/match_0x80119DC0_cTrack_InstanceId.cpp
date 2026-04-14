/* cTrack::InstanceId(void) - 0x80119DC0 - 8 bytes */
/* lwz r3, 4(r3); blr */

class cTrack {
public:
    char _pad[0x4];
    int m_instanceId;

    int InstanceId(void);
};

int cTrack::InstanceId(void) {
    return m_instanceId;
}
