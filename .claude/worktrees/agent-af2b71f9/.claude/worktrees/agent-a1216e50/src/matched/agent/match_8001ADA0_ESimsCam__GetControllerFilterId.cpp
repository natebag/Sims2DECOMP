// 0x8001ADA0 (8 bytes) — lwz r3, 0x560(r3); blr

class ESimsCam {
public:
    char _pad[0x560];
    unsigned int m_controllerFilterId;

    unsigned int GetControllerFilterId() const;
};

unsigned int ESimsCam::GetControllerFilterId() const {
    return m_controllerFilterId;
}
