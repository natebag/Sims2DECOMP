// 0x8033B734 ENgcRenderer::Init(int&, int&) (48B)
// Forward to helper, boolean-coerce result

struct ENgcRenderer {
    int Init(int& a, int& b);
    int InitImpl();
};

int ENgcRenderer::Init(int&, int&) {
    int r = InitImpl();
    int ret = 0;
    if (r == 0) return ret;
    return 1;
}
