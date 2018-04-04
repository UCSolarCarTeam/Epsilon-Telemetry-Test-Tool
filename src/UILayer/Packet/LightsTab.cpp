#include "LightsTab.h"
#include "ui_LightsTab.h"

LightsTab::LightsTab()
    : ui_(new Ui::LightsTab)
{
    ui_->setupUi(this);
}

LightsTab::~LightsTab()
{
    delete ui_;
}

QCheckBox& LightsTab::bmsStrobeLight()
{
    return *ui_->bmsStrobeLight;
}

QCheckBox& LightsTab::brakeLights()
{
    return *ui_->brakeLights;
}

QCheckBox& LightsTab::highBeams()
{
    return *ui_->highBeams;
}

QCheckBox& LightsTab::leftSignal()
{
    return *ui_->leftSignal;
}

QCheckBox& LightsTab::alive()
{
    return *ui_->alive;
}

QCheckBox& LightsTab::lowBeams()
{
    return *ui_->lowBeams;
}

QCheckBox& LightsTab::rightSignal()
{
    return *ui_->rightSignal;
}
