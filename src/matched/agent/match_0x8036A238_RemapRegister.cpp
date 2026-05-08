// 0x8036A238 RemapRegister(signed char&) (64B)
//
// Remaps ASCII '2' → 11, '7' → 6 in-place. Two early-exits (==11 and <=11)
// emitted as separate beqlr+blelr rather than coalesced into a single ble,
// suggesting the source has two distinct `if` statements.

void RemapRegister(signed char& reg) {
    signed char r = reg;
    if (r == 11) return;
    if (r <= 11) return;
    switch (r) {
        case '2': reg = 11; return;
        case '7': reg = 6; return;
    }
}
