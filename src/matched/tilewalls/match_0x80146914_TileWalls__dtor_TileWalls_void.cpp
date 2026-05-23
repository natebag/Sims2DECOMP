void del_TileWalls__dtor_TileWalls_void(void*);
void TileWalls__dtor_TileWalls_void(void* self, int c) { if (c & 1) del_TileWalls__dtor_TileWalls_void(self); }
