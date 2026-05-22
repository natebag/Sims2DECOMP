// 0x800AB9B4 Behavior::GetBaseID(short) (64B) — Tech #16 goto-end + result var

class Behavior {
public:
    static short GetBaseID(short type);
};

short Behavior::GetBaseID(short type) {
    int result = 0;
    if (type == 1) goto case1;
    if (type <= 1) goto end;
    if (type == 2) goto case2;
    if (type == 3) goto case3;
    goto end;
case1:
    result = 0x100;
    goto end;
case2:
    result = 0x1000;
    goto end;
case3:
    result = 0x2000;
end:
    return (short)result;
}
