TEMPLATE = subdirs

SUBDIRS += \
    app \
    morse \
    tests

tests.depends = morse
app.depends = morse

CONFIG += c++17
