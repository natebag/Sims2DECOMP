/* sort_records_by_name(void *, void *) at 0x801DA670 (128b) */

typedef unsigned short wchar_t;

extern int wcscmp(const wchar_t *, const wchar_t *);

struct BString2 {
    char pad[4];
    const wchar_t *c_str() const;
};

struct Record {
    char pad_00[0x0C];
    BString2 m_name;
    BString2 m_subname;
};

int sort_records_by_name(void *a, void *b) {
    Record *ra = (Record *)a;
    Record *rb = (Record *)b;
    if (ra == rb) return 0;
    const wchar_t *nameA = ra->m_name.c_str();
    const wchar_t *nameB = rb->m_name.c_str();
    int result = wcscmp(nameA, nameB);
    if (result != 0) return result;
    const wchar_t *subA = ra->m_subname.c_str();
    const wchar_t *subB = rb->m_subname.c_str();
    return wcscmp(subA, subB);
}
