// FLAGS: -msdata=eabi -G 8
// 0x800B1B20 CareersImpl::GetCarpoolHour (44b)
struct Career { char data[72]; int hour; };

int CareersImpl_GetCarpoolHour(void* self, Career* career) {
    return (career->hour + 23) % 24;
}
