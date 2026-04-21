// 0x80118E84 cSamplePatch::~cSamplePatch (64B)
// Deleting destructor: bl FreeSnd; if (flag & 1) __builtin_delete(this);

struct cSamplePatch {
    void FreeSnd();
    ~cSamplePatch();
};

cSamplePatch::~cSamplePatch() {
    FreeSnd();
}
