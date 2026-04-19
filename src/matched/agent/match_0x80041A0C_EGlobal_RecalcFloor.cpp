// 0x80041A0C (32B) EGlobal::RecalcFloor(void)
// Thunk to RecalcHouse.

class EGlobal {
public:
    void RecalcFloor(void);
    void RecalcHouse(void);
};

void EGlobal::RecalcFloor(void) {
    RecalcHouse();
}
