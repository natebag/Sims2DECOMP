// 0x800AB9B4 Behavior::GetBaseID(short) (64B)

class Behavior {
public:
    static int GetBaseID(short id);
};

int Behavior::GetBaseID(short id) {
    int r = 0;
    if (id == 1) goto c1;
    if (id <= 1) goto ex;
    if (id == 2) goto c2;
    if (id == 3) goto c3;
    goto ex;
c1: r = 0x100; goto ex;
c2: r = 0x1000; goto ex;
c3: r = 0x2000;
ex:
    return r;
}
