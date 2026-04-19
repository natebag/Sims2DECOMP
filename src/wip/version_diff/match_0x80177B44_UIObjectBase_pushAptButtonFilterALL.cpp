// 0x80177B44 (88B) UIObjectBase::pushAptButtonFilterALL(int, char *)

struct UIObjectBase {
    int pushAptButtonFilter(int arg1, char* arg2);
    int addCmdToAptButtonFilter(int arg1, unsigned int arg2);
    int pushAptButtonFilterALL(int arg1, char* arg2);
};

int UIObjectBase::pushAptButtonFilterALL(int arg1, char* arg2) {
    int r = pushAptButtonFilter(arg1, arg2);
    if (!r) return 0;
    unsigned int i = 1;
    do {
        addCmdToAptButtonFilter(r, i);
        i++;
    } while (i != 49);
    return r;
}
