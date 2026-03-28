struct PassiveInfluenceTarget {
    char _p[0x04];
    int m_obj;
    int GetObject();
};
int PassiveInfluenceTarget::GetObject() { return m_obj; }
