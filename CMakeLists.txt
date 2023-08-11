project(i-plugin-manager)

cmake_minimum_required(VERSION 3.10)

include_directories(
    include/
)

install(DIRECTORY include DESTINATION /usr)
