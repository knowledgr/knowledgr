file(GLOB HEADERS "include/knowledgr/private_message/*.hpp")

add_library( knowledgr_private_message
             private_message_plugin.cpp
           )

target_link_libraries( knowledgr_private_message knowledgr_chain knowledgr_protocol knowledgr_app )
target_include_directories( knowledgr_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   knowledgr_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
