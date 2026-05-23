/* 0x80069354 (100 bytes) - SAnimator2::getIndexOfPropID(unsigned int) */
struct SAnimator2 {
    char pad[0x168];
    unsigned int** m_propsBegin;
    unsigned int** m_propsEnd;
    int getIndexOfPropID(unsigned int id);
};

int SAnimator2::getIndexOfPropID(unsigned int id) {
    unsigned int** start = m_propsBegin;
    int i = 0;
    unsigned int** p = start;
    int count = (int)((char*)m_propsEnd - (char*)start) >> 2;
    if (i >= count) return -1;
    if (**p == id) return 0;
    i++;
    p++;
    while (i < count) {
        if (**p == id) return i;
        i++;
        p++;
    }
    return -1;
}
