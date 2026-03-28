struct PassiveInfluencePerson {
    char _p[0x04];
    int m_obj;
    int GetObject();
};
int PassiveInfluencePerson::GetObject() { return m_obj; }
