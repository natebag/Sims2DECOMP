/* PDATarget::GetPdaMode(int) at 0x8020376C (16B) */

struct PDATarget {
    char pad[0x14C];
    int m_pdaModes[1];

    int GetPdaMode(int index);
};

int PDATarget::GetPdaMode(int index) {
    return m_pdaModes[index];
}
