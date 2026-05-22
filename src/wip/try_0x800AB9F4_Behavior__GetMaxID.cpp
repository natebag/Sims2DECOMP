// 0x800AB9F4 Behavior::GetMaxID(short) (64B)

class Behavior {
public:
    static int GetMaxID(short id);
};

int Behavior::GetMaxID(short id) {
    int r = 0;
    if (id == 1) goto c1;
    if (id <= 1) goto ex;
    if (id == 2) goto c2;
    if (id == 3) goto c3;
    goto ex;
c1: r = 0xfff; goto ex;
c2: r = 0x1fff; goto ex;
c3: r = 0x2328;
ex:
    return r;
}
