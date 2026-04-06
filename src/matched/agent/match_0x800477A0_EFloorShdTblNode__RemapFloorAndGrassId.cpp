extern void* gDefaultFloorId;
extern "C" unsigned int remapFloor(unsigned int id);
unsigned int EFloorShdTblNode_RemapFloorAndGrassId(unsigned int id) {
    if (id) {
        return remapFloor(id);
    }
    return (unsigned int)gDefaultFloorId;
}
