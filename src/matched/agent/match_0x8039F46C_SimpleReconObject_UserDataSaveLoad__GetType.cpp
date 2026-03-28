struct SimpleReconObject_UserDataSaveLoad {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_UserDataSaveLoad::GetType() { return m_type; }
