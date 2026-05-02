// 0x80218FAC (96B) InteractorModule::ObjectManipulator::~ObjectManipulator(void)
// Variant L (MI): vtable-transition at +0x5c + PlacementObject member dtor at +0x64.

extern char vt_ObjectManipulator_a[];
extern char vt_ObjectManipulator_b[];

void PlacementObject_dtor(void* obj, int flag);
void __builtin_delete(void* p);

struct PlacementObject {
    char data[1];
};

struct ObjectManipulator {
    char pad_00_5b[92];
    void* m_vt_at_5c;
    char pad_60_63[4];
    PlacementObject m_placement;
    void dtor(int flag);
};

void ObjectManipulator::dtor(int flag) {
    m_vt_at_5c = vt_ObjectManipulator_a;
    PlacementObject_dtor(&m_placement, 2);
    m_vt_at_5c = vt_ObjectManipulator_b;
    if (flag & 1) {
        __builtin_delete(this);
    }
}
