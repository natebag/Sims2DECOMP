// 0x80189408 HUDTarget::SetJobBarInputRange(int, int, int) (60B)
struct JobBar { short m_min; short m_max; };

struct HUDTarget {
    char pad[134];
    JobBar m_ranges[5];
};

int HUDTarget__SetJobBarInputRange(HUDTarget* self, int idx, int minVal, int maxVal) {
    if ((unsigned int)idx > 4) return 0;
    if (minVal >= maxVal) return 0;
    self->m_ranges[idx].m_min = (short)minVal;
    self->m_ranges[idx].m_max = (short)maxVal;
    return 1;
}
