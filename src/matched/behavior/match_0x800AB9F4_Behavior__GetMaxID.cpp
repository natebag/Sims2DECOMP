// 0x800AB9F4 Behavior::GetMaxID(short) (64B) — Tech #16 goto-end + result var (same pattern as GetBaseID)

class Behavior {
public:
    static short GetMaxID(short type);
};

short Behavior::GetMaxID(short type) {
    int result = 0;
    if (type == 1) goto case1;
    if (type <= 1) goto end;
    if (type == 2) goto case2;
    if (type == 3) goto case3;
    goto end;
case1:
    result = 0xFFF;
    goto end;
case2:
    result = 0x1FFF;
    goto end;
case3:
    result = 0x2328;
end:
    return (short)result;
}
