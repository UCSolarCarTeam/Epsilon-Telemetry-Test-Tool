#include "TestApplication.h"

TestApplication::TestApplication(int& argc, char** argv)
    : QApplication(argc, argv)
    , data0Container_(new DataContainer())
    , data1Container_(new DataContainer())
    , internetWindow_(new InternetWindow())
    , serialWindow_(new SerialWindow())
    , packetWindow_(new PacketWindow())
    , internetView_(new InternetView(internetWindow_.data()))
    , serialView_(new SerialView(serialWindow_.data()))
    , packetView_(new PacketView(packetWindow_.data()))
    , window_(new Window(QList<QWidget*>
{
    serialWindow_.data(),
                       internetWindow_.data(),
                       packetWindow_.data()
}))
, communicationService_(new CommunicationService(*serialView_, *internetView_))
, serialReporting_(new SerialReporting(*communicationService_,
                                       *data0Container_,
                                       *data1Container_,
                                       *serialView_))
, internetReporting_(new InternetReporting(*communicationService_,
                     *data0Container_,
                     *data1Container_,
                     *internetView_))
, packetReporting_(new PacketReporting(*data0Container_,
                                       *data1Container_,
                                       *packetView_))
{
}

TestApplication::~TestApplication()
{
}

