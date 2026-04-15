/* SpacePartition::IsSpatialNode(int) - 0x80138F1C (20 bytes) */
class SpacePartition {
public:
    int IsSpatialNode(int x);
};
int SpacePartition::IsSpatialNode(int x) {
    return (unsigned)(x + 1) > 2;
}
