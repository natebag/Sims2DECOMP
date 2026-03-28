struct SimpleReconObject_ObjectModuleImpl {
    char _p[0x08];
    int m_type;
    int GetType();
};
int SimpleReconObject_ObjectModuleImpl::GetType() { return m_type; }
