# ------------------------------------------------------------------- #
# This file contains all references to the core functionality which   #
# is shared by the actual application and its test cases.             #
# An alternative solution would be the use of static libraries. To    #
# make sense this would require more changes to the file hierarchy    #
# which is overkill for this scenario.                                #
# ------------------------------------------------------------------- #

include(DataLayer/DataLayer.pri)
include(Peripherals/Peripherals.pri)
include(BusinessLayer/BusinessLayer.pri)
include(UILayer/UILayer.pri)
include(ViewLayer/ViewLayer.pri)
