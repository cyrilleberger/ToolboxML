set(TOOLBOXML_SRCS
  AbstractTool.cpp
  AbstractViewInterface.cpp
  ProxyTool.cpp
  initialise.cpp
  Tool.cpp
  ToolController.cpp
  ToolEvents.cpp
)

add_library(ToolboxML SHARED ${TOOLBOXML_SRCS} )
target_link_libraries(ToolboxML Qt5::Gui Qt5::Quick)

