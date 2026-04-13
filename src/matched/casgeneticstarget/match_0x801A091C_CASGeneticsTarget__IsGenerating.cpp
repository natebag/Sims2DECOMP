// 0x801A091C CASGeneticsTarget::IsGenerating (24B)

extern int g_isGenerating;

struct CASGeneticsTarget {
    int IsGenerating();
};

int CASGeneticsTarget::IsGenerating() {
    int r = 1;
    if (g_isGenerating == 0) r = 0;
    return r;
}
