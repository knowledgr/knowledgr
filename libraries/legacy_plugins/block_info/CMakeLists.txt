file(GLOB HEADERS "include/colab/plugins/block_info/*.hpp")

add_library( colab_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( colab_block_info colab_app colab_chain colab_protocol fc )
target_include_directories( colab_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
