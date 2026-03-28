struct SimpleReconObject_ObjectSaveTypeTable2 {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_ObjectSaveTypeTable2::GetType() { return m_type; }
