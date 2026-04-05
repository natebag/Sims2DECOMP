void *CR_Check(void);
void CR_AddRes(void *, unsigned int);

struct CR_OMS {
    int CreateResources(void *manip);
};

int CR_OMS::CreateResources(void *manip) {
    void *result = CR_Check();
    if (result == 0) {
        return 0;
    }
    CR_AddRes(result, 0x4EBB9687u);
    CR_AddRes(result, 0x8BC514D2u);
    return 1;
}
