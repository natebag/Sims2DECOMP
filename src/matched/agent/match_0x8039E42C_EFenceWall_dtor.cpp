// FLAGS: -fno-elide-constructors
// 0x8039E42C EFenceWall::~EFenceWall (68b)
void fence_delete(void*);

void EFenceWall_dtor(void* self, int mode) {
    parent_dtor(self, 0);
    if (mode & 1) {
        fence_delete(self);
    }
}
