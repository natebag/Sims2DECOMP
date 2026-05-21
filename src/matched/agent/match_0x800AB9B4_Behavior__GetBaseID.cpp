// 0x800AB9B4 (64B) Behavior::GetBaseID(short)
// DOL layout: comparison chain → explicit b→done (v>3) → r1 → r2 → r3 → done
// Key: explicit goto done after comparison chain forces the branch at +0x20

class Behavior {
public:
    static int GetBaseID(short v);
};

int Behavior::GetBaseID(short v) {
    int result = 0;
    if (v == 1) goto r1;
    if (v <= 1) goto done;
    if (v == 2) goto r2;
    if (v == 3) goto r3;
    goto done;
r1: result = 256; goto done;
r2: result = 4096; goto done;
r3: result = 8192;
done:
    return result;
}
