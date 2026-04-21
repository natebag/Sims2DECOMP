// 0x802C5A78 (112 bytes)
// 0x802C5A78 EBoundTreeNode::EBoundTreeNode (112b)

class EBoundTreeNode {
    // vtable ptr at 0x00
    float m_field_04;
    float m_field_08;
    float m_field_0C;
    float m_field_10;
    int m_field_1C;
    int m_field_20;
    int m_field_24;
public:
    EBoundTreeNode();
};

extern int EBoundTreeNode_vtable[];
extern float g_EBoundTreeNode_float_const;

EBoundTreeNode::EBoundTreeNode() {
    // Set vtable
    *(int**)this = EBoundTreeNode_vtable;
    
    // Initialize float fields
    float f = g_EBoundTreeNode_float_const;
    m_field_04 = f;
    m_field_08 = f;
    m_field_0C = f;
    
    // Copy pattern
    m_field_10 = m_field_04;
    
    // Zero out pointer fields
    m_field_1C = 0;
    m_field_20 = 0;
    m_field_24 = 0;
}
