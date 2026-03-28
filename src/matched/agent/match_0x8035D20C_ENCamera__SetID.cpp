struct ENCamera {
    char _pad[0x40];
    int m_id;
    void SetID(int val);
};
void ENCamera::SetID(int val) { m_id = val; }
