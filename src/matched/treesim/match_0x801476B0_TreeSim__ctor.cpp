// 0x801476B0 TreeSim::TreeSim(void) (48 B)

extern char s_TreeSim_vtable[];

struct BaseSim {
    int b0, b1, b2, b3, b4;
    BaseSim();
};

inline BaseSim::BaseSim() {
    b0 = 0;
    b1 = 0;
    b2 = 0;
    b3 = 0;
    b4 = 0;
}

struct TreeSim : public BaseSim {
    int m_f;
    void* m_vt;
    TreeSim();
};

TreeSim::TreeSim() {
    m_vt = s_TreeSim_vtable;
    m_f = 0;
}
