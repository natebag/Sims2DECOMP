// MATCH: 0x80201338 RELTarget::GetRecord(int) | Size: 36 bytes
// FLAGS: -O2 -g0

struct Record {
    char pad[4];
    Record* next;
};

struct RELTarget {
    char pad[0x84];
    Record* m_records;
    Record* GetRecord(int n);
};

Record* RELTarget::GetRecord(int n) {
    Record* r = m_records;
    int count = n;
    if (count <= 0) return r;
    do {
        if (r) r = r->next;
    } while (--count);
    return r;
}
