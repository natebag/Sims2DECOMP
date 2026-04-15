// 0x800B1AE8 (56B) CareersImpl::GetShortName(Job&, bool)

struct Foo { unsigned short x; };

struct Job {
    char pad0[96];
    char def_short[4];  // offset 96
    Foo** alt_short_ptr;  // offset 100
};

class CareersImpl {
public:
    char* GetShortName(Job& job, bool useAlt);
};

char* CareersImpl::GetShortName(Job& job, bool useAlt) {
    if (useAlt) {
        Foo** pp = job.alt_short_ptr;
        Foo* p = 0;
        if (pp) p = *pp;
        if (p->x != 0) goto alt_path;
    }
    return job.def_short;
alt_path:
    return (char*)&job.alt_short_ptr;
}
