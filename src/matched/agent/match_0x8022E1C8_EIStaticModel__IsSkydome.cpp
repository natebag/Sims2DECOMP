// 0x8022E1C8 EIStaticModel::IsSkydome(void) const (36B)
// Returns 1 if (m_model && (m_model->flags & 0x2000)).

struct ModelData {
    char _pad[8];
    int flags;
};

struct EIStaticModel {
    char _pad[0x118];
    ModelData* m_model;
    int IsSkydome() const;
};

int EIStaticModel::IsSkydome() const {
    ModelData* p = m_model;
    int r = 0;
    if (!p) return r;
    if (p->flags & 0x2000) r = 1;
    return r;
}
