// 0x802CBCF0 (68B) EMutex::operator--(void)
// MI-vcall slot-3 dispatch (vtable at this+0); 2 filler virtuals + Decrement at slot 3.

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
