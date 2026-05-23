// FLAGS: -fno-schedule-insns
// 0x800708F4 SimModel::DeallocateMorphResources(void) (120 bytes)

class ERModel {
public:
    int GetNumMorphBases();
    void FreeAllMorphAndLatticeResource(bool);
};

class Model {
    char m_data[288];
public:
    ERModel* m_morph;
};

class SimModel {
public:
    int m_partFlags[26];
    Model* m_models[26];
    unsigned int m_resourceIDs[26];
    void DeallocateMorphResources();
};

void SimModel::DeallocateMorphResources() {
    int* p = (int*)this;
    int* pEnd = p + 25;
    do {
        Model* model = *(Model**)(p + 26);
        if (model) {
            ERModel* morph = model->m_morph;
            if (morph) {
                if (morph->GetNumMorphBases()) {
                    *p |= 4;
                    (*(Model**)(p + 26))->m_morph->FreeAllMorphAndLatticeResource(true);
                }
            }
        }
        p++;
    } while (p <= pEnd);
}
