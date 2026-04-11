// ESim::VisibilityTest(E3DWindow &) - 0x800341E8 (228 bytes)
// FLAGS: -fno-elide-constructors

class E3DWindow;
class EBoundSphere;
class EBound3;
class EAnimController;
class EMat4;

// ESim base with virtual method at entry 34
class ESimBase {
public:
    // Virtual methods 0-33 (placeholders)
    virtual void V0(); virtual void V1(); virtual void V2(); virtual void V3();
    virtual void V4(); virtual void V5(); virtual void V6(); virtual void V7();
    virtual void V8(); virtual void V9(); virtual void V10(); virtual void V11();
    virtual void V12(); virtual void V13(); virtual void V14(); virtual void V15();
    virtual void V16(); virtual void V17(); virtual void V18(); virtual void V19();
    virtual void V20(); virtual void V21(); virtual void V22(); virtual void V23();
    virtual void V24(); virtual void V25(); virtual void V26(); virtual void V27();
    virtual void V28(); virtual void V29(); virtual void V30(); virtual void V31();
    virtual void V32(); virtual void V33();
    // Entry 34 - called in VisibilityTest
    virtual void* GetAnimControllerPtr();
};

class ESim : public ESimBase {
public:
    char pad[256];           // 0-255
    EBoundSphere* m_bounds;  // 256
    char pad2[564];          // 260-819
    EAnimController m_animCtrl; // 820
    // ... more fields
    int m_field1592;         // 1592
    
    int HasQueuedOperation(void);
    int VisibilityTest(E3DWindow& window);
};

class E3DWindow {
public:
    int Test(EBoundSphere& sphere);
    int Test(EBound3& box);
};

class EBoundSphere {};
class EBound3 {};
class EAnimController {
public:
    void CalcTightBoundBox(EMat4& mat, EBound3& box, bool* flag);
    int m_field16;  // 16
};
class EMat4 {};

// SDA constants
extern float g_one;  // 4600 (0x11f8) from -32707 base

int ESim::VisibilityTest(E3DWindow& window) {
    // If has queued operation, not visible
    if (HasQueuedOperation()) {
        return 0;
    }
    
    // Check anim controller valid
    if (m_animCtrl.m_field16 == 0) {
        // Use simple bounds test
        return window.Test(*m_bounds);
    }
    
    // Complex path: get anim controller via virtual call
    void* animCtrl = GetAnimControllerPtr();
    
    // Calculate tight bounding box
    EMat4 mat;
    EBound3 box;
    bool flag = false;
    m_animCtrl.CalcTightBoundBox(mat, box, &flag);
    
    // Test against window
    return window.Test(box);
}
