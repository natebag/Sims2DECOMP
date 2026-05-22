// FLAGS: -fno-schedule-insns
// 0x8007084C SimModel::DeallocateModelPart(eBodyPartS2C) (168 bytes)
// Nested second block forces 4 callee-saves (r28-r31) with correct DOL assignment.
// Only remaining mismatches: flags section lwzx/stwx have rA/rB swapped vs DOL.
// ASMPROC_replace_insn: match="lwzx 0,31,9" replacement="lwzx 0,9,31"
// ASMPROC_replace_insn: match="stwx 0,31,9" replacement="stwx 0,9,31"

class ERModel {
public:
    void FreeAllMorphAndLatticeResource(bool);
};

struct ModelVtable {
    char pad[48];
    short dtor_adj;
    short _pad;
    void (*dtor_fn)(void*, int);
};

class Model {
public:
    ModelVtable* m_vtable;
    char m_pad[284];
    ERModel* m_morph;
};

class EString {
public:
    char* m_ptr;
    ~EString() { Deallocate(m_ptr); }
    void Deallocate(char* ptr);
};

struct ModelPart {
    int m_flags;
    ~ModelPart() {}
};

class SimModel {
public:
    ModelPart m_partFlags[26];
    Model* m_models[26];
    unsigned int m_resourceIDs[26];
    int m_f312;
    int m_f316;
    int m_f320;
    int m_f324;
    int m_f328;
    int m_f332;
    int m_f336;
    int m_f340;
    EString m_strings[4];

    void DeallocateModelPart(int part);
};

void SimModel::DeallocateModelPart(int part) {
    Model* model = m_models[part];
    if (model) {
        ERModel* morph = model->m_morph;
        if (morph) {
            if (!(m_partFlags[part].m_flags & 4)) {
                morph->FreeAllMorphAndLatticeResource(false);
            }
        }

        Model* model2 = m_models[part];
        if (model2) {
            ModelVtable* vt = model2->m_vtable;
            short adj = vt->dtor_adj;
            void (*fn)(void*, int) = vt->dtor_fn;
            fn((char*)model2 + adj, 3);
        }
        m_models[part] = 0;
    }

    m_partFlags[part].m_flags &= ~0x1E;
}
