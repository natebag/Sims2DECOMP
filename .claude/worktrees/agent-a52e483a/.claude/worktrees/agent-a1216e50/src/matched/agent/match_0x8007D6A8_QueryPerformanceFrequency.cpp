/* 0x8007D6A8 (24 bytes) - QueryPerformanceFrequency(long long *) */

int QueryPerformanceFrequency(long long *freq) {
    *freq = 0x3F0D;
    return 1;
}
