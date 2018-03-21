#pragma once

struct LightsData
{
    LightsData()
        : alive(true)
        , lowBeams(true)
        , highBeams(false)
        , brakes(true)
        , leftSignal(false)
        , rightSignal(true)
        , bmsStrobeLight(false)
    {}

    bool alive;
    bool lowBeams;
    bool highBeams;
    bool brakes;
    bool leftSignal;
    bool rightSignal;
    bool bmsStrobeLight;
};

//#pragma once

//#include <QObject>

//class LightsData : public QObject
//{
//    Q_OBJECT

//public:
//    LightsData();
//    virtual ~LightsData();

//    bool alive() const;
//    bool lowBeams() const;
//    bool highBeams() const;
//    bool brakes() const;
//    bool leftSignal() const;
//    bool rightSignal() const;
//    bool bmsStrobeLight() const;

//    void setAlive(const bool& alive);
//    void setLowBeams(const bool& lowBeams);
//    void setHighBeams(const bool& highBeams);
//    void setBrakes(const bool& brakes);
//    void setLeftSignal(const bool& leftSignal);
//    void setRightSignal(const bool& rightSignal);
//    void setBmsStrobeLight(const bool& bmsStrobeLight);

//private:
//    bool alive_;
//    bool lowBeams_;
//    bool highBeams_;
//    bool brakes_;
//    bool leftSignal_;
//    bool rightSignal_;
//    bool bmsStrobeLight_;
//};


