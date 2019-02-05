file(GLOB HEADERS "include/knowledgr/plugins/raw_block/*.hpp")

add_library( knowledgr_raw_block
             ${HEADERS}
             raw_block_plugin.cpp
             raw_block_api.cpp
           )

target_link_libraries( knowledgr_raw_block knowledgr_app knowledgr_chain knowledgr_protocol fc )
target_include_directories( knowledgr_raw_block
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
