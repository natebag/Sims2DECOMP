struct SimpleReconObject_ObjectSaveTypeTable3 {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_ObjectSaveTypeTable3::GetType() { return m_type; }
