struct TrackDataReader {
    void* data;
    int offset;
    TrackDataReader& operator+=(int n);
};

TrackDataReader& TrackDataReader::operator+=(int n) {
    offset += n;
    return *this;
}
