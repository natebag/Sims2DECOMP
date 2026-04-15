// 0x8021C344 InteractorModule::PlacementObject::ResetDirection(void) (64B)

static int g_resetDirectionFlag;

struct cXObject;

void SetDirection(int, cXObject*);

struct PlacementObject {
    cXObject* m_object;
    char pad[12];
    short m_direction;
    void ResetDirection();
};

void PlacementObject::ResetDirection() {
    cXObject* obj = m_object;
    if (obj != 0) {
        int dir = m_direction;
        g_resetDirectionFlag = 1;
        SetDirection(dir, obj);
        g_resetDirectionFlag = 0;
    }
}
