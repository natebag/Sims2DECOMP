class EBtnToCmdAssoc {
public:
    static int CompareControllerCommandToKey(void *a, void *b);
};
int EBtnToCmdAssoc::CompareControllerCommandToKey(void *a, void *b) {
    unsigned int va = *(unsigned int *)a;
    unsigned int vb = *(unsigned int *)b;
    if (va < vb) return -1;
    if (va > vb) return 1;
    return 0;
}
