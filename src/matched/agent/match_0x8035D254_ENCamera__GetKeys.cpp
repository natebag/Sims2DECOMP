struct ENCamera {
    char _p[0x44];
    int m_keys;
    int GetKeys();
};
int ENCamera::GetKeys() { return m_keys; }
