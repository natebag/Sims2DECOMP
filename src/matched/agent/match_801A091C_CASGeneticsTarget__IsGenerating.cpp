static int s_generating;

class CASGeneticsTarget {
public:
    int IsGenerating(void);
};

int CASGeneticsTarget::IsGenerating(void) {
    if (s_generating != 0) {
        return 1;
    }
    return 0;
}
