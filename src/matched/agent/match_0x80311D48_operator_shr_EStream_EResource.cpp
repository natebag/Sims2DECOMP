struct EStream;
struct EStorable;
struct EResource;
extern EStream& operator>>(EStream&, EStorable*&);
EStream& operator>>(EStream& s, EResource*& r) {
    EStorable* tmp;
    operator>>(s, tmp);
    r = (EResource*)tmp;
    return s;
}
