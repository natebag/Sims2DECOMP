struct EController {
    unsigned int GetCmdButtonMask(unsigned int cmd);
    void AddBtnToFilter(unsigned int filterId, unsigned int mask);
    void AddCmdToFilter(unsigned int filterId, unsigned int cmd);
};

void EController::AddCmdToFilter(unsigned int filterId, unsigned int cmd) {
    unsigned int mask = GetCmdButtonMask(cmd);
    AddBtnToFilter(filterId, mask);
}
