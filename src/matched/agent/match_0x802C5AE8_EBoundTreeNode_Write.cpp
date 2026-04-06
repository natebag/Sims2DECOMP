// 0x802C5AE8 EBoundTreeNode::Write (76b)
// FLAGS: -fno-schedule-insns

extern void WriteField_4(int*, int*);
extern void WriteValue(int, int, int);

struct EBoundTreeNode {
    int field_0x0;
    int field_0x4;
    int field_0x8;
    int field_0xc;
    int field_0x10;
    int field_0x14;
    int field_0x18;
    int field_0x1c;
    int field_0x20;
    int field_0x24;
    
    void Write(int* stream);
};

void EBoundTreeNode::Write(int* stream) {
    // Pack values to force register usage
    int v1 = field_0x1c;
    int v2 = field_0x20;
    int v3 = field_0x24;
    WriteField_4(stream, &field_0x4);
    WriteValue(v1, v2, v3);
}
