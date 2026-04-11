// 0x8039E42C EFenceWall::~EFenceWall (68b)

struct EFenceWall {
    char pad[0x3C];
    int m_field3C;
    
    ~EFenceWall();
};

extern "C" void ERoomWall_dtor(void* self, int flag);
extern "C" void ERoomWall_op_delete(void* self);

// Deleting destructor - takes flag in r4
void EFenceWall_dtor(EFenceWall* self, int flag) {
    ERoomWall_dtor(self, 0);
    if (flag & 1) {
        ERoomWall_op_delete(self);
    }
}
