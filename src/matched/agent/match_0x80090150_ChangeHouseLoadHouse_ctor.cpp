// FLAGS: -fno-elide-constructors
// 0x80090150 ChangeHouseLoadHouse::ChangeHouseLoadHouse (60b)

extern int _vt_ChangeHouseLoadHouse[];

struct ChangeHouseLoadHouse {
    int f0;
    int f4;
    int f8;
    int f12;
    int f16;
    int f20;
    int* f24;
    int f28;
    ChangeHouseLoadHouse(int p2);
};

ChangeHouseLoadHouse::ChangeHouseLoadHouse(int p2) {
    f0 = p2;
    f4 = -1;
    f8 = 0;
    f12 = -1;
    f16 = 0;
    f20 = 1;
    f24 = _vt_ChangeHouseLoadHouse;
    f28 = 0;
}
