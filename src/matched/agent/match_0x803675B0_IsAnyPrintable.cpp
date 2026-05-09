// IsAnyPrintable(unsigned int) - 0x803675B0 (44B)
// Returns 1 if any of the 4 bytes is > 0x20 (printable-range check), else 0.

int IsAnyPrintable(unsigned int v)
{
    for (int i = 0; i < 4; i++) {
        unsigned int b = v & 0xFF;
        if (b > 32) return 1;
        v >>= 8;
    }
    return 0;
}
