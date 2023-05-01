QT += widgets
QY += core gui
requires(qtConfig(combobox))

HEADERS       = SpaceCraft.h \
                HoverScene.h \
                Bullet.h \
                Alien.h

SOURCES       = main.cpp \
                SpaceCraft.cpp \
                HoverScene.cpp \
                Bullet.cpp \
                Alien.cpp

RESOURCES     = spaceshooter.qrc

# install
target.path = $$[QT_INSTALL_EXAMPLES]/spaceshooter/
INSTALLS += target
