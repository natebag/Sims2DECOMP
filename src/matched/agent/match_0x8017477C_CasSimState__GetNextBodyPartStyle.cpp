// 0x8017477C CasSimState::GetNextBodyPartStyle(int, int, bool) (68B)

class CasSimState {
public:
    int GetNextBodyPartStyle(int curr, int max, bool fwd);
};

int CasSimState::GetNextBodyPartStyle(int curr, int max, bool fwd) {
    if (curr < 0) return curr;
    if (curr >= max) return curr;
    int delta = 1;
    if (!fwd) delta = -1;
    curr += delta;
    if (curr >= max) return 0;
    if (curr < 0) return max - 1;
    return curr;
}
