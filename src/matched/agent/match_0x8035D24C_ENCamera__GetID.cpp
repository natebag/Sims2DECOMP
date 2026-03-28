struct ENCamera {
    char _p[0x40];
    int m_id;
    int GetID();
};
int ENCamera::GetID() { return m_id; }
