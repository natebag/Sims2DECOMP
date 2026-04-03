// ObjSelector::ObjSelector(void) (196 bytes)
// Constructor - initialize all member variables to defaults

class ObjectDataObjDefinition;

class ObjSelector {
    int m_field0;           // offset 0
    int m_field4;           // offset 4 (init to -1)
    int m_field8;           // offset 8 (init to -1)
    int m_field12;          // offset 12
    // ... many more fields initialized to 0 or -1

public:
    ObjSelector() {
        // Initialize base object definition
        ObjectDataObjDefinition::ObjectDataObjDefinition();  // at offset 28

        // Initialize all fields to 0 or -1
        *(int *)((char *)this + 0) = 0;
        *(int *)((char *)this + 4) = -1;
        *(int *)((char *)this + 8) = -1;
        *(int *)((char *)this + 12) = 0;
        *(int *)((char *)this + 16) = 0;
        // ... many stw r0, offset(r30) or stw r29, offset(r30)
        // ... approximately 40 fields initialized
        *(int *)((char *)this + 60) = 0;
        *(int *)((char *)this + 80) = 0;
        *(int *)((char *)this + 84) = 0;
        *(int *)((char *)this + 88) = 0;
        *(int *)((char *)this + 96) = 0;
        *(int *)((char *)this + 100) = 0;
        *(int *)((char *)this + 104) = 0;
        *(short *)((char *)this + 108) = 0;
        *(int *)((char *)this + 112) = -1;
        *(int *)((char *)this + 116) = -1;
        *(int *)((char *)this + 120) = -1;
        *(int *)((char *)this + 124) = 0xFFFFFFFF;
        // ... and many more fields
    }
};
