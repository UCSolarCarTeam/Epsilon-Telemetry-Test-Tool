#pragma once
#include <QObject>

class DriverControlsData : public QObject
{
    Q_OBJECT

public:
    DriverControlsData();
    virtual ~DriverControlsData();

    bool alive() const;
    bool headlightsOff() const;
    bool headlightsLow() const;
    bool headlightsHigh() const;
    bool signalLeft() const;
    bool signalRight() const;
    bool hazardLights() const;
    bool interiorLights() const;
    bool volumeUp() const;
    bool volumeDown() const;
    bool nextSong() const;
    bool prevSong() const;
    bool brakes() const;
    bool forward() const;
    bool reverse() const;
    bool pushToTalk() const;
    bool horn() const;
    bool reset() const;
    bool aux() const;
    unsigned short acceleration() const;
    unsigned short regenBraking() const;

    void setAlive(const bool& alive);
    void setHeadlightsOff(const bool& headlightsOff);
    void setHeadlightsLow(const bool& headlightsLow);
    void setHeadlightsHigh(const bool& headlightsHigh);
    void setSignalLeft(const bool& signalLeft);
    void setSignalRight(const bool& signalRight);
    void setHazardLights(const bool& hazardLights);
    void setInteriorLights(const bool& interiorLights);
    void setVolumeUp(const bool& volumeUp);
    void setVolumeDown(const bool& volumeDown);
    void setNextSong(const bool& nextSong);
    void setPrevSong(const bool& prevSong);
    void setBrakes(const bool& brakes);
    void setForward(const bool& forward);
    void setReverse(const bool& reverse);
    void setPushToTalk(const bool& pushToTalk);
    void setHorn(const bool& horn);
    void setReset(const bool& reset);
    void setAux(const bool& aux);
    void setAcceleration(const unsigned short& acceleration);
    void setRegenBraking(const unsigned short& regenBraking);

private:
    bool alive_;
    bool headlightsOff_;
    bool headlightsLow_;
    bool headlightsHigh_;
    bool signalLeft_;
    bool signalRight_;
    bool hazardLights_;
    bool interiorLights_;
    bool volumeUp_;
    bool volumeDown_;
    bool nextSong_;
    bool prevSong_;
    bool brakes_;
    bool forward_;
    bool reverse_;
    bool pushToTalk_;
    bool horn_;
    bool reset_;
    bool aux_;
    unsigned short acceleration_;
    unsigned short regenBraking_;
};
