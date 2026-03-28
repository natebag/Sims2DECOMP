struct ESimsCam {
    char pad[0x560];
    int m_controllerFilterId;
};

int ESimsCam_ClearControllerFilterId(ESimsCam* self) {
    self->m_controllerFilterId = 0;
    return 1;
}
