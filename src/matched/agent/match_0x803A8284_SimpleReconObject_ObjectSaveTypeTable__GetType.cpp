struct SimpleReconObject_ObjectSaveTypeTable {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_ObjectSaveTypeTable::GetType() { return m_type; }
