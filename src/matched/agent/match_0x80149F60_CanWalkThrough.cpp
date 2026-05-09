// CanWalkThrough(WallStyle) @ 0x80149F60 (56B)
// FLAGS: -fno-schedule-insns
// Returns 1 if WallStyle is one of {3,5,6,15,23}, 0 otherwise.
// DOL: 5 sequential cmpwi, 4 beq to shared return-1, 1 bne to return-0.

int CanWalkThrough(int wallStyle) {
    if (wallStyle == 3 || wallStyle == 5 || wallStyle == 6 || wallStyle == 15 || wallStyle == 23)
        return 1;
    return 0;
}
