add_library(
    libraries
    "${CMAKE_CURRENT_SOURCE_DIR}/nodes/node.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/nodes/node.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/file_operations/read_nodes.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/file_operations/read_nodes.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/bfs/bfs.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/bfs/bfs.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/dfs/dfs.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/dfs/dfs.cpp"
)

target_include_directories(libraries PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
