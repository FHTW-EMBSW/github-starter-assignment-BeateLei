#add_library(greet src/greeting.cpp)
#target_include_directories(greet PUBLIC include)

add_executable(greet  
src/main.cpp 
src/greeting.cpp 
)

#target_link_libraries(greet_test greet)

#catch_discover_tests(greet_test)

target_include_directories(greet PUBLIC include)
