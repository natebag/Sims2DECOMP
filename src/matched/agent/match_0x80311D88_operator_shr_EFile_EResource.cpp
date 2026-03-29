struct EFile;
struct EStorable;
struct EResource;
extern EFile& operator>>(EFile&, EStorable*&);
EFile& operator>>(EFile& f, EResource*& r) {
    EStorable* tmp;
    operator>>(f, tmp);
    r = (EResource*)tmp;
    return f;
}
