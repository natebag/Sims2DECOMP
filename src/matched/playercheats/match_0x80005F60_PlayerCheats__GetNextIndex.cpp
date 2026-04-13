// 0x80005F60 PlayerCheats::GetNextIndex (36B)

class PlayerCheats {
public:
    int GetNextIndex(int &idx);
};

int PlayerCheats::GetNextIndex(int &idx) {
    int val = idx;
    val++;
    idx = val;
    if (val > 5) {
        idx = 0;
    }
    return idx;
}
