struct PassiveInfluenceObject {
    char _p[0x04];
    int m_obj;
    int GetObject();
};
int PassiveInfluenceObject::GetObject() { return m_obj; }
