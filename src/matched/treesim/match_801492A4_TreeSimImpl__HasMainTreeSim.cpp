// 0x801492A4 (16 bytes)
// TreeSimImpl::HasMainTreeSim(void)
// lwz r3, 56(r3); subfic r0, r3, 0; addze r3, r0; blr
// field at offset 0x38 = noMainTreeSim flag
// subfic r0, r3, 0: r0 = -r3, CA = (r3 == 0)
// addze r3, r0: r3 = -r3 + (r3==0)
// This is: !noMainTreeSim (when noMainTreeSim is exactly 0 or 1)

class TreeSimImpl {
public:
    int HasMainTreeSim();
    char _pad[0x38];
    int m_noMainTreeSim;
};

int TreeSimImpl::HasMainTreeSim() {
    return !m_noMainTreeSim;
}
