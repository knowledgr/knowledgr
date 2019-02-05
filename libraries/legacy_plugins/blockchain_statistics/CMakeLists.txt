file(GLOB HEADERS "include/knowledgr/blockchain_statistics/*.hpp")

add_library( knowledgr_blockchain_statistics
             blockchain_statistics_plugin.cpp
             blockchain_statistics_api.cpp
           )

target_link_libraries( knowledgr_blockchain_statistics knowledgr_chain knowledgr_protocol knowledgr_app )
target_include_directories( knowledgr_blockchain_statistics
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   knowledgr_blockchain_statistics

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)