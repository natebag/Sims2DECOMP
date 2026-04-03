struct Lattice { char _d[0xb0]; };
struct ERModel {
    char _p[0x110];
    char *m_lattices;
    void *GetLattice(int i);
};
void *ERModel::GetLattice(int i) { return m_lattices + i * 0xb0; }
