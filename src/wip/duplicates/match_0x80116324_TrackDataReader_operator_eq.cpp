struct TrackDataReader {
    void* data;
    int offset;
    TrackDataReader& operator=(TrackDataReader& other);
};

TrackDataReader& TrackDataReader::operator=(TrackDataReader& other) {
    data = other.data;
    offset = other.offset;
    return *this;
}
