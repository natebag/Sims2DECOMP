struct SimpleReconObject_ObjectSaveIDTable {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_ObjectSaveIDTable::GetType() { return m_type; }
