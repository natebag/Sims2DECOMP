// 0x80138F1C SpacePartition::IsSpatialNode(int) (20B)

struct SpacePartition {
    int IsSpatialNode(int nodeType);
};

int SpacePartition::IsSpatialNode(int nodeType) {
    return (unsigned)(nodeType + 1) > 2;
}
