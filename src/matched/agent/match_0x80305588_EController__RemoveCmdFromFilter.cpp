struct EController {
    unsigned int GetCmdButtonMask(unsigned int cmd);
    void RemoveBtnFromFilter(unsigned int filterId, unsigned int mask);
    void RemoveCmdFromFilter(unsigned int filterId, unsigned int cmd);
};

void EController::RemoveCmdFromFilter(unsigned int filterId, unsigned int cmd) {
    unsigned int mask = GetCmdButtonMask(cmd);
    RemoveBtnFromFilter(filterId, mask);
}
