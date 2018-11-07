file(GLOB HEADERS "include/colab/plugins/auth_util/*.hpp")

add_library( colab_auth_util
             ${HEADERS}
             auth_util_plugin.cpp
             auth_util_api.cpp
           )

target_link_libraries( colab_auth_util colab_app colab_chain colab_protocol fc )
target_include_directories( colab_auth_util
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
