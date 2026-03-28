namespace InteractorModule {
    struct FloorData {
        int field0;
        int field4;
        int field8;
        int shaderId;
    };
}

struct SomeFloorPtr {
    InteractorModule::FloorData* data;
};

int StaticGetShaderId(SomeFloorPtr* ptr) {
    if (!ptr) {
        return 0xD59C7BB5;
    }
    return ptr->data->shaderId;
}
