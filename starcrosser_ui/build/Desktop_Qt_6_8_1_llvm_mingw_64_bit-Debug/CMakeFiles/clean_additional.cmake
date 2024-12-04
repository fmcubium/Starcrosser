# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\starcrosser_ui_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\starcrosser_ui_autogen.dir\\ParseCache.txt"
  "starcrosser_ui_autogen"
  )
endif()
