// 0x800B1AB0 (56B) CareersImpl::GetJobName(Job&, bool)

struct Foo { unsigned short x; };

struct Job {
    char pad0[88];
    char def[4];       // offset 88
    Foo** alt_ptr;     // offset 92
};

class CareersImpl {
public:
    char* GetJobName(Job& job, bool useAlt);
};

char* CareersImpl::GetJobName(Job& job, bool useAlt) {
    if (useAlt) {
        Foo** pp = job.alt_ptr;
        Foo* p = 0;
        if (pp) p = *pp;
        if (p->x != 0) goto alt_path;
    }
    return job.def;
alt_path:
    return (char*)&job.alt_ptr;
}
