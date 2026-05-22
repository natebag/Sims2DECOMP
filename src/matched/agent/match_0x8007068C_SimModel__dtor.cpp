// FLAGS: -fno-schedule-insns
// 0x8007068C SimModel::~SimModel(void) (140 bytes)

void __builtin_delete(void*);

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

class Model;

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

    void Reset();
    ~SimModel();
};

SimModel::~SimModel() {
    Reset();
}
