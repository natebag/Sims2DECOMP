// 0x80145354 ObjectSlot::GetHeightMask(StdHeight) (16B)

struct ObjectSlot {
    static int GetHeightMask(int h);
};

int ObjectSlot::GetHeightMask(int h) {
    return 1 << (h - 1);
}
