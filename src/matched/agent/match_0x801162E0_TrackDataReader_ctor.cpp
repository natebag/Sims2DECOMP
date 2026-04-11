// 0x801162E0 TrackDataReader::TrackDataReader (20b)

struct TrackDataReader {
    int f0;
    int f4;
    TrackDataReader();
};

TrackDataReader::TrackDataReader() {
    TrackDataReader* p = this;
    p->f0 = 0;
    p->f4 = 0;
}
