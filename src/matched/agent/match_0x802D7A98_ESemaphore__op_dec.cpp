// 0x802D7A98 (68B) ESemaphore::operator--(void)
// Same MI-vcall slot-3 pattern as EMutex twins.

class ESemaphore {
public:
    virtual void Filler1() = 0;
    virtual void Filler2() = 0;
    virtual void Decrement() = 0;

    ESemaphore& operator--();
};

ESemaphore& ESemaphore::operator--() {
    Decrement();
    return *this;
}
