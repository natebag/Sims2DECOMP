namespace InteractorModule {
    struct WallPaperData {
        int field0;
        int field4;
        int shaderId;
    };
}

struct SomeWallPaperPtr {
    InteractorModule::WallPaperData* data;
};

int StaticGetShaderId(SomeWallPaperPtr* ptr) {
    if (!ptr) {
        return 0xD59C7BB5;
    }
    return ptr->data->shaderId;
}
