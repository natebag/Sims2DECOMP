struct TrackDataReader {
    void* data;
    int offset;
    TrackDataReader& operator--();
};

TrackDataReader& TrackDataReader::operator--() {
    offset--;
    return *this;
}
