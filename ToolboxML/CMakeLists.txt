qt5_add_resources(TOOLBOXML_QRC_SRC ToolboxML.qrc)

set(TOOLBOXML_SRCS
  AbstractTool.cpp
  AbstractViewInterface.cpp
  ProxyTool.cpp
  initialise.cpp
  Tool.cpp
  ToolAction.cpp
  ToolController.cpp
  ToolEvents.cpp
  ${TOOLBOXML_QRC_SRC}
)

add_library(ToolboxML SHARED ${TOOLBOXML_SRCS} )
target_link_libraries(ToolboxML Qt5::Gui Qt5::Quick)

install(TARGETS ToolboxML EXPORT ToolboxMLTargets ${INSTALL_TARGETS_DEFAULT_ARGS})

install(FILES AbstractViewInterface.h AbstractTool.h initialise.h DESTINATION ${INSTALL_INCLUDE_DIR}/ToolboxML)
