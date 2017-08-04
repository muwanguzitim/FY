#-------------------------------------------------
#
# Project created by QtCreator 2017-06-29T13:16:57
#
#-------------------------------------------------

QT       += core gui sql
QT       += network


greaterThan(QT_MAJOR_VERSION, 4):
QT +=printsupport
QT += widgets



TARGET = hms
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    receiptionist.cpp \
    doctor.cpp \
    laboratory.cpp \
    pharmacy.cpp \
    cashier.cpp \
    invoice.cpp \
    appointments.cpp \
    triage.cpp \
    searchpatient.cpp \
    admin.cpp \
    gs_admin.cpp \
    viewusers_admin.cpp \
    prescription_admin.cpp \
    medicine_admin.cpp \
    readyresults.cpp \
    admin_login.cpp \
    users_admin.cpp \
    addprescription_admin.cpp \
    schedule.cpp \
    navigation_receptionist.cpp \
    navigation_doctor.cpp \
    navigation_nurse.cpp \
    navigation_pharmacy.cpp \
    navigation_laboratory.cpp \
    navigation_cashier.cpp \
    appointment_receptionist.cpp \
    waitinglist.cpp \
    pharmacy_newstock.cpp \
    report.cpp \
    ../qcustomplot/qcustomplot.cpp


HEADERS  += mainwindow.h \
    dialog.h \
    receiptionist.h \
    doctor.h \
    laboratory.h \
    pharmacy.h \
    cashier.h \
    invoice.h \
    appointments.h \
    triage.h \
    searchpatient.h \
    admin.h \
    gs_admin.h \
    viewusers_admin.h \
    prescription_admin.h \
    medicine_admin.h \
    readyresults.h \
    admin_login.h \
    users_admin.h \
    addprescription_admin.h \
    schedule.h \
    navigation_receptionist.h \
    navigation_doctor.h \
    navigation_nurse.h \
    navigation_pharmacy.h \
    navigation_laboratory.h \
    navigation_cashier.h \
    appointment_receptionist.h \
    waitinglist.h \
    pharmacy_newstock.h \
    report.h \
    cppconn/build_config.h \
    cppconn/config.h \
    cppconn/connection.h \
    cppconn/datatype.h \
    cppconn/driver.h \
    cppconn/exception.h \
    cppconn/metadata.h \
    cppconn/parameter_metadata.h \
    cppconn/prepared_statement.h \
    cppconn/resultset.h \
    cppconn/resultset_metadata.h \
    cppconn/sqlstring.h \
    cppconn/statement.h \
    cppconn/variant.h \
    cppconn/version_info.h \
    cppconn/warning.h \
    mysql_connection.h \
    mysql_driver.h \
    mysql_error.h \
    ../qcustomplot/qcustomplot.h

FORMS    += mainwindow.ui \
    dialog.ui \
    receiptionist.ui \
    doctor.ui \
    laboratory.ui \
    pharmacy.ui \
    cashier.ui \
    invoice.ui \
    appointments.ui \
    triage.ui \
    searchpatient.ui \
    admin.ui \
    gs_admin.ui \
    viewusers_admin.ui \
    prescription_admin.ui \
    medicine_admin.ui \
    readyresults.ui \
    admin_login.ui \
    users_admin.ui \
    addprescription_admin.ui \
    schedule.ui \
    navigation_receptionist.ui \
    navigation_doctor.ui \
    navigation_nurse.ui \
    navigation_pharmacy.ui \
    navigation_laboratory.ui \
    navigation_cashier.ui \
    appointment_receptionist.ui \
    waitinglist.ui \
    pharmacy_newstock.ui \
    report.ui

DISTFILES += \
    Images/hms.png \
    Images/hms2.png \
    Images/hms3.png


