#include <iostream>
using namespace std;

class MediaFile {
protected:
    string filePath;
    double size;
public:
    MediaFile(string path, double sz) : filePath(path), size(sz) {}
    virtual void play() const { cout << "Playing media from: " << filePath << endl; }
    virtual void stop() const { cout << "Stopping media: " << filePath << endl; }
    virtual ~MediaFile() {}
};

class VisualMedia : virtual public MediaFile {
protected:
    int resolution;
public:
    VisualMedia(string path, double sz, int res) : MediaFile(path, sz), resolution(res) {}
};

class AudioMedia : virtual public MediaFile {
protected:
    int sampleRate;
public:
    AudioMedia(string path, double sz, int rate) : MediaFile(path, sz), sampleRate(rate) {}
};

class VideoFile : public VisualMedia, public AudioMedia {
public:
    VideoFile(string path, double sz, int res, int rate) : MediaFile(path, sz), VisualMedia(path, sz, res), AudioMedia(path, sz, rate) {}
    void play() const override {
        cout << "Playing video file: " << filePath << " | Resolution: " << resolution << "p | Sample Rate: " << sampleRate << " Hz" << endl;
    }
};

class ImageFile : public VisualMedia {
public:
    ImageFile(string path, double sz, int res) : MediaFile(path, sz), VisualMedia(path, sz, res) {}
    void play() const override {
        cout << "Displaying image file: " << filePath << " | Resolution: " << resolution << "p" << endl;
    }
};

class AudioFile : public AudioMedia {
public:
    AudioFile(string path, double sz, int rate) : MediaFile(path, sz), AudioMedia(path, sz, rate) {}
    void play() const override {
        cout << "Playing audio file: " << filePath << " | Sample Rate: " << sampleRate << " Hz" << endl;
    }
};

int main() {
    MediaFile* media1 = new VideoFile("video.mp4", 500.0, 1080, 44100);
    MediaFile* media2 = new ImageFile("image.jpg", 5.5, 720);
    MediaFile* media3 = new AudioFile("song.mp3", 3.2, 44100);   
    media1->play();
    media2->play();
    media3->play();   
    delete media1;
    delete media2;
    delete media3;    
    return 0;
}

