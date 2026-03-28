struct EInstance;
struct EAnimController;

unsigned int HashString(char* name);

struct EIStaticModel {
    void SetModel(unsigned int id, bool flag, EInstance* inst, EAnimController* ctrl);
    void SetModel(char* name);
};

void EIStaticModel::SetModel(char* name) {
    unsigned int id = HashString(name);
    SetModel(id, 0, 0, 0);
}
