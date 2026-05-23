// FLAGS: -fno-elide-constructors
int gPlaceFlag = 0;

void PlaceAtDir(int, void *);

struct PO_SetDirS {
    void *m_object;
    void SetDirection(int dir);
};

void PO_SetDirS::SetDirection(int dir) {
    void *obj = m_object;
    if (obj != 0) {
        gPlaceFlag = 1;
        PlaceAtDir(dir, obj);
        gPlaceFlag = 0;
    }
}
