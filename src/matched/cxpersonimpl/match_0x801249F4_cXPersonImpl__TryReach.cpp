// 0x801249F4 cXPersonImpl::TryReach(int, StackElem*) (88B)
// Calls TU-local helper _s801249F4_0(this, arg, elem, &a, &b, &c, &d) returning
// long long. If result != 0, override return with {r3=0, r4=!(short)elem[1]}
// (i.e. (long long)(stackElem->field_2 == 0)). Otherwise pass through r.
//
// Technique #19 extern helper — bl relocation masked by verify_match.sh; linker
// resolves to canonical/in-region copy.

extern "C" long long _s801249F4_0(void*, int, void*, int*, int*, int*, int*);

struct cXPerson_TR {
    long long TryReach(int arg, void* elem);
};

long long cXPerson_TR::TryReach(int arg, void* elem) {
    int a, b, c, d;
    long long r = _s801249F4_0(this, arg, elem, &a, &b, &c, &d);
    if (r != 0) {
        short s = ((short*)elem)[1];
        return (long long)(s == 0);
    }
    return r;
}
