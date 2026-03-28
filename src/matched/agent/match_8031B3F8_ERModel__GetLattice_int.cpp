struct ENLatticePoints { char data[176]; };
class ERModel { char pad[272]; ENLatticePoints *m_lattice; public: ENLatticePoints *GetLattice(int); };
ENLatticePoints *ERModel::GetLattice(int idx) { return &m_lattice[idx]; }
