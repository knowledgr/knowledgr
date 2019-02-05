file(GLOB HEADERS "include/knowledgr/account_statistics/*.hpp")

add_library( knowledgr_account_statistics
             account_statistics_plugin.cpp
             account_statistics_api.cpp
           )

target_link_libraries( knowledgr_account_statistics knowledgr_chain knowledgr_protocol knowledgr_app )
target_include_directories( knowledgr_account_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   knowledgr_account_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)