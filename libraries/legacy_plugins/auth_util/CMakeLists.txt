file(GLOB HEADERS "include/knowledgr/plugins/auth_util/*.hpp")

add_library( knowledgr_auth_util
             ${HEADERS}
             auth_util_plugin.cpp
             auth_util_api.cpp
           )

target_link_libraries( knowledgr_auth_util knowledgr_app knowledgr_chain knowledgr_protocol fc )
target_include_directories( knowledgr_auth_util
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )
