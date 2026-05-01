// 0x802D7ADC (68B) ESemaphore::operator-=(int)
// Same MI-vcall slot-3 pattern as the EMutex/ESemaphore twin family.

class ESemaphore {
public:
    virtual void Filler1() = 0;
    virtual void Filler2() = 0;
    virtual void Decrement() = 0;

    ESemaphore& operator-=(int);
};

ESemaphore& ESemaphore::operator-=(int) {
    Decrement();
    return *this;
}
