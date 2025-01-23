project(XYZ-Renderer)
add_executable(XYZ-Renderer 
	lib/glad/src/glad/glad.c 
	src/main.cpp 
)
add_subdirectory(./lib/glfw-3.4)
target_link_libraries(XYZ-Renderer PRIVATE glfw)
add_subdirectory(./lib/glm)
target_link_libraries(XYZ-Renderer PRIVATE glm::glm)
