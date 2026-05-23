// 0x802012EC RELTarget::GetColor(int) (76B)

class RELRecord {
public:
    char pad[0x1C];
    int m_1C;
};

class RELTarget {
public:
    static RELRecord* GetRecord(int idx);
    static int GetColor(int idx);
};

int RELTarget::GetColor(int idx) {
    RELRecord* r = RELTarget::GetRecord(idx);
    if (r == 0) goto ret_one;
    {
        int v = r->m_1C;
        if (v <= 33) goto neg_check;
        return 0;
    neg_check:
        if (v < -34) return 2;
    }
ret_one:
    return 1;
}
