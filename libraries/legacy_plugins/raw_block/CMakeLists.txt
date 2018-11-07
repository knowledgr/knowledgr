file(GLOB HEADERS "include/colab/plugins/raw_block/*.hpp")

add_library( colab_raw_block
             ${HEADERS}
             raw_block_plugin.cpp
             raw_block_api.cpp
           )

target_link_libraries( colab_raw_block colab_app colab_chain colab_protocol fc )
target_include_directories( colab_raw_block
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
