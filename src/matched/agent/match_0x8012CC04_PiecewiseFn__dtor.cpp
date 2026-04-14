// 0x8012CC04 PiecewiseFn::~PiecewiseFn (68B)

struct PiecewiseFn {
    char pad[0x3C];
    int m_field3C;
    ~PiecewiseFn();
};

extern "C" void ERoomWall_dtor(void* self, int flag);
extern "C" void ERoomWall_op_delete(void* self);

void PiecewiseFn_dtor(PiecewiseFn* self, int flag) {
    ERoomWall_dtor(self, 0);
    if (flag & 1) {
        ERoomWall_op_delete(self);
    }
}
