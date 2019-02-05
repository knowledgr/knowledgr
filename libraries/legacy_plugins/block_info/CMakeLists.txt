file(GLOB HEADERS "include/knowledgr/plugins/block_info/*.hpp")

add_library( knowledgr_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( knowledgr_block_info knowledgr_app knowledgr_chain knowledgr_protocol fc )
target_include_directories( knowledgr_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
