file(GLOB HEADERS "include/knowledgr/schema/*.hpp")
add_library( knowledgr_schema schema.cpp ${HEADERS} )
target_link_libraries( knowledgr_schema fc )
target_include_directories( knowledgr_schema PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   knowledgr_schema

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
install( FILES ${HEADERS} DESTINATION "include/knowledgr/schema" )
