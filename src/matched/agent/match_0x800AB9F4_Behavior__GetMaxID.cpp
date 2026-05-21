// 0x800AB9F4 (64B) Behavior::GetMaxID(short)
// Sister of GetBaseID — identical goto-chain pattern, different return values.

class Behavior {
public:
    static int GetMaxID(short v);
};

int Behavior::GetMaxID(short v) {
    int result = 0;
    if (v == 1) goto r1;
    if (v <= 1) goto done;
    if (v == 2) goto r2;
    if (v == 3) goto r3;
    goto done;
r1: result = 4095; goto done;
r2: result = 8191; goto done;
r3: result = 9000;
done:
    return result;
}
