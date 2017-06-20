
qt5_wrap_cpp(MOC 
    ${PROJECT_INCLUDE_DIR}/QDocumentTabWidget/basedocumenttabitemwidget.h
    ${PROJECT_INCLUDE_DIR}/QDocumentTabWidget/qdocumenttabbarwidget.h
    ${PROJECT_INCLUDE_DIR}/QDocumentTabWidget/qdocumenttabwidget.h
    ${PROJECT_INCLUDE_DIR}/QDocumentTabWidget/qdocumenttabitemwidget.h
)

set(SOURCES
    ${MOC}
    qdocumenttabwidget.cpp
    qdocumenttabbarwidget.cpp
    basedocumenttabitemwidget.cpp
    qdocumenttabitemwidget.cpp
)

add_library(qdocumenttabwidget ${SOURCES})
target_link_libraries(qdocumenttabwidget Qt5::Widgets)