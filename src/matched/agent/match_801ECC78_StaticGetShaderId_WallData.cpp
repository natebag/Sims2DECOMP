namespace InteractorModule {
    struct WallData {
        int shaderId;
    };
}

struct SomeWallPtr {
    InteractorModule::WallData* data;
};

int StaticGetShaderId(SomeWallPtr* ptr) {
    if (!ptr) {
        return 0xD59C7BB5;
    }
    return ptr->data->shaderId;
}
