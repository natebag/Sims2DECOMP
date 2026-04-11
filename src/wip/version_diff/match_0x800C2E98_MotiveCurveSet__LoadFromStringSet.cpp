struct PiecewiseFn {
    void Reset(void);
    void AddPointsFromText(char *);
};

struct MotiveCurveSet {
    char *m_data;
    int m_count;
    void LoadFromStringSet(char **, int);
};

void MotiveCurveSet::LoadFromStringSet(char **strings, int count) {
    if (count <= 0) return;
    char **p = strings;
    int n = count;
    int offset = 0;
    do {
        PiecewiseFn *entry = (PiecewiseFn *)(m_data + offset);
        entry->Reset();
        char *str = *p;
        p++;
        if (str != 0) {
            entry->AddPointsFromText(str);
        }
        offset += 20;
    } while (--n != 0);
}
