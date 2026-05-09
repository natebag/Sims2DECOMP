// PRAGMA_STUB: EIFloor::TestCreateFloors(void)
// 0x80047E24 EIFloor::TestCreateFloors (48B)
struct EIFloor;
extern int TestCreateFloors_impl(EIFloor* self);

int EIFloor__TestCreateFloors(EIFloor* self) {
    int result = TestCreateFloors_impl(self);
    int r = 0;
    if (result) r = 1;
    return r;
}
