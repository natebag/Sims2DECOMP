// FLAGS: -fno-schedule-insns -fno-elide-constructors
// 0x80089A14 EGameStateMan::EGameStateMan (40B)

struct EGameStateMan {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;

    EGameStateMan();
};

EGameStateMan::EGameStateMan() {
    int* p = (int*)this;
    int* q = p + 1;
    q[1] = 0;
    q[0] = 0;
    q[2] = 1;
    p[0] = 0;
    p[4] = 0;
}
