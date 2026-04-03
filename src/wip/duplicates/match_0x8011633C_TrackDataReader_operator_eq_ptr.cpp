struct ERSoundTrackData;

struct TrackDataReader {
    ERSoundTrackData* data;
    int offset;
    TrackDataReader& operator=(ERSoundTrackData* p);
};

TrackDataReader& TrackDataReader::operator=(ERSoundTrackData* p) {
    data = p;
    offset = 0;
    return *this;
}
