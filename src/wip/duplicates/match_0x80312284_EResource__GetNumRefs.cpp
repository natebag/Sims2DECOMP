struct EResource {
    char _pad[0x0c];
    short m_numRefs;
    short GetNumRefs();
};
short EResource::GetNumRefs() { return m_numRefs; }
