struct ObjSelector {
    char _p[0x8c];
    int m_val;
    int GetSimDescription() const;
};
int ObjSelector::GetSimDescription() const { return m_val; }
