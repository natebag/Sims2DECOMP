// 0x800477A0 EFloorShdTblNode::RemapFloorAndGrassId (48B)
extern void* gDefaultFloorId;
extern "C" unsigned int remapFloor(unsigned int id);

unsigned int EFloorShdTblNode_RemapFloorAndGrassId(unsigned int id) {
    if (id == 0) {
        return (unsigned int)gDefaultFloorId;
    }
    return remapFloor(id);
}
