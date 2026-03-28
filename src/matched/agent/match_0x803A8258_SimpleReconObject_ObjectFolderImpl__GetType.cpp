struct SimpleReconObject_ObjectFolderImpl {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_ObjectFolderImpl::GetType() { return m_type; }
