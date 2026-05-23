// 0x802D7ADC (68B) ESemaphore::operator-=(int)
// Same vtable-slot-3-via-2-fillers pattern as the EMutex/ESemaphore twin family.

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
