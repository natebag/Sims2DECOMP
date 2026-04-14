// 0x803C3B24 TArray<ESMSStrip>::operator= (76B)
extern void F1(void*, int, int);
extern void F2(void*, void*, int);
struct T { void* d; int s; T& operator=(T& r); };
T& T::operator=(T& r) {
    F1(this, r.s, 0);
    F2(d, r.d, r.s);
    return *this;
}
