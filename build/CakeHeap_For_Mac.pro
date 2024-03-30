#-------------------------------------------------
#
# Project created by QtCreator 2016-09-06T12:32:04
#
#-------------------------------------------------

!include( ../examples.pri ) {
 error( "Couldn't find the examples.pri file!" )
}

QT       += core gui xml network printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 'CakeHeap Budget Professional'
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    budget_frame.cpp \
    inventory_dock.cpp \
    main_budget.cpp \
    reminders_dock.cpp \
    savings_dock.cpp \
    income_statement_dialog.cpp \
    edited_expenses_dialog.cpp \
    main_window.cpp \
    merge_sort_budget.cpp \
    commands.cpp \
    budget_dock.cpp \
    cake_calenderwidget.cpp \
    edited_income_dialog.cpp \
    pieview.cpp \
    add_income_button.cpp \
    cake_message_box.cpp \
    edited_savings_dialog.cpp \
    savings_apr.cpp \
    donate_dialog.cpp \
    reminder_dialog.cpp \
    edited_debt_dialog.cpp \
    savings_dialog.cpp \
    get_money_dialog.cpp \
    expenses_dialog.cpp \
    check_reminders.cpp \
    income_dialog.cpp \
    about_dialog.cpp \
    item_dialog.cpp \
    save_money_dialog.cpp \
    debt_dialog.cpp \
    budget_tab.cpp \
    budget_page.cpp \
    income.cpp \
    priority.cpp \
    debt.cpp \
    deficit.cpp \
    balance.cpp \
    inventory.cpp \
    date.cpp \
    asset.cpp \
    savings_page.cpp \
    fiscal_record.cpp \
    expense.cpp \
    fiscal_year.cpp \
    inventory_page.cpp \
    indicator.cpp \
    liability.cpp \
    menu.cpp \
    savings.cpp \
    reminder.cpp \
    reminders_page.cpp \
    surplus.cpp \
    donutbreakdownchart.cpp \
    mainslice.cpp \
    cakespacerwidget.cpp \
    cakeheapapplication.cpp \
    cake_tool_bar.cpp \
    onboaderdialog.cpp

HEADERS  += mainwindow.h \
    income_statement_dialog.h \
    add_income_button.h \
    main_window.h \
    reminder_dialog.h \
    merge_sort_budget.h \
    budget_dock.h \
    cake_calenderwidget.h \
    edited_income_dialog.h \
    save_money_dialog.h \
    debt_dialog.h \
    check_reminders.h \
    pieview.h \
    savings_apr.h \
    donate_dialog.h \
    cake_message_box.h \
    edited_savings_dialog.h \
    budget_tab.h \
    cake_tab_widget.h \
    edited_debt_dialog.h \
    savings_dialog.h \
    about_dialog.h \
    get_money_dialog.h \
    expenses_dialog.h \
    income_dialog.h \
    inventory_dock.h \
    reminders_dock.h \
    commands.h \
    budget_frame.h \
    item_dialog.h \
    main_budget.h \
    edited_expenses_dialog.h \
    savings_dock.h \
    ui_about_dialog.h \
    ui_budget_tab.h \
    ui_budget_frame.h \
    ui_budget_dock.h \
    ui_inventory_dock.h \
    ui_get_money_dialog.h \
    ui_income_dialog.h \
    ui_save_money_dialog.h \
    ui_savings_dock.h \
    ui_edited_expenses_dialog.h \
    ui_savings_dialog.h \
    ui_edited_income_dialog.h \
    ui_expenses_dialog.h \
    ui_income_statement.h \
    ui_item_dialog.h \
    ui_debt_dialog.h \
    ui_reminder_dialog.h \
    ui_donate_dialog.h \
    ui_reminder_dock.h \
    expense.h \
    reminder.h \
    asset.h \
    debt.h \
    fiscal_year.h \
    income.h \
    surplus.h \
    balance.h \
    savings_page.h \
    budget_page.h \
    date.h \
    fiscal_record.h \
    deficit.h \
    priority.h \
    inventory_page.h \
    indicator.h \
    inventory.h \
    liability.h \
    menu.h \
    reminders_page.h \
    savings.h \
    donutbreakdownchart.h \
    mainslice.h \
    cakespacerwidget.h \
    cakeheapapplication.h \
    cake_tool_bar.h \
    onboaderdialog.h \
    ui_onboaderdialog.h

FORMS    += mainwindow.ui \
    about_dialog.ui \
    budget_dock.ui \
    budget_frame.ui \
    budget_page.ui \
    budget_tab_test.ui \
    budget_tab.ui \
    debt_dialog.ui \
    donate_dialog.ui \
    expenses_dialog.ui \
    get_money.ui \
    income_dialog.ui \
    income_statement_dialog.ui \
    inventory_dock.ui \
    inventory_page.ui \
    item_dialog.ui \
    reminder_dialog.ui \
    reminders_dock.ui \
    reminders_page.ui \
    save_money_dialog.ui \
    savings_dialog.ui \
    savings_dock.ui \
    savings_page.ui \
    onboarder_dialog.ui

unix:INCLUDEPATH += "/Users/thabo/Documents/CakeHeapBudgetForMac/CakeHeap_For_Mac"

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x000000

DISTFILES += \
    CakeHeap_For_Mac.pro.user

RESOURCES += \
    cake_resource.qrc

ICON = cakeheap.icns

QMAKE_CFLAGS += -gdwarf-2
QMAKE_CXXFLAGS += -gdwarf-2
