class INVTarget {
public:
    int CalcLastPageIdx(int numItems);
};

int INVTarget::CalcLastPageIdx(int numItems) {
    return numItems / 13;
}
