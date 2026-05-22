// 0x800ABA34 Behavior::GetTreeClass(short) (84B)
// Range-based class encoding: uid=[0x000-0x0FF]→0, [0x100-0xFFF]→1,
//   [0x1000-0x1FFF]→2, [0x2000-0x2328]→3, [0x2329+]→0
// DOL structure: ble branches FORWARD past branchless code to li r3,3 at end

class Behavior {
public:
    static int GetTreeClass(short id);
};

int Behavior::GetTreeClass(short id) {
    unsigned short uid = (unsigned short)id;
    if (uid <= 0xFF) return 0;
    if ((unsigned)(id - 0x100) <= 0xEFF) return 1;
    if ((unsigned)(id - 0x2000) > 0x328) {
        return ((unsigned)(id - 0x1000) <= 0x0FFF) << 1;
    }
    return 3;
}
