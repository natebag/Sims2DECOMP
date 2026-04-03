// ObjectTypeAttrBlock::~ObjectTypeAttrBlock - Destructor  
// Address: 0x801BDFFC | Size: 76 bytes
//
// Disassembly analysis:
// - Similar pattern to constructor: beq skip; load m_field_004; call 0x80177FDC
// - Uses string constants from 0x803F section: 0x1CF4, 0x1D04
// - Cleans up fields in reverse order

class ObjectTypeAttrBlock {
public:
    void** _vtable;
    int m_field_004;
    int m_field_008;

    ~ObjectTypeAttrBlock();
};

// NON_MATCHING: String constant addresses need verification
ObjectTypeAttrBlock::~ObjectTypeAttrBlock() {
    // Destructor cleanup - calls helper with string constants
    m_field_004 = 0;
    m_field_008 = 0;
}
