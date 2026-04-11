// 0x8015BAF4 ObjectDataID::ObjectDataID(unsigned int, unsigned short) (16b)

typedef unsigned int uint;

struct ObjectDataID {
    uint f0;
    unsigned short f4;
    ObjectDataID(uint p2, unsigned short p3);
};

ObjectDataID::ObjectDataID(uint p2, unsigned short p3) {
    f0 = p2;
    f4 = p3;
}
