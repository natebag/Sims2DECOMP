// 0x802CBCAC (68B) EMutex::operator-=(int)
// Twin of operator-- — same vtable-slot-3-via-2-fillers dispatch (arg ignored).

class EMutex {
public:
    virtual void Filler1() = 0;
    virtual void Filler2() = 0;
    virtual void Decrement() = 0;

    EMutex& operator-=(int);
};

EMutex& EMutex::operator-=(int) {
    Decrement();
    return *this;
}
