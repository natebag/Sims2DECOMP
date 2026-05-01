// 0x802CBCF0 (68B) EMutex::operator--(void)
// vtable-slot-3-via-2-fillers dispatch (vtable at this+0); 2 filler virtuals + Decrement at slot 3.

class EMutex {
public:
    virtual void Filler1() = 0;
    virtual void Filler2() = 0;
    virtual void Decrement() = 0;

    EMutex& operator--();
};

EMutex& EMutex::operator--() {
    Decrement();
    return *this;
}
