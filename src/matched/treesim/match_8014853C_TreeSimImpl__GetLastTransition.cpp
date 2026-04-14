// 0x8014853C (20 bytes)
// TreeSimImpl::GetLastTransition(void)
// lwz r3,40(r3); xori r3,r3,0xFE; subfic r0,r3,0; addze r3,r0; blr
// = !(field40 ^ 0xFE) = (field40 == 0xFE) as bool

class TreeSimImpl {
public:
    char _pad[0x28];
    unsigned int m_lastTransition;  // offset 0x28
    int GetLastTransition();
};

int TreeSimImpl::GetLastTransition() {
    return !(m_lastTransition ^ 0xFEU);
}
