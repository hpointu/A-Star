SOURCES += \
    main.cpp \
	 graphics/RenderArea.cpp \
    Application.cpp \
	 graphics/Drawable.cpp \
	 EventManager.cpp \
    Singleton.cpp \
    graphics/Image.cpp \
    model/ModelEntity.cpp \
    model/Cell.cpp \
    model/CellGraph.cpp \
    MapFileReader.cpp \
    graphics/GraphDrawer.cpp \
    graphics/Line.cpp \
    graphics/NodeImage.cpp \
    graphics/EdgeLine.cpp

HEADERS += \
	 graphics/RenderArea.h \
    Application.h \
	 graphics/Drawable.h \
	 EventManager.h \
    EventListener.h \
    graphics/Image.h \
    model/ModelEntity.h \
    model/ModelObserver.h \
    model/Cell.h \
    model/CellGraph.h \
    MapFileReader.h \
    graphics/GraphDrawer.h \
    graphics/Line.h \
    graphics/Graphics.h \
    graphics/NodeImage.h \
    graphics/EdgeLine.h

LIBPATH += /usr/local/lib
LIBS += -lSDL -lSDL_gfx -lSDL_image
