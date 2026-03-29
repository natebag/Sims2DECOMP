unsigned int GetNextRandomNumber(void);

unsigned int RangedRandInt(unsigned int range) {
    return GetNextRandomNumber() % range;
}
