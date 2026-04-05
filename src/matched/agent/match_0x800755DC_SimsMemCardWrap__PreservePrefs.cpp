extern int *gSMCW_Global[];
void SMCW_Preserve(void *);

struct SMCW_PP {
    void PreservePrefs(void);
};

void SMCW_PP::PreservePrefs(void) {
    SMCW_Preserve(gSMCW_Global[0]);
}
