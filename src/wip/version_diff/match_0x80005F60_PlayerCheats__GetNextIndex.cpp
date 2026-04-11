// PlayerCheats::GetNextIndex(int &) — 36B @ 0x80005F60

class PlayerCheats {
public:
    int GetNextIndex(int &idx);
};

int PlayerCheats::GetNextIndex(int &idx) {
    int val = idx;
    val++;
    idx = val;
    if (val == 5) {
        idx = 0;
    }
    return idx;
}
