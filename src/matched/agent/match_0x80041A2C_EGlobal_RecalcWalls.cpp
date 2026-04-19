// 0x80041A2C (32B) EGlobal::RecalcWalls(void)
// Thunk to RecalcHouse.

class EGlobal {
public:
    void RecalcWalls(void);
    void RecalcHouse(void);
};

void EGlobal::RecalcWalls(void) {
    RecalcHouse();
}
