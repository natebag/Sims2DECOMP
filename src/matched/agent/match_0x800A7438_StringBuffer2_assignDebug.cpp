// 0x800A7438 (60B) StringBuffer2::assignDebug(StringBuffer&)
// Two-call pattern: this->assign(preprocess(sb))

extern int preprocess(int&);

class StringBuffer2 {
public:
    void* assignDebug(int&);
    void* assign(int hash);
};

void* StringBuffer2::assignDebug(int& sb) {
    return assign(preprocess(sb));
}
