struct EIFloor;
extern int TestCreateFloors_impl(EIFloor* self);

int EIFloor__TestCreateFloors(EIFloor* self) {
    int result = TestCreateFloors_impl(self);
    if (result) return 1;
    return 0;
}
