// 0x801EFA00 INVTarget::CalcLastPageIdx(int) (28B)

struct INVTarget {
    int CalcLastPageIdx(int n);
};

int INVTarget::CalcLastPageIdx(int n) {
    return n / 13;
}
