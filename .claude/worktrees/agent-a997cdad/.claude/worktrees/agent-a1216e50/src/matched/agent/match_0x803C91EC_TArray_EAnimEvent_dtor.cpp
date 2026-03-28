/* TArray_EAnimEvent::~TArray_EAnimEvent() - 0x803C91EC (64 bytes) */

struct TArray_EAnimEvent {
    void Deallocate();
    ~TArray_EAnimEvent();
};

TArray_EAnimEvent::~TArray_EAnimEvent()
{
    Deallocate();
}
