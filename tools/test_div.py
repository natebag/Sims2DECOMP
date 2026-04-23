import ctypes

def emulate_dol(n):
    # mullw (low 32 bits of signed multiply)
    product = ctypes.c_int32(n * 0xCCCCCCCD).value
    # srawi by 2 (signed shift right)
    result = product >> 2
    return result

for n in [20, 40, 60, -20, -40, 100, 0, 19, 21, -19, -21]:
    expected = n // 20
    actual = emulate_dol(n)
    match = "OK" if actual == expected else "MISMATCH"
    print(f"{n:4d} -> {actual:4d} (expected {expected:4d}) {match}")
