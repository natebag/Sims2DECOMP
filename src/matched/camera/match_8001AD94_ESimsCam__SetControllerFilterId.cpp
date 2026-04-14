// 0x8001AD94 (12 bytes) — stw r4, 0x560(r3); li r3, 1; blr
// Stores the filter ID and returns 1

class ESimsCam {
public:
    char _pad[0x560];
    unsigned int m_controllerFilterId;

    int SetControllerFilterId(unsigned int id);
};

int ESimsCam::SetControllerFilterId(unsigned int id) {
    m_controllerFilterId = id;
    return 1;
}
